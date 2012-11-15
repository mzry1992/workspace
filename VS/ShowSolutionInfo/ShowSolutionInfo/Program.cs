using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ShowSolutionInfo
{
    class Program
    {
        static void Main(string[] args)
        {
            DirectoryInfo folder = new DirectoryInfo(System.Environment.CurrentDirectory);
            String info = "=================================================\n";
            foreach (DirectoryInfo chi in folder.GetDirectories())
            {
                info += chi.Name;
                info += ",包含文件数 : " + chi.GetFiles().Length + "\n";
            }
            info += "=================================================";
            File.WriteAllText("info.txt", info);
        }
    }
}
