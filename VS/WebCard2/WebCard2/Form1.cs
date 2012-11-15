using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WebCard2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private int[,] pwdtable = new int[10,8];

        private void b_quit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            pwdtable[0, 0] = 57;
            pwdtable[0, 1] = 87;
            pwdtable[0, 2] = 98;
            pwdtable[0, 3] = 04;
            pwdtable[0, 4] = 02;
            pwdtable[0, 5] = 65;
            pwdtable[0, 6] = 81;
            pwdtable[0, 7] = 14;
            pwdtable[1, 0] = 35;
            pwdtable[1, 1] = 42;
            pwdtable[1, 2] = 27;
            pwdtable[1, 3] = 26;
            pwdtable[1, 4] = 94;
            pwdtable[1, 5] = 51;
            pwdtable[1, 6] = 17;
            pwdtable[1, 7] = 71;
            pwdtable[2, 0] = 56;
            pwdtable[2, 1] = 51;
            pwdtable[2, 2] = 48;
            pwdtable[2, 3] = 82;
            pwdtable[2, 4] = 65;
            pwdtable[2, 5] = 56;
            pwdtable[2, 6] = 80;
            pwdtable[2, 7] = 80;
            pwdtable[3, 0] = 34;
            pwdtable[3, 1] = 04;
            pwdtable[3, 2] = 60;
            pwdtable[3, 3] = 73;
            pwdtable[3, 4] = 78;
            pwdtable[3, 5] = 44;
            pwdtable[3, 6] = 45;
            pwdtable[3, 7] = 10;
            pwdtable[4, 0] = 43;
            pwdtable[4, 1] = 05;
            pwdtable[4, 2] = 20;
            pwdtable[4, 3] = 47;
            pwdtable[4, 4] = 68;
            pwdtable[4, 5] = 46;
            pwdtable[4, 6] = 42;
            pwdtable[4, 7] = 86;
            pwdtable[5, 0] = 87;
            pwdtable[5, 1] = 72;
            pwdtable[5, 2] = 63;
            pwdtable[5, 3] = 64;
            pwdtable[5, 4] = 71;
            pwdtable[5, 5] = 27;
            pwdtable[5, 6] = 59;
            pwdtable[5, 7] = 21;
            pwdtable[6, 0] = 64;
            pwdtable[6, 1] = 07;
            pwdtable[6, 2] = 95;
            pwdtable[6, 3] = 92;
            pwdtable[6, 4] = 93;
            pwdtable[6, 5] = 68;
            pwdtable[6, 6] = 35;
            pwdtable[6, 7] = 78;
            pwdtable[7, 0] = 23;
            pwdtable[7, 1] = 93;
            pwdtable[7, 2] = 31;
            pwdtable[7, 3] = 53;
            pwdtable[7, 4] = 31;
            pwdtable[7, 5] = 26;
            pwdtable[7, 6] = 44;
            pwdtable[7, 7] = 42;
            pwdtable[8, 0] = 94;
            pwdtable[8, 1] = 71;
            pwdtable[8, 2] = 48;
            pwdtable[8, 3] = 60;
            pwdtable[8, 4] = 81;
            pwdtable[8, 5] = 75;
            pwdtable[8, 6] = 94;
            pwdtable[8, 7] = 07;
            pwdtable[9, 0] = 94;
            pwdtable[9, 1] = 10;
            pwdtable[9, 2] = 33;
            pwdtable[9, 3] = 44;
            pwdtable[9, 4] = 73;
            pwdtable[9, 5] = 58;
            pwdtable[9, 6] = 19;
            pwdtable[9, 7] = 86;
        }

        private string getres(string pwd)
        {
            string res;
            if (pwd.Length != 2) return "??";
            pwd = pwd.ToUpper();
            if (pwd[0] >= 'A' && pwd[0] <= 'J' &&
                pwd[1] >= '1' && pwd[1] <= '8')
                res = pwdtable[pwd[0] - 'A', pwd[1] - '1'].ToString();
            else
                res = "??";
            return res;
        }

        private void b_ok_Click(object sender, EventArgs e)
        {
            t_res1.Text = getres((string)t_pwd1.Text);
            t_res2.Text = getres((string)t_pwd2.Text);
            t_res3.Text = getres((string)t_pwd3.Text);
        }

        private void b_clear_Click(object sender, EventArgs e)
        {
            t_pwd1.Text = t_pwd2.Text = t_pwd3.Text = "";
            t_res1.Text = t_res2.Text = t_res3.Text = "";
        }
    }
}
