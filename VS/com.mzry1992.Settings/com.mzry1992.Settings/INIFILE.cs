using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;

namespace com.mzry1992.Settings
{

    public class INIFILE
    {
        #region DllImport
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileInt(
           string lpAppName,
           string lpKeyName,
           int nDefault,
           string lpFileName
           );
        [DllImport("kernel32")]
        private static extern int GetPrivateProfileString(
           string lpAppName,
           string lpKeyName,
           string lpDefault,
           StringBuilder lpReturnedString,
           int nSize,
           string lpFileName
           );
        [DllImport("kernel32")]
        private static extern bool WritePrivateProfileString(
           string lpAppName,
           string lpKeyName,
           string lpString,
           string lpFileName
           );
        #endregion

        private string _FileName;
        private string Path = System.IO.Directory.GetCurrentDirectory();

        public INIFILE(string Path, string FileName)
        {
            _FileName = Path + "\\" + FileName;
        }

        public INIFILE(string FileName)
        {
            _FileName = Path+"\\"+FileName;
        }

        public INIFILE()
        {
            _FileName = Path+"\\"+"Default.ini";
        }

        /// <summary>
        /// 读取整数
        /// </summary>
        /// <param name="section">文件节</param>
        /// <param name="key">键值</param>
        /// <param name="def">默认数值</param>
        public int GetInt(string section, string key, int def)
        {
            return GetPrivateProfileInt(section, key, def, _FileName);
        }

        /// <summary>
        /// 读取字符串
        /// </summary>
        /// <param name="section">文件节</param>
        /// <param name="key">键值</param>
        /// <param name="def">默认数值</param>
        public string GetString(string section, string key, string def)
        {
            StringBuilder temp = new StringBuilder(1024);
            GetPrivateProfileString(section, key, def, temp, 1024, _FileName);
            return temp.ToString();
        }

        /// <summary>
        /// 读取布尔数值
        /// </summary>
        /// <param name="section">文件节</param>
        /// <param name="key">键值</param>
        /// <param name="def">默认数值</param>
        public bool GetBoolean(string section, string key, bool def)
        {
            bool retvalue = GetInt(section, key, (def ? 1 : 0)) == 1;
            return retvalue;
        }

        /// <summary>
        /// 写入整数数值
        /// </summary>
        /// <param name="section">文件节</param>
        /// <param name="key">键值</param>
        /// <param name="iVal">数值</param>
        public void WriteInt(string section, string key, int iVal)
        {
            WritePrivateProfileString(section, key, iVal.ToString(), _FileName);
        }

        /// <summary>
        /// 写入字符串
        /// </summary>
        /// <param name="section">文件节</param>
        /// <param name="key">键值</param>
        /// <param name="strVal">数值</param>
        public void WriteString(string section, string key, string strVal)
        {
            WritePrivateProfileString(section, key, strVal, _FileName);
        }

        /// <summary>
        /// 写入布尔数值
        /// </summary>
        /// <param name="section">文件节</param>
        /// <param name="key">键值</param>
        /// <param name="bVal">数值</param>
        public void WriteBoolean(string section, string key, bool bVal)
        {
            WriteInt(section, key, (bVal ? 1 : 0));
        }

        /// <summary>
        /// 删除键
        /// </summary>
        /// <param name="section">文件节</param>
        /// <param name="key">键值</param>
        public void DelKey(string section, string key)
        {
            WritePrivateProfileString(section, key, null, _FileName);
        }

        /// <summary>
        /// 删除节
        /// </summary>
        /// <param name="section">文件节</param>
        public void DelSection(string section)
        {
            WritePrivateProfileString(section, null, null, _FileName);
        }

    }
}
