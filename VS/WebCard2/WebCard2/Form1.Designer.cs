namespace WebCard2
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.t_pwd1 = new System.Windows.Forms.TextBox();
            this.t_pwd2 = new System.Windows.Forms.TextBox();
            this.t_pwd3 = new System.Windows.Forms.TextBox();
            this.b_ok = new System.Windows.Forms.Button();
            this.b_clear = new System.Windows.Forms.Button();
            this.b_quit = new System.Windows.Forms.Button();
            this.t_res3 = new System.Windows.Forms.TextBox();
            this.t_res2 = new System.Windows.Forms.TextBox();
            this.t_res1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // t_pwd1
            // 
            this.t_pwd1.Font = new System.Drawing.Font("微软雅黑", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.t_pwd1.Location = new System.Drawing.Point(12, 12);
            this.t_pwd1.Name = "t_pwd1";
            this.t_pwd1.Size = new System.Drawing.Size(77, 81);
            this.t_pwd1.TabIndex = 0;
            // 
            // t_pwd2
            // 
            this.t_pwd2.Font = new System.Drawing.Font("微软雅黑", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.t_pwd2.Location = new System.Drawing.Point(95, 12);
            this.t_pwd2.Name = "t_pwd2";
            this.t_pwd2.Size = new System.Drawing.Size(77, 81);
            this.t_pwd2.TabIndex = 1;
            // 
            // t_pwd3
            // 
            this.t_pwd3.Font = new System.Drawing.Font("微软雅黑", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.t_pwd3.Location = new System.Drawing.Point(178, 12);
            this.t_pwd3.Name = "t_pwd3";
            this.t_pwd3.Size = new System.Drawing.Size(77, 81);
            this.t_pwd3.TabIndex = 2;
            // 
            // b_ok
            // 
            this.b_ok.Location = new System.Drawing.Point(12, 99);
            this.b_ok.Name = "b_ok";
            this.b_ok.Size = new System.Drawing.Size(77, 34);
            this.b_ok.TabIndex = 3;
            this.b_ok.Text = "OK";
            this.b_ok.UseVisualStyleBackColor = true;
            this.b_ok.Click += new System.EventHandler(this.b_ok_Click);
            // 
            // b_clear
            // 
            this.b_clear.Location = new System.Drawing.Point(95, 99);
            this.b_clear.Name = "b_clear";
            this.b_clear.Size = new System.Drawing.Size(77, 34);
            this.b_clear.TabIndex = 4;
            this.b_clear.Text = "Clear";
            this.b_clear.UseVisualStyleBackColor = true;
            this.b_clear.Click += new System.EventHandler(this.b_clear_Click);
            // 
            // b_quit
            // 
            this.b_quit.Location = new System.Drawing.Point(178, 99);
            this.b_quit.Name = "b_quit";
            this.b_quit.Size = new System.Drawing.Size(77, 34);
            this.b_quit.TabIndex = 5;
            this.b_quit.Text = "Quit";
            this.b_quit.UseVisualStyleBackColor = true;
            this.b_quit.Click += new System.EventHandler(this.b_quit_Click);
            // 
            // t_res3
            // 
            this.t_res3.Enabled = false;
            this.t_res3.Font = new System.Drawing.Font("微软雅黑", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.t_res3.Location = new System.Drawing.Point(178, 139);
            this.t_res3.Name = "t_res3";
            this.t_res3.Size = new System.Drawing.Size(77, 81);
            this.t_res3.TabIndex = 8;
            // 
            // t_res2
            // 
            this.t_res2.Enabled = false;
            this.t_res2.Font = new System.Drawing.Font("微软雅黑", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.t_res2.Location = new System.Drawing.Point(95, 139);
            this.t_res2.Name = "t_res2";
            this.t_res2.Size = new System.Drawing.Size(77, 81);
            this.t_res2.TabIndex = 7;
            // 
            // t_res1
            // 
            this.t_res1.Enabled = false;
            this.t_res1.Font = new System.Drawing.Font("微软雅黑", 42F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.t_res1.Location = new System.Drawing.Point(12, 139);
            this.t_res1.Name = "t_res1";
            this.t_res1.Size = new System.Drawing.Size(77, 81);
            this.t_res1.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(269, 231);
            this.Controls.Add(this.t_res3);
            this.Controls.Add(this.t_res2);
            this.Controls.Add(this.t_res1);
            this.Controls.Add(this.b_quit);
            this.Controls.Add(this.b_clear);
            this.Controls.Add(this.b_ok);
            this.Controls.Add(this.t_pwd3);
            this.Controls.Add(this.t_pwd2);
            this.Controls.Add(this.t_pwd1);
            this.Name = "Form1";
            this.Text = "WebCard";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox t_pwd1;
        private System.Windows.Forms.TextBox t_pwd2;
        private System.Windows.Forms.TextBox t_pwd3;
        private System.Windows.Forms.Button b_ok;
        private System.Windows.Forms.Button b_clear;
        private System.Windows.Forms.Button b_quit;
        private System.Windows.Forms.TextBox t_res3;
        private System.Windows.Forms.TextBox t_res2;
        private System.Windows.Forms.TextBox t_res1;
    }
}

