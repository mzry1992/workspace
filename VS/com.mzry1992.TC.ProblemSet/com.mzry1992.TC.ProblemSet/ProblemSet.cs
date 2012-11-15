using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading;
using System.Collections;

namespace com.mzry1992.TC.ProblemSet
{
    public class ProblemSet
    {
        public List<Contest> ContestList = new List<Contest>();
        public bool UpdataComplete = false;

        public ProblemSet()
        {
            Load();
        }

        public void Load()
        {
            ContestList.Clear();
            if (Directory.Exists("ProblemSet") == false)
                Directory.CreateDirectory("ProblemSet");
            foreach (String ContestName in Directory.GetDirectories("ProblemSet"))
            {
                int op;
                for (op = ContestName.Length - 1; op >= 0 && ContestName[op] != '\\'; op--) ;
                ContestList.Add(new Contest(ContestName.Substring(op + 1, ContestName.Length - op - 1)));
            }
        }

        public void Updata()
        {
            String URL = "http://community.topcoder.com/stat?c=round_overview";                         
            HTML.HTML html = new HTML.HTML(URL);
            List<Hashtable> info = html.GetDFSDocument();
            foreach (Hashtable tmp in info)
                if ((string)tmp["Type"] == "TAG")
                    if ((string)tmp["Value"] == "option")
                        if ((string)tmp["value"] != "\"#\"")
                        {
                            string src = (string)tmp["value"];
                            src = src.Substring(1, src.Length - 2);
                            int op;
                            for (op = src.Length - 1; op >= 0 && src[op] != '='; op--) ;
                            src = src.Substring(op + 1, src.Length - op - 1);
                            if (Directory.Exists(src) == false)
                                Directory.CreateDirectory("ProblemSet/" + src);
                        }
            UpdataComplete = true;
            Load();
        }

    }
}
