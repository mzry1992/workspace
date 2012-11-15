using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;
using com.mzry1992.Settings;
using System.Collections;

namespace com.mzry1992.TC.ProblemSet
{
    public class Contest
    {
        public String Name;
        public String ID;
        public int iID;
        public List<Div> DivList = new List<Div>();
        public bool UpdataComplete = false;

        private String Path;

        public Contest(String _ContestID)
        {
            ID = _ContestID;
            iID = int.Parse(ID);
            Path = "ProblemSet/" + ID;
            Load();
        }

        private String GetRoundURL()
        {
            return string.Format("http://community.topcoder.com/stat?c=round_overview&er=5&rd={0}", ID);
        }

        private bool checkURL(string URL)
        {
            for (int er = 0; er <= 10; er++)
            {
                string tmp = string.Format("\"/stat?c=round_overview&er={0}&rd={1}\"",er, ID);
                if (tmp == URL) return true;
            }
            return false;
        }

        private void LoadInfo()
        {
            INIFILE info = new INIFILE(Path, "info.ini");
            Name = info.GetString("contest", "name", "null");
        }

        public void Load()
        {
            foreach (String DivName in Directory.GetDirectories(Path))
            {
                int op;
                for (op = DivName.Length - 1; op >= 0 && DivName[op] != '\\'; op--) ;
                DivList.Add(new Div(ID, DivName.Substring(op + 1, DivName.Length - op - 1)));
            }
            LoadInfo();
        }

        public void Updata()
        {
            INIFILE INIinfo = new INIFILE(Path, "info.ini");
            String URL = GetRoundURL();
            HTML.HTML html = new HTML.HTML(URL);
            List<Hashtable> info = html.GetDFSDocument();

            //获取name
            for (int i = 0; i < info.Count; i++)
            {
                Hashtable tmp = info[i];
                if ((string)tmp["Type"] == "TAG")
                    if ((string)tmp["Value"] == "option")
                        if (checkURL((string)tmp["value"]) == true)
                        {
                            INIinfo.WriteString("contest", "name", (string)info[i + 1]["Value"]);
                            break;
                        }
            }

            //获取DIV信息
            DivList.Clear();
            int op = 0;
            bool find = true;
            while (find)
            {
                find = false;
                for (; op < info.Count && find == false; op++)
                {
                    Hashtable tmp = info[op];
                    if ((string)tmp["Type"] == "TAG")
                        if ((string)tmp["Value"] == "a")
                            if ((string)tmp["name"] == "\"problem_stats\"")
                            {
                                DivList.Add(new Div(ID, string.Format("Div{0}", DivList.Count + 1)));
                                int CountTR = 0;
                                for (; op < info.Count && CountTR < 2; op++)
                                {
                                    tmp = info[op];
                                    if ((string)tmp["Type"] == "TAG")
                                        if ((string)tmp["Value"] == "tr")
                                            CountTR++;
                                }
                                int CountTD = 0;
                                for (; op < info.Count && CountTD < 6; op++)
                                {
                                    tmp = info[op];
                                    if ((string)tmp["Type"] == "TAG")
                                        if ((string)tmp["Value"] == "td")
                                            CountTD++;
                                }
                                //获取题目信息
                                while (true)
                                {
                                    tmp = info[op];
                                    if ((string)tmp["Type"] == "TAG"
                                        && (string)tmp["Value"] == "tr")
                                    {
                                        CountTD = 0;
                                        for (int i = op + 1; i < info.Count; i++)
                                        {
                                            tmp = info[i];
                                            if ((string)tmp["Value"] == "td")
                                                CountTD++;
                                            else if ((string)tmp["Value"] == "tr")
                                                break;
                                        }
                                        if (CountTD != 7) break;
                                        Problem problem = new Problem(ID, DivList.Last().Name, (string)info[op +6]["Value"]);
                                        String problemids = (string)info[op + 5]["href"];
                                        problem.SetID(problemids.Split('=', '&')[3]);
                                        problem.Updata();
                                        op += 21;
                                    }
                                    else
                                        break;
                                }
                                find = true;
                                op--;
                            }
                }
            }

            UpdataComplete = true;
            Load();
        }

    }
}
