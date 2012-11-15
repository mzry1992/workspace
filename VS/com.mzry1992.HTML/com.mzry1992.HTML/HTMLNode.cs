using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace com.mzry1992.HTML
{
    public class HTMLNode
    {
        public Hashtable Info = new Hashtable();
        public List<HTMLNode> Children = new List<HTMLNode>();

        private List<DictionaryEntry> elements = new List<DictionaryEntry>();
        private List<int> startpos = new List<int>();
        private List<int> endpos = new List<int>();

        private String HTML;

        public HTMLNode()
        {
            Info["Type"] = "String";
            Info["Value"] = Info["Source"] = "";
        }

        public HTMLNode(String Type,String _HTML)
        {
            HTML = _HTML;
            Info["Type"] = Type;
            Info["Source"] = _HTML;
            if (Type == "STRING")
            {
                Info["Value"] = DelBlanks(HTML);
            }
            else
            {
                GetElements();
                /*for (int i = 0; i < elements.Count; i++)
                {
                    DictionaryEntry dt = elements[i];
                    Console.WriteLine(string.Format("{0} {1} : {2}", dt.Key, dt.Value,_HTML.Substring(startpos[i],endpos[i]-startpos[i]+1)));
                }
                return;*/
                GetInfo();
                GetChildren();
            }
        }

        private void GetChildren()
        {
            for (int i = 1; i < elements.Count - 1; i++)
            {
                if ((string)elements[i].Key == "TAG")
                {
                    bool find = false;
                    int cnt = 0;
                    for (int j = i; j < elements.Count-1; j++)
                    {
                        if ((string)elements[j].Value == (string)elements[i].Value)
                        {
                            if ((string)elements[j].Key == "TAG")
                                cnt++;
                            else
                            {
                                cnt--;
                                if (cnt == 0)
                                {
                                    find = true;
                                    Children.Add(new HTMLNode("TAG", HTML.Substring(startpos[i], endpos[j] - startpos[i] + 1)));
                                    i = j;
                                    break;
                                }
                            }
                        }
                    }
                    if (find == false)
                    {
                        Children.Add(new HTMLNode("TAG", HTML.Substring(startpos[i], endpos[i] - startpos[i] + 1)));
                    }
                }
                else
                {
                    string tmp = DelBlanks(HTML.Substring(startpos[i], endpos[i] - startpos[i] + 1));
                    if (tmp != "")
                        Children.Add(new HTMLNode("STRING", tmp));
                }
            }
        }

        private void DFS(int deep, HTMLNode now)
        {
            foreach (HTMLNode next in now.Children)
                DFS(deep + 1, next);
        }

        public void Show()
        {
            DFS(0, this);
        }

        public HTMLNode GotoFirstAppearTAG(String id)
        {
            foreach (HTMLNode next in Children)
                if (next.Get("Type") == "TAG")
                    if (next.Get("Value") == id)
                        return next;
            return new HTMLNode();
        }

        public HTMLNode GotoFirstAppearTAG(String key,String value)
        {
            foreach (HTMLNode next in Children)
                if (next.Get("Type") == "TAG")
                    if (next.Get(key) == value)
                        return next;
            return new HTMLNode();
        }

        public String Get(String id)
        {
            if (Info.Contains(id) == false) return "";
            return (string)Info[id];
        }

        private void GetInfo()
        {
            String _HTML = HTML.Substring(startpos[0] + 1, endpos[0] - startpos[0] - 1);
            List<string> tmps = new List<string>();
            bool inString = false;
            char charString = ' ';
            int lastpos = 0;
            for (int i = 0;i < _HTML.Length;i++)
            {
                if (inString == true)
                {
                    if (i > 0 && _HTML[i - 1] != '\\' && _HTML[i] == charString)
                    {
                        inString = false;
                        charString = ' ';
                    }
                }
                else
                {
                    if (i > 0 && _HTML[i - 1] != '\\' && (_HTML[i] == '\'' || _HTML[i] == '"'))
                    {
                        inString = true;
                        charString = _HTML[i];
                    }
                }
                if (inString == true) continue;

                if (_HTML[i] == ' ')
                {
                    tmps.Add(_HTML.Substring(lastpos, i - lastpos));
                    lastpos = i+1;
                }
                if (_HTML[i] == '=')
                {
                    tmps.Add(_HTML.Substring(lastpos, i - lastpos));
                    tmps.Add("=");
                    lastpos = i + 1;
                }
            }
            tmps.Add(_HTML.Substring(lastpos, _HTML.Length - lastpos));
            string tmp;
            List<String> info = new List<string>();
            foreach (string s in tmps)
                if (s != "")
                    info.Add(s);
            Info["Value"] = info[0].ToLower();
            for (int i = 1; i < info.Count; i += 3)
            {
                if (i + 2 >= info.Count || info[i + 1] != "=")
                {
                    tmp = "";
                    for (int j = i; j < info.Count; j++)
                        tmp = tmp + " " + info[j];
                    Info["Unknow"] = tmp;
                    break;
                }
                else
                {
                    Info[info[i].ToLower()] = info[i + 2];
                }
            }
        }

        private String DelBlanks(String s)
        {
            int op, ed;
            for (op = 0; op < s.Length && s[op] < 33; op++) ;
            for (ed = s.Length - 1; ed >= 0 && s[ed] < 33; ed--) ;
            if (op > ed) return "";
            return s.Substring(op, ed - op + 1);
        }

        private void AddElements(String s,int op,int ed)
        {
            startpos.Add(op);
            endpos.Add(ed);
            if (s == "STRING")
            {
                elements.Add(new DictionaryEntry(s,""));
            }
            else
            {
                String tmp = DelBlanks(HTML.Substring(op + 1, ed - op - 1)).Split(' ')[0];
                if (tmp[0] == '/')
                    elements.Add(new DictionaryEntry("CLOSETAG", tmp.Substring(1, tmp.Length - 1).ToLower()));
                else
                    elements.Add(new DictionaryEntry("TAG", tmp.ToLower()));
            }
        }

        private void GetElements()
        {
            int pre = 0;
            bool inString = false;
            char charString = ' ';

            //table
            for (int i = 1; i < HTML.Length; i++)
            {
                /*if (inString == true)
                {
                    if (HTML[i - 1] != '\\' && HTML[i] == charString)
                    {
                        inString = false;
                        charString = ' ';
                    }
                }
                else
                {
                    if (HTML[i - 1] != '\\' && HTML[i] == '"')
                    {
                        inString = true;
                        charString = HTML[i];
                    }
                }
                if (inString == true)
                    continue;*/
                if (HTML[pre] == '<')
                {
                    if (HTML[i] == '>')
                    {
                        AddElements("TAG", pre, i);
                        pre = i + 1;
                    }
                }
                else
                {
                    if (HTML[i] == '<')
                    {
                        AddElements("STRING", pre, i - 1);
                        pre = i;
                    }
                }

            }
        }

    }
}
