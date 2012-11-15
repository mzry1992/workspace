using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace com.mzry1992.TC.ProblemSet
{
    public class Analysis
    {
        public static string DownloadImage(string Path, string URL)
        {
            if (URL[0] == '/')
                URL = "http://apps.topcoder.com" + URL;
            string path = "Image/" + URL.Split('/').Last();
            if (File.Exists(path)) return path;
            HTML.GetSource.SavePhoto(Path + "/" + path, URL);
            Console.WriteLine("DownloadImage : " + URL + " : " + path);
            return path;
        }

        public static string DownloadCSS(string Path, string URL)
        {
            if (URL[0] == '/')
                URL = "http://apps.topcoder.com" + URL;
            string path = "CSS/" + URL.Split('/').Last();
            if (File.Exists(path)) return path;
            string tmp = HTML.GetSource.GetHTML(URL, Encoding.Default);
            File.WriteAllText(Path + "/" + path, tmp);
            Console.WriteLine("DownloadCSS : " + URL + " : " + path);
            return path;
        }

        public static string UpdataCSSandImage(string Path, string html)
        {
            string res = "";
            for (int i = 0; i < html.Length; i++)
            {
                if (((i - 4 >= 0 && html.Substring(i - 4, 5) == "src=\"") ||
                        (i - 5 >= 0 && html.Substring(i - 5, 6) == "href=\"")))
                {
                    string URL = "";
                    for (i = i + 1; i < html.Length && html[i] != '"'; i++)
                        URL = URL + html[i];
                    i--;
                    URL = URL.Split('?').First();
                    string type = URL.Split('.').Last().ToLower();
                    res = res + '"';
                    if (type == "css")
                        res = res + DownloadCSS(Path, URL);
                    else if (type == "jpg" || type == "gif" || type == "png")
                        res = res + DownloadImage(Path, URL);
                }
                else
                    res = res + html[i];
            }
            return res;
        }

        public static void UpdataNew(string URL)
        {
            Console.WriteLine("Start updata : " + URL);
            URL = URL + "?decorator=printable";
            string key = "Match Overview";
            HTML.HTML html = new HTML.HTML(URL);
            List<Hashtable> info = html.GetDFSDocument();
            string uid = "0";
            for (int i = 0; i < info.Count; i++)
                if ((string)info[i]["Value"] == key)
                {
                    string tmp = (string)info[i - 1]["href"];
                    tmp = tmp.Substring(1, tmp.Length - 2);
                    uid = tmp.Split('=').Last();
                    break;
                }
            if (uid == "0") return;
            string Path = "ProblemSet/" + uid;
            if (Directory.Exists(Path) == false) return;
            string DocPath = Path + "/Solution.doc";
            if (File.Exists(DocPath))
            {
                //string tmp = File.ReadAllText(Path);
                //if (tmp == "")
                File.Delete(DocPath);
                //else
                //    return;
            }
            if (Directory.Exists(Path + "/CSS") == false)
                Directory.CreateDirectory(Path + "/CSS");
            if (Directory.Exists(Path + "/Image") == false)
                Directory.CreateDirectory(Path + "/Image");
            string source = html.source;
            source = UpdataCSSandImage(Path, source);
            File.WriteAllText(DocPath, source);
            Console.WriteLine("Updata : " + URL + " Success!");
        }

        public static void UpdataOld(string URL)
        {
        }

        public static void Updata()
        {
            string URL = "http://apps.topcoder.com/wiki/display/tc/Algorithm+Problem+Set+Analysis?decorator=printable";
            string key = "Problem Set & Analysis";
            HTML.HTML html = new HTML.HTML(URL);
            List<Hashtable> info = html.GetDFSDocument();
            for (int i = 0; i < info.Count; i++)
                if ((string)info[i]["Value"] == key)
                {
                    string tmp = (string)info[i - 1]["href"];
                    tmp = tmp.Substring(1, tmp.Length - 2);
                    if (tmp.StartsWith("http://apps.topcoder.com/wiki/display/tc/"))
                        UpdataNew(tmp);
                    else
                        UpdataOld(tmp);
                }
        }

        public static void Test()
        {
            UpdataNew("http://apps.topcoder.com/wiki/display/tc/SRM+532");
        }
    }
}
