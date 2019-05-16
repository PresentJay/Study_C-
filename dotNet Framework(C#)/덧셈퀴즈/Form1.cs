using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Sansu
{
    public partial class Form1 : Form
    {
        private string Str, Str2, state;
        Random R = new Random();
        int left, right;

        public Form1()
        {
            InitializeComponent();
            Str = "";
            Str2 = "";
            state = "";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Timer T = new Timer();
            T.Interval = 3000;
            T.Tick += new EventHandler(Form1_Timer);
            T.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawString(Str, this.Font, Brushes.Black, 10, 10);
            e.Graphics.DrawString(Str2, this.Font, Brushes.Black, 10, 40);
            e.Graphics.DrawString(state, this.Font, Brushes.Black, 10, 60);
        }

        private void Form1_Timer(object sender, System.EventArgs e)
        {
            DateTime dt = DateTime.Now;
            left = R.Next(10);
            right = R.Next(10);

            Str = left.ToString() + '+' + right.ToString() + '=';
            Str2 = "";
            this.Invalidate();
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == ' ')
            {
                Str2 = "";
                state = "";
            }
            else
            {
                Str2 += e.KeyChar;
                if (Str2.CompareTo((left + right).ToString()) == 0)
                    state = "정답!";
                else
                    state = "오답입니다";
            }
            this.Invalidate();
        }
    }
}
