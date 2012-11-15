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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        public Form2(DataTable data)
        {
            InitializeComponent();
            dataGridView1.DataSource = data;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void dataGridView1_Resize(object sender, EventArgs e)
        {
        }

        private void Form2_SizeChanged(object sender, EventArgs e)
        {
            dataGridView1.Top = 10;
            dataGridView1.Left = 10;
            dataGridView1.Height = this.Height - 56;
            dataGridView1.Width = this.Width - 30;
        }
    }
}
