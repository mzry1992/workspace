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
    public partial class tabProblemSet : Form
    {
        ProblemSet problem;

        public tabProblemSet(ProblemSet _problem)
        {
            InitializeComponent();
            problem = _problem;
        }

        private void LoadContest()
        {
            ContestView.Items.Clear();
            foreach (Contest ct in problem.ContestList)
                ContestView.Items.Add(ct.Name.ToString());
        }

        private void tabProblemSet_Load(object sender, EventArgs e)
        {
            LoadContest();
        }

        private void tabProblemSet_SizeChanged(object sender, EventArgs e)
        {
            ContestView.Width = Width - 16;
            ContestView.Height = Height - 10;
        }

        private void 刷新ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            problem.StartUpdata();
            LoadContest();
        }

        private void UpdataInfo_Tick(object sender, EventArgs e)
        {
            Main F = (Main)this.Parent.Parent.Parent;
            if (F.I.Text != problem.Status)
            {
                F.I.Text = problem.Status;
                LoadContest();
            }
        }

        private void tabProblemSet_FormClosed(object sender, FormClosedEventArgs e)
        {
        }

    }
}
