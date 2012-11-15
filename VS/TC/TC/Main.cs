using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using com.mzry1992.TC.ProblemSet;

namespace TC
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void Main_Load(object sender, EventArgs e)
        {
            TabPage tb = new TabPage("ProblemSet");
            MainView.TabPages.Add(tb);

            tabProblemSet tProblemSet = new tabProblemSet(new ProblemSet());
            tProblemSet.TopLevel = false;
            tProblemSet.Parent = tb;
            tProblemSet.ControlBox = false;
            tProblemSet.Dock = System.Windows.Forms.DockStyle.Fill;
            tProblemSet.FormBorderStyle = FormBorderStyle.None;

            tProblemSet.Show();

        }

        private void Main_Resize(object sender, EventArgs e)
        {
            MainView.Height = Height - 66;
            MainView.Width = Width-20;
        }

        private void StatusView_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
        }

    }
}
