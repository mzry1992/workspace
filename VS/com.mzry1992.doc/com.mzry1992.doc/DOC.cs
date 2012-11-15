using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Web;
using System.IO;

namespace com.mzry1992.doc
{
    public class DOC
    {
        public static void Write(string str,string fileName)
        {
            HttpResponse Response = System.Web.HttpContext.Current.Response;
            Response.ContentEncoding = System.Text.Encoding.Default;
            StringWriter word = new System.IO.StringWriter();
            Response.AppendHeader("Content-Disposition", string.Format("attachment;filename={0}",fileName));  //保存的文件名
            Response.ContentType = "application/vnd.ms-word";
            Response.Write(str);
            Response.End();
        }
    }
}
