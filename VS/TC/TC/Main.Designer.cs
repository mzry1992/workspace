namespace TC
{
    partial class Main
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
            this.MainView = new System.Windows.Forms.TabControl();
            this.StatusView = new System.Windows.Forms.StatusStrip();
            this.I = new System.Windows.Forms.ToolStripStatusLabel();
            this.StatusView.SuspendLayout();
            this.SuspendLayout();
            // 
            // MainView
            // 
            this.MainView.Location = new System.Drawing.Point(7, 7);
            this.MainView.Name = "MainView";
            this.MainView.Padding = new System.Drawing.Point(0, 0);
            this.MainView.SelectedIndex = 0;
            this.MainView.Size = new System.Drawing.Size(518, 258);
            this.MainView.TabIndex = 0;
            // 
            // StatusView
            // 
            this.StatusView.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.I});
            this.StatusView.Location = new System.Drawing.Point(0, 268);
            this.StatusView.Name = "StatusView";
            this.StatusView.Size = new System.Drawing.Size(530, 22);
            this.StatusView.TabIndex = 1;
            this.StatusView.Text = "StatusView";
            this.StatusView.ItemClicked += new System.Windows.Forms.ToolStripItemClickedEventHandler(this.StatusView_ItemClicked);
            // 
            // I
            // 
            this.I.Name = "I";
            this.I.Size = new System.Drawing.Size(0, 17);
            // 
            // Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(530, 290);
            this.Controls.Add(this.StatusView);
            this.Controls.Add(this.MainView);
            this.MinimumSize = new System.Drawing.Size(300, 300);
            this.Name = "Main";
            this.Text = "TC";
            this.Load += new System.EventHandler(this.Main_Load);
            this.Resize += new System.EventHandler(this.Main_Resize);
            this.StatusView.ResumeLayout(false);
            this.StatusView.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        public System.Windows.Forms.TabControl MainView;
        public System.Windows.Forms.StatusStrip StatusView;
        public System.Windows.Forms.ToolStripStatusLabel I;


    }
}

