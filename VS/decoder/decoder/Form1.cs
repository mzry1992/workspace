using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace decoder
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private int lastframe;

        private void allclear()
        {
            output.Clear();
            lastframe = 1;
        }

        private void b_clear_Click(object sender, EventArgs e)
        {
            allclear();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            allclear();
        }

        private int[] CRC(int[] buf, int len, int key, int keylen)
        {
            int[] res = new int[len];
            for (int i = 0;i < len;i++)
                res[i] = buf[i];
            for (int i = keylen - 1, j = 0; i < len; i++, j++)
            {
                if (res[j] == 1)
                    for (int k = 0; k < keylen; k++)
                        res[j + k] ^= (key >> k) & 1;
            }
            for (int i = 0; i < len - keylen; i++)
                res[i] = buf[i];
            return res;
        }

        private void b_check_Click(object sender, EventArgs e)
        {
            string buf = rec.Text.ToString();
            int len = buf.Length;
            int[] bit = new int[len];
            int bitlen = 0;
            int last1 = 0;
            for (int i = 8; i < len - 8; i++)
            {
                bit[bitlen++] = buf[i] - '0';
                if (buf[i] == '1') last1++;
                else
                    last1 = 0;
                if (last1 == 5) i++;
            }
            int[] res = CRC(bit, bitlen, 0x04C11DB7, 32);
            bool check = true;
            for (int i = 0; i < 32; i++)
                if (res[bitlen - 1 - i] != 0)
                {
                    check = false;
                    break;
                }
            if (bitlen != 65) check = false;
            if (check == true)
            {
                send.Text = "011111101111111101111110";
                if (lastframe != bit[0])
                {
                    lastframe = bit[0];
                    for (int i = 1; i <= 32; i += 8)
                    {
                        int tmp = 0;
                        for (int j = 7; j >= 0; j--)
                            tmp = (tmp << 1) | bit[i + j];
                        if (tmp == 0) break;
                        output.Text += (char)tmp;
                    }
                }
            }
            else
                send.Text = "011111100000000001111110";
            rec.Clear();
        }

    }
}
