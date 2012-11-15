using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using com.mzry1992.TC.ProblemSet;
using com.mzry1992.Settings;
using System.IO;

namespace TCgeter
{
    class Program
    {
        public static ProblemSet p = new ProblemSet();

        public static void CheckAll()
        {
            int tot = 0;
            foreach (Contest c in p.ContestList)
            {
                foreach (Div d in c.DivList)
                {
                    foreach (Problem pp in d.ProblemList)
                    {
                        if (File.Exists(pp.ProblemPath) == false)
                        {
                            Console.WriteLine(string.Format("Not Eexists : {0}", pp.ProblemPath));
                            pp.Updata();
                            tot++;
                        }
                        else
                        {
                            string tmp = File.ReadAllText(pp.ProblemPath);
                            if (tmp == "") continue;
                            string replacestr = string.Format("<center><h1>{0}</h1></center>", pp.Name);
                            if (tmp.Contains(replacestr) == false)
                            {
                                Console.WriteLine(string.Format("Incomplete : {0}", pp.ProblemPath));
                                pp.Updata();
                                tot++;
                            }
                            else
                            {
                                Console.Write("Get image : " + pp.ProblemPath+" ...");
                                pp.GetImage();
                                Console.WriteLine("OK");
                            }
                        }
                    }
                }
            }
            Console.WriteLine(tot);
        }

        public static void Updata()
        {
            Console.Write("更新列表...");
            p.Updata();
            Console.WriteLine("完毕!");
            for (int i = 0; i < p.ContestList.Count; i++)
                if (p.ContestList[i].Name == "null")
                {
                    Console.Write("更新"+p.ContestList[i].ID+"中...");
                    p.ContestList[i].Updata();
                    Console.WriteLine("完毕!");
                }
        }

        private static bool check(char c)
        {
            if (c >= '0' && c <= '9') return true;
            if (c >= 'a' && c <= 'z') return true;
            if (c >= 'A' && c <= 'Z') return true;
            if (c == ' ' || c == '.') return true;
            return false;
        }

        private static void CopyDir(string srcPath, string aimPath)
        {
            try
            {
                // 检查目标目录是否以目录分割字符结束如果不是则添加之 
                if (aimPath[aimPath.Length - 1] != System.IO.Path.DirectorySeparatorChar)
                {
                    aimPath += System.IO.Path.DirectorySeparatorChar;
                }

                // 判断目标目录是否存在如果不存在则新建之 
                if (!System.IO.Directory.Exists(aimPath))
                {
                    System.IO.Directory.CreateDirectory(aimPath);
                }

                // 得到源目录的文件列表，该里面是包含文件以及目录路径的一个数组 
                // 如果你指向copy目标文件下面的文件而不包含目录请使用下面的方法 
                // string[] fileList = Directory.GetFiles(srcPath); 
                string[] fileList = System.IO.Directory.GetFileSystemEntries(srcPath);

                // 遍历所有的文件和目录 
                foreach (string file in fileList)
                {
                    // 先当作目录处理如果存在这个目录就递归Copy该目录下面的文件 
                    if (System.IO.Directory.Exists(file))
                    {
                        CopyDir(file, aimPath + System.IO.Path.GetFileName(file));
                    }

                    // 否则直接Copy文件 
                    else
                    {
                        System.IO.File.Copy(file, aimPath + System.IO.Path.GetFileName(file), true);
                    }
                }
            }

            catch (Exception e)
            {
                throw;
            }
        }

        public static void Public()
        {
            if (Directory.Exists("Public") == true)
                Directory.Delete("Public");
            Directory.CreateDirectory("Public");
            for (int i = 0; i < p.ContestList.Count; i++)
            {
                Console.Write("Copy : " + p.ContestList[i].Name);
                Contest c = p.ContestList[i];
                string cName = "";
                for (int j = 0; j < c.Name.Length; j++)
                    if (check(c.Name[j]) == true)
                        cName = cName + c.Name[j];
                Directory.CreateDirectory("Public/" + cName);
                foreach (Div d in c.DivList)
                {
                    CopyDir(d.Path, "Public/" + cName + "/" + d.Name);
                }
                Console.WriteLine(" OK");
            }
        }

        public static void GetSolution()
        {
            Analysis.Test();
            //Analysis.Updata();
        }

        static void Main(string[] args)
        {
            while (true)
            {
                string command;
                Console.WriteLine("UpdataAll    : 1");
                Console.WriteLine("CheckAll     : 2");
                Console.WriteLine("Public       : 3");
                Console.WriteLine("Get Solution : 4");
                Console.WriteLine("Exit      : Others");
                command = Console.ReadLine();
                if (command == "1")
                    Updata();
                else if (command == "2")
                    CheckAll();
                else if (command == "3")
                    Public();
                else if (command == "4")
                    GetSolution();
                else 
                    break;
            }
        }
    }
}
