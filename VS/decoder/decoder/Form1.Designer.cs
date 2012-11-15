namespace decoder
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
            this.rec = new System.Windows.Forms.TextBox();
            this.b_check = new System.Windows.Forms.Button();
            this.send = new System.Windows.Forms.TextBox();
            this.output = new System.Windows.Forms.RichTextBox();
            this.b_clear = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // rec
            // 
            this.rec.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.rec.Location = new System.Drawing.Point(12, 12);
            this.rec.Name = "rec";
            this.rec.Size = new System.Drawing.Size(752, 23);
            this.rec.TabIndex = 0;
            // 
            // b_check
            // 
            this.b_check.Location = new System.Drawing.Point(648, 41);
            this.b_check.Name = "b_check";
            this.b_check.Size = new System.Drawing.Size(116, 27);
            this.b_check.TabIndex = 1;
            this.b_check.Text = "check";
            this.b_check.UseVisualStyleBackColor = true;
            this.b_check.Click += new System.EventHandler(this.b_check_Click);
            // 
            // send
            // 
            this.send.Font = new System.Drawing.Font("宋体", 10.5F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.send.Location = new System.Drawing.Point(12, 74);
            this.send.Name = "send";
            this.send.Size = new System.Drawing.Size(752, 23);
            this.send.TabIndex = 2;
            // 
            // output
            // 
            this.output.Location = new System.Drawing.Point(13, 103);
            this.output.Name = "output";
            this.output.Size = new System.Drawing.Size(751, 134);
            this.output.TabIndex = 3;
            this.output.Text = "";
            // 
            // b_clear
            // 
            this.b_clear.Location = new System.Drawing.Point(12, 41);
            this.b_clear.Name = "b_clear";
            this.b_clear.Size = new System.Drawing.Size(116, 27);
            this.b_clear.TabIndex = 4;
            this.b_clear.Text = "clear";
            this.b_clear.UseVisualStyleBackColor = true;
            this.b_clear.Click += new System.EventHandler(this.b_clear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(776, 250);
            this.Controls.Add(this.b_clear);
            this.Controls.Add(this.output);
            this.Controls.Add(this.send);
            this.Controls.Add(this.b_check);
            this.Controls.Add(this.rec);
            this.Name = "Form1";
            this.Text = "Decoder";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox rec;
        private System.Windows.Forms.Button b_check;
        private System.Windows.Forms.TextBox send;
        private System.Windows.Forms.RichTextBox output;
        private System.Windows.Forms.Button b_clear;
    }
}

