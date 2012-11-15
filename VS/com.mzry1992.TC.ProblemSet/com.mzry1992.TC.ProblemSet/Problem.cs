using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using com.mzry1992.Settings;
using com.mzry1992.HTML;
using System.Collections;
using System.Net;

namespace com.mzry1992.TC.ProblemSet
{
    public class Problem
    {
        public String Name;
        public String ID;
        public Solution Solutions;
        public String ProblemPath;

        private String Path;
        private String ContestID;
        private String DivName;

        public Problem(String _ContestID, String _DivName, String _Name)
        {
            Name = _Name;
            ContestID = _ContestID;
            DivName = _DivName;
            Path = "ProblemSet/" + _ContestID + "/" + _DivName + "/" + _Name;
            ProblemPath = Path + "/Problem.doc";
            Load();
        }

        public void SetID(string ID)
        {
            INIFILE inifile = new INIFILE(Path, "info.ini");
            inifile.WriteString("problem", "id", ID);
            LoadInfo();
        }

        private void LoadInfo()
        {
            INIFILE inifile = new INIFILE(Path, "info.ini");
            ID = inifile.GetString("problem", "id", "null");
        }

        private void Load()
        {
            if (Directory.Exists(Path) == false)
                Directory.CreateDirectory(Path);

            FileStream fs;
            if (File.Exists(ProblemPath) == false)
            {
                fs = File.Create(ProblemPath);
                fs.Close();
            }
            Solutions = new Solution(ContestID, DivName, Name);

            LoadInfo();
        }

        private string GetURL()
        {
            return string.Format("http://community.topcoder.com/stat?c=problem_statement&pm={0}&rd={1}", ID, ContestID);
        }

        public void GetImage()
        {
            string doc = File.ReadAllText(ProblemPath);
            string pre1 = "http://www.topcoder.com/";
            string pre2 = "http://community.topcoder.com/";
            string newdoc = "";
            bool first = true;
            for (int i = 0; i < doc.Length; i++)
            {
                if (doc.Substring(i).StartsWith(pre1) || doc.Substring(i).StartsWith(pre2))
                {
                    string photoURL = "";
                    for (int j = i; j < doc.Length; j++)
                    {
                        if (doc[j] == '"')
                        {
                            string photoName = "";
                            for (int k = photoURL.Length - 1; k >= 0; k--)
                                if (photoURL[k] == '/')
                                {
                                    photoName = photoURL.Substring(k + 1);
                                    break;
                                }
                            if (first == true)
                            {
                                if (Directory.Exists(Path + "/Image") == false)
                                    Directory.CreateDirectory(Path + "/Image");
                                first = false;
                            }
                            GetSource.SavePhoto(Path + "/Image/" + photoName, photoURL);
                            //Console.WriteLine(photoURL + " : " + photoName);
                            newdoc = newdoc + "Image/" + photoName;
                            i = j-1;
                            break;
                        }
                        photoURL = photoURL + doc[j];
                    }
                }
                else
                    newdoc = newdoc + doc[i];
            }

            File.WriteAllText(ProblemPath, newdoc);
        }

        public void Updata()
        {
            LoadInfo();
            if (ID == "null") return;

            CookieCollection cookie = new CookieCollection();
            cookie.Add(new Cookie("main_user_id_1", "22768107|4d3c9fd95d28de4ac224108a2d79bd5d", "/", ".topcoder.com"));
            HTML.HTML html = new HTML.HTML(GetURL(),cookie);
            List<Hashtable> info = html.GetDFSDocument();

            for (int i = 0; i < info.Count; i++)
            {
                string tmp = (string)info[i]["Value"];
                if (tmp.Contains("Problem Statement for") == true)
                {
                    tmp = (string)info[i - 9]["Value"];
                    if (tmp == "table")
                    {
                        tmp = (string)info[i - 9]["Source"];
                        string findstr = "Problem Statement for ";
                        string replacestr = string.Format("<center><h1>{0}</h1></center>", Name);
                        for (int j = 0; j < tmp.Length && j+findstr.Length < tmp.Length; j++)
                            if (tmp.Substring(j, findstr.Length) == findstr)
                            {
                                for (int k = j+findstr.Length;k < tmp.Length;k++)
                                    if (tmp[k] == '<')
                                    {
                                        tmp = tmp.Substring(0, j) + replacestr + tmp.Substring(k);
                                        break;
                                    }
                                break;
                            }
                        File.WriteAllText(ProblemPath, tmp);
                        GetImage();
                    }
                    break;
                }
            }

            Load();
        }

    }
}
