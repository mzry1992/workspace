using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ExcelCompare
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        DataSet ImportData1 = null;
        string ImportFileName1 = null;
        bool success1;
        int TableName1; //选中的表
        int ColName1; //选中的列

        DataSet ImportData2 = null;
        string ImportFileName2 = null;
        bool success2;
        int TableName2;
        int ColName2;

        List<KeyValuePair<int, int>> relationship = new List<KeyValuePair<int,int>>(0);
        List<bool> diff = new List<bool>(0);

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private string ChooseFilePath()
        {
            this.openFileDialog1.Multiselect = false;
            this.openFileDialog1.Filter = "EXCEL文件(*.xls)|*.xls";
            if (this.openFileDialog1.ShowDialog() == DialogResult.OK)
                return openFileDialog1.FileName;
            else
                return null;
        }

        private bool LoadExcelData(ref string ImportFileName, ref DataSet ImportData)
        {
            ImportFileName = ChooseFilePath();
            if (ImportFileName != null)
            {
                ImportData = myExcel.LoadExcel(ImportFileName);
                if (ImportData != null)
                    return true;
            }
            return false;
        }

        private void ShowTables(ref ListBox listbox, DataSet ImportData)
        {
            listbox.Items.Clear();
            foreach (DataTable dt in ImportData.Tables)
                listbox.Items.Add(dt.TableName);
        }

        private void ShowCols(ref ListBox listbox, DataTable ImportData,bool firstline)
        {
            listbox.Items.Clear();
            //listbox.Items.Add("返回上一层");
            if (firstline == false)
            {
                for (int i = 0; i < ImportData.Columns.Count; i++)
                    listbox.Items.Add((char)('A' + i));
            }
            else
            {
                foreach (DataColumn dr in ImportData.Columns)
                    listbox.Items.Add(dr.ColumnName);
            }
        }

        private void ShowRelation()
        {
            listBox3.Items.Clear();
            for (int i = 0; i < listBox2.Items.Count; i++)
                listBox3.Items.Add("");
            if (TableName1 == -1 || TableName2 == -1) return;
            for (int i = 0; i < relationship.Count; i++)
            {
                listBox3.Items[relationship[i].Value] = listBox1.Items[relationship[i].Key];
                if (diff[i] == true)
                    listBox3.Items[relationship[i].Value] += "*"; 
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            success1 = LoadExcelData(ref ImportFileName1, ref ImportData1);
            if (success1 == true)
            {
                ShowTables(ref listBox1, ImportData1);
                this.textBox1.Text = ImportFileName1;
                TableName1 = ColName1 = -1;
                radioButton1.Enabled = radioButton2.Enabled = false;
                relationship.Clear();
                diff.Clear();
                ShowRelation();
            }
            else
            {
                MessageBox.Show("打开文件1失败");
                this.textBox1.Text = "";
                TableName1 = ColName1 = -1;
                radioButton1.Enabled = radioButton2.Enabled = false;
            }
        }


        private void button2_Click(object sender, EventArgs e)
        {
            success2 = LoadExcelData(ref ImportFileName2, ref ImportData2);
            if (success2 == true)
            {
                ShowTables(ref listBox2, ImportData2);
                this.textBox2.Text = ImportFileName2;
                TableName2 = ColName2 = -1;
                radioButton3.Enabled = radioButton4.Enabled = false;
                relationship.Clear();
                diff.Clear();
                ShowRelation();
            }
            else
            {
                MessageBox.Show("打开文件2失败");
                this.textBox2.Text = "";
                TableName1 = ColName1 = -1;
                radioButton1.Enabled = radioButton2.Enabled = false;
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void listBox1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (success1 == false) return;
            if (this.listBox1.SelectedItem == null) return;
            if (TableName1 == -1)
            {
                TableName1 = this.listBox1.SelectedIndex;
                radioButton1.Enabled = radioButton2.Enabled = true;
                radioButton1.Checked = true;
                relationship.Clear();
                diff.Clear();
                ShowRelation();
                ShowCols(ref listBox1, ImportData1.Tables[TableName1], radioButton1.Checked);
            }
        }

        private void listBox2_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            if (success2 == false) return;
            if (this.listBox2.SelectedItem == null) return;
            if (TableName2 == -1)
            {
                TableName2 = this.listBox2.SelectedIndex;
                radioButton3.Enabled = radioButton4.Enabled = true;
                radioButton3.Checked = true;
                relationship.Clear();
                diff.Clear();
                ShowRelation();
                ShowCols(ref listBox2, ImportData2.Tables[TableName2], radioButton3.Checked);
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            relationship.Clear();
            diff.Clear();
            ShowRelation();
            ShowCols(ref listBox1, ImportData1.Tables[TableName1], radioButton1.Checked);
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            relationship.Clear();
            diff.Clear();
            ShowRelation();
            ShowCols(ref listBox1, ImportData1.Tables[TableName1], radioButton1.Checked);
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            relationship.Clear();
            diff.Clear();
            ShowRelation();
            ShowCols(ref listBox2, ImportData2.Tables[TableName2], radioButton3.Checked);
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            relationship.Clear();
            diff.Clear();
            ShowRelation();
            ShowCols(ref listBox2, ImportData2.Tables[TableName2], radioButton3.Checked);
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (TableName1 == -1 || TableName2 == -1) return;
            ColName1 = ColName2 = -1;
            if (listBox1.SelectedItem == null) return;
            if (listBox2.SelectedItem == null) return;
            ColName1 = listBox1.SelectedIndex;
            ColName2 = listBox2.SelectedIndex;
            for (int i = 0;i < relationship.Count;i++)
                if (relationship[i].Key == ColName1 || relationship[i].Value == ColName2)
                {
                    relationship.RemoveAt(i);
                    diff.RemoveAt(i);
                }
            relationship.Add(new KeyValuePair<int, int>(ColName1, ColName2));
            diff.Add(false);
            ShowRelation();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            relationship.Clear();
            diff.Clear();
            ShowRelation();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (TableName1 == -1 || TableName2 == -1) return;
            ColName1 = ColName2 = -1;
            if (listBox1.SelectedItem == null) return;
            if (listBox2.SelectedItem == null) return;
            ColName1 = listBox1.SelectedIndex;
            ColName2 = listBox2.SelectedIndex;
            for (int i = 0; i < relationship.Count; i++)
                if (relationship[i].Key == ColName1 || relationship[i].Value == ColName2)
                {
                    relationship.RemoveAt(i);
                    diff.RemoveAt(i);
                }
            ShowRelation();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (listBox3.SelectedItem == null) return;
            for (int i = 0; i < relationship.Count; i++)
                if (relationship[i].Value == listBox3.SelectedIndex)
                    diff[i] = true;
            ShowRelation();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (listBox3.SelectedItem == null) return;
            for (int i = 0; i < relationship.Count; i++)
                if (relationship[i].Value == listBox3.SelectedIndex)
                    diff[i] = false;
            ShowRelation();
        }

        private void button7_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < relationship.Count; i++)
                diff[i] = false;
            ShowRelation();
        }

        public DataTable result;
        private DataTable d1,d2;

        private void button9_Click(object sender, EventArgs e)
        {
            if (relationship.Count == 0)
            {
                MessageBox.Show("请选择关联项目");
                return;
            }
            bool flag = true;
            for (int i = 0;i < relationship.Count;i++)
                if (diff[i] == true)
                {
                    flag = false;
                    break;
                }
            if (flag == true)
            {
                MessageBox.Show("请选择对比项目");
                return;
            }

            d1 = ImportData1.Tables[TableName1];
            if (radioButton2.Checked == true)
            {
                DataRow newrow = d1.Rows[0];
                for (int i = 0; i < d1.Columns.Count; i++)
                {
                    newrow[i] = d1.Columns[i].ColumnName;
                    d1.Columns[i].ColumnName = ""+(char)('A' + i);
                }
                d1.Rows.Add(newrow);
            }

            d2 = ImportData2.Tables[TableName2];
            if (radioButton4.Checked == true)
            {
                DataRow newrow = d2.Rows[0];
                for (int i = 0; i < d2.Columns.Count; i++)
                {
                    newrow[i] = d2.Columns[i].ColumnName;
                    d2.Columns[i].ColumnName = ""+(char)('A' + i);
                }
                d2.Rows.Add(newrow);
            }

            result = new DataTable();
            result.Rows.Clear();
            result.Columns.Clear();
            for (int i = 0; i < relationship.Count; i++)
                result.Columns.Add(d1.Columns[relationship[i].Key].ColumnName);
            result.Columns.Add("原因");

            foreach (DataRow r1 in d1.Rows)
            {
                DataRow newrow = result.NewRow();
                for (int i = 0; i < relationship.Count; i++)
                    newrow[i] = r1[i];

                bool find = false;
                foreach (DataRow r2 in d2.Rows)
                {
                    //
                    //
                }
                if (find == false)
                {
                    newrow[result.Columns.Count - 1] = "无匹配数据";
                    result.Rows.Add(newrow);
                }
            }

            Form2 form2 = new Form2(result);
            form2.Show();
        }
    }
}
