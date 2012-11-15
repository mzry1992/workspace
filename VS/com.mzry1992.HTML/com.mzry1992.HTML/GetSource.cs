using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Net;
using System.IO;

namespace com.mzry1992.HTML
{
    public class GetSource
    {
        /// <summary>
        /// 获取网页HTML代码
        /// </summary>
        /// <param name="url">网址</param>
        /// <param name="cookie">cookie</param>
        /// <returns></returns>
        public static string GetHTML(string url, CookieCollection cookie)
        {
            CookieContainer cc = new CookieContainer();
            cc.Add(cookie);

            Uri uri = new Uri(url);
            HttpWebRequest hwReq = (HttpWebRequest)WebRequest.Create(uri);
            hwReq.CookieContainer = cc;

            HttpWebResponse hwRes;

            try
            {
                hwRes = (HttpWebResponse)hwReq.GetResponse();
            }
            catch
            {
                return "NONE";
            }

            hwReq.Method = "Get";
            hwReq.KeepAlive = false;

            StreamReader reader = new StreamReader(hwRes.GetResponseStream(), System.Text.Encoding.GetEncoding("GB2312"));
            return reader.ReadToEnd();
        }

        /// <summary>
        /// 获取网页HTML代码
        /// </summary>
        /// <param name="url">网址</param>
        /// <returns></returns>
        public static string GetHTML(string url, System.Text.Encoding encode)
        {
            string result;
            try
            {
                System.Net.WebClient aWebClient = new System.Net.WebClient();
                aWebClient.Encoding = encode;
                string html = aWebClient.DownloadString(url);
                result = html;
            }
            catch (Exception ex)
            {
                result = ex.ToString();
            }
            return result;
        }

        public static bool SaveBinaryFile(WebResponse response, string FileName)
        {
            bool Value = true;
            byte[] buffer = new byte[1024];

            try
            {
                if (File.Exists(FileName))
                    File.Delete(FileName);
                Stream outStream = File.Create(FileName);
                Stream inStream = response.GetResponseStream();

                int l;
                do
                {
                    l = inStream.Read(buffer, 0, buffer.Length);
                    if (l > 0)
                        outStream.Write(buffer, 0, l);
                }
                while (l > 0);

                outStream.Close();
                inStream.Close();
            }
            catch
            {
                Value = false;
            }
            return Value;
        }

        public static bool SavePhoto(string FileName, string Url)
        {
            bool Value = false;
            WebResponse response = null;
            Stream stream = null;
            try
            {
                HttpWebRequest request = (HttpWebRequest)WebRequest.Create(Url);

                response = request.GetResponse();
                stream = response.GetResponseStream();

                if (!response.ContentType.ToLower().StartsWith("text/"))
                {
                    Value = SaveBinaryFile(response, FileName);
                }
            }
            catch
            {
                Value = false;
            }
            return Value;
        }

    }
}
