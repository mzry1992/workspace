namespace TC
{
    partial class tabProblemSet
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.ContestView = new System.Windows.Forms.ListBox();
            this.ContestViewMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.刷新ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.UpdataInfo = new System.Windows.Forms.Timer(this.components);
            this.ContestViewMenu.SuspendLayout();
            this.SuspendLayout();
            // 
            // ContestView
            // 
            this.ContestView.ContextMenuStrip = this.ContestViewMenu;
            this.ContestView.FormattingEnabled = true;
            this.ContestView.ItemHeight = 12;
            this.ContestView.Location = new System.Drawing.Point(7, 7);
            this.ContestView.Name = "ContestView";
            this.ContestView.Size = new System.Drawing.Size(516, 256);
            this.ContestView.TabIndex = 0;
            // 
            // ContestViewMenu
            // 
            this.ContestViewMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.刷新ToolStripMenuItem});
            this.ContestViewMenu.Name = "ContestViewMenu";
            this.ContestViewMenu.Size = new System.Drawing.Size(95, 26);
            // 
            // 刷新ToolStripMenuItem
            // 
            this.刷新ToolStripMenuItem.Name = "刷新ToolStripMenuItem";
            this.刷新ToolStripMenuItem.Size = new System.Drawing.Size(94, 22);
            this.刷新ToolStripMenuItem.Text = "刷新";
            this.刷新ToolStripMenuItem.Click += new System.EventHandler(this.刷新ToolStripMenuItem_Click);
            // 
            // UpdataInfo
            // 
            this.UpdataInfo.Enabled = true;
            this.UpdataInfo.Interval = 1000;
            this.UpdataInfo.Tick += new System.EventHandler(this.UpdataInfo_Tick);
            // 
            // tabProblemSet
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(526, 266);
            this.Controls.Add(this.ContestView);
            this.Name = "tabProblemSet";
            this.Text = "tabProblemSet";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.tabProblemSet_FormClosed);
            this.Load += new System.EventHandler(this.tabProblemSet_Load);
            this.SizeChanged += new System.EventHandler(this.tabProblemSet_SizeChanged);
            this.ContestViewMenu.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox ContestView;
        private System.Windows.Forms.ContextMenuStrip ContestViewMenu;
        private System.Windows.Forms.ToolStripMenuItem 刷新ToolStripMenuItem;
        private System.Windows.Forms.Timer UpdataInfo;


    }
}