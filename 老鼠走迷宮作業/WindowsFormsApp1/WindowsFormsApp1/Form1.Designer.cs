namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// 設計工具所需的變數。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清除任何使用中的資源。
        /// </summary>
        /// <param name="disposing">如果應該處置受控資源則為 true，否則為 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 設計工具產生的程式碼

        /// <summary>
        /// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
        /// 這個方法的內容。
        /// </summary>
        private void InitializeComponent()
        {
            this.LbSize = new System.Windows.Forms.Label();
            this.SizeChooser = new System.Windows.Forms.NumericUpDown();
            this.Btnstart = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.RowChooser = new System.Windows.Forms.NumericUpDown();
            this.ColumnChooser = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.SizeChooser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.RowChooser)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ColumnChooser)).BeginInit();
            this.SuspendLayout();
            // 
            // LbSize
            // 
            this.LbSize.AutoSize = true;
            this.LbSize.Font = new System.Drawing.Font("新細明體", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.LbSize.Location = new System.Drawing.Point(82, 213);
            this.LbSize.Name = "LbSize";
            this.LbSize.Size = new System.Drawing.Size(45, 24);
            this.LbSize.TabIndex = 0;
            this.LbSize.Text = "size";
            // 
            // SizeChooser
            // 
            this.SizeChooser.Location = new System.Drawing.Point(206, 217);
            this.SizeChooser.Name = "SizeChooser";
            this.SizeChooser.Size = new System.Drawing.Size(120, 25);
            this.SizeChooser.TabIndex = 3;
            // 
            // Btnstart
            // 
            this.Btnstart.Font = new System.Drawing.Font("新細明體", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.Btnstart.Location = new System.Drawing.Point(86, 287);
            this.Btnstart.Name = "Btnstart";
            this.Btnstart.Size = new System.Drawing.Size(240, 105);
            this.Btnstart.TabIndex = 4;
            this.Btnstart.Text = "start";
            this.Btnstart.UseVisualStyleBackColor = true;
            this.Btnstart.Click += new System.EventHandler(this.Btnstart_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("新細明體", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label1.Location = new System.Drawing.Point(452, 28);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(238, 144);
            this.label1.TabIndex = 5;
            this.label1.Text = "changeroad rule:\r\nO(road),X(block),#(step)\r\no=>x\r\nx=>o\r\n#=>x\r\n\r\n";
            // 
            // RowChooser
            // 
            this.RowChooser.Location = new System.Drawing.Point(567, 161);
            this.RowChooser.Name = "RowChooser";
            this.RowChooser.Size = new System.Drawing.Size(120, 25);
            this.RowChooser.TabIndex = 6;
            // 
            // ColumnChooser
            // 
            this.ColumnChooser.Location = new System.Drawing.Point(567, 222);
            this.ColumnChooser.Name = "ColumnChooser";
            this.ColumnChooser.Size = new System.Drawing.Size(120, 25);
            this.ColumnChooser.TabIndex = 7;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("新細明體", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label2.Location = new System.Drawing.Point(452, 157);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(45, 24);
            this.label2.TabIndex = 8;
            this.label2.Text = "row";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("新細明體", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.label3.Location = new System.Drawing.Point(452, 218);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 24);
            this.label3.TabIndex = 9;
            this.label3.Text = "column";
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("新細明體", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(136)));
            this.button1.Location = new System.Drawing.Point(447, 287);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(240, 105);
            this.button1.TabIndex = 10;
            this.button1.Text = "change and walk";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.ColumnChooser);
            this.Controls.Add(this.RowChooser);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Btnstart);
            this.Controls.Add(this.SizeChooser);
            this.Controls.Add(this.LbSize);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.SizeChooser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.RowChooser)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ColumnChooser)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label LbSize;
        private System.Windows.Forms.NumericUpDown SizeChooser;
        private System.Windows.Forms.Button Btnstart;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown RowChooser;
        private System.Windows.Forms.NumericUpDown ColumnChooser;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button button1;
    }
}

