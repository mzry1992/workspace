using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace com.mzry1992.TC.ProblemSet
{
    public class Div
    {        
        public String Name;
        public List<Problem> ProblemList = new List<Problem>();
        public String Path;
        private String ContestID;

        public Div(String _ContestID,String _DivName)
        {
            ContestID = _ContestID;
            Name = _DivName;
            Path = "ProblemSet/" + ContestID+"/"+Name;
            Load();
        }

        private void Load()
        {
            if (Directory.Exists(Path) == false)
                Directory.CreateDirectory(Path);
            foreach (String ProblemName in Directory.GetDirectories(Path))
            {
                int op;
                for (op = ProblemName.Length - 1; op >= 0 && ProblemName[op] != '\\'; op--) ;
                ProblemList.Add(new Problem(ContestID, Name, ProblemName.Substring(op + 1, ProblemName.Length - op - 1)));
            }
        }
    }
}
