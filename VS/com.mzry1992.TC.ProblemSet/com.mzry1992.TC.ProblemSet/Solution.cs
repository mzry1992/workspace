using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace com.mzry1992.TC.ProblemSet
{
    public class Solution
    {
        public List<KeyValuePair<String, String>> Soluions = new List<KeyValuePair<string,string>>();
        
        private String Path;

        public Solution(String _ContestID,String _DivName,String _ProblemName)
        {
            Path = "ProblemSet/" + _ContestID + "/" + _DivName + "/" + _ProblemName+"/solution";
            Load();
        }

        private void Load()
        {
            if (Directory.Exists(Path) == false)
                Directory.CreateDirectory(Path);

            foreach (String FileName in Directory.GetFiles(Path))
                Soluions.Add(new KeyValuePair<string, string>(FileName, File.ReadAllText(Path + "/" + FileName)));
        }

    }
}
