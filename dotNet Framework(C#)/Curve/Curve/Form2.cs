using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Curve
{
    public partial class Form2 : Form
    {
        private int iDialogWidth;

        public int iWidth
        {
            get { return (listBox1.SelectedIndex + 1) * 2; }
            set
            {
                iDialogWidth = value;
                listBox1.SelectedIndex = iDialogWidth / 2 - 1;
            }
        }
        public Form2()
        {
            InitializeComponent();
    
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            listBox1.Items.Add("2");
            listBox1.Items.Add("4");
            listBox1.Items.Add("6");
            listBox1.Items.Add("8");
        }

    }
}
