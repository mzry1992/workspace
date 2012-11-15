using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.OleDb;
using System.Windows.Forms;

namespace ExcelCompare
{
    class myExcel
    {
        //加载Excel 
        public static DataSet LoadExcel(string filePath)
        {
            try
            {
                string strConn;
                strConn = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + filePath + ";Extended Properties='Excel 8.0;HDR=False;IMEX=1'";
                OleDbConnection OleConn = new OleDbConnection(strConn);
                OleConn.Open();
                
                DataTable OleTables = OleConn.GetOleDbSchemaTable(OleDbSchemaGuid.Tables,new object[] {null, null, null, "TABLE"});
                DataSet OleDsExcle = new DataSet();


                foreach (DataRow dr in OleTables.Rows)
                {
                    String TableName = (String)dr["TABLE_NAME"];

                    String sql = String.Format("SELECT * FROM  [{0}]",TableName);
                    
                    OleDbDataAdapter OleDaExcel = new OleDbDataAdapter(sql, OleConn);
                
                    OleDaExcel.Fill(OleDsExcle, TableName);
                }
                OleConn.Close();
                return OleDsExcle;
            }
            catch
            {
                return null;
            }
        }
    }
}
