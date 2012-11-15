using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.Net;
using System.IO;

namespace com.mzry1992.HTML
{
    public class HTML
    {
        public string source;
        public HTMLNode Document;

        private List<Hashtable> DFSDocument;

        public HTML()
        {
            source = "";
            Document = new HTMLNode();
        }

        public HTML(string url)
        {
            source = GetSource.GetHTML(url, System.Text.Encoding.Default);
            AnalyseHTML();
        }

        public HTML(string url,System.Text.Encoding encode)
        {
            source = GetSource.GetHTML(url, encode);
            AnalyseHTML();
        }

        public HTML(string url, CookieCollection cookie)
        {
            source = GetSource.GetHTML(url, cookie);
            AnalyseHTML();
        }

        /// <summary>
        /// 分析源代码
        /// </summary>
        public void AnalyseHTML()
        {
            try
            {
                Document = new HTMLNode("TAG",source);
            }
            catch (Exception ex)
            {
                Document = new HTMLNode("STRING",ex.ToString());
            }
        }

        private int DFS(HTMLNode now)
        {
            int pos = DFSDocument.Count;
            DFSDocument.Add(now.Info);
            int totchildren = 0;
            foreach(HTMLNode next in now.Children)
                totchildren += DFS(next);
            DFSDocument[pos]["TotChildren"] = totchildren;
            return totchildren;
        }

        public List<Hashtable> GetDFSDocument()
        {
            DFSDocument = new List<Hashtable>();
            DFS(Document);
            return DFSDocument;
        }

    }
}
