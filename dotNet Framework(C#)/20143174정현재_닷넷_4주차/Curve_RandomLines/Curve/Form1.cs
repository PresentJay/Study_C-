using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Curve
{
    public partial class Form1 : Form
	{

        // 4주차 요구된 자료구조
        class CMyData
        {
            private Color color;
            private int width;
            private ArrayList Loc;

            public CMyData()  //생성자함수
            {
                Loc = new ArrayList();
            }

            public Color Color
            {
                get { return color; }
                set { color = value; }
            }

            public int Width
            {
                get { return width; }
                set { width = value; }
            }
            public ArrayList LOC
            {
                get { return Loc; }
            }
        }
        //----

        CMyData ar;
        private LinkedList<CMyData> total_lines;
        Random R = new Random();
        bool isRandom = false;
        bool isSelectionMode = false;
        int current_Width;
        Color current_Color;

        public Form1()
        {
            total_lines = new LinkedList<CMyData>();
            InitializeComponent();
        }
		private void Form1_MouseDown(object sender, MouseEventArgs e)
		{
			if (e.Button == MouseButtons.Left)
			{
                ar = new CMyData();

                if (isRandom)
                    ar.Color = Color.FromArgb(R.Next(256), R.Next(256), R.Next(256));
                else
                    ar.Color = current_Color;

                ar.Width = current_Width;

                ar.LOC.Add(new Point(e.X, e.Y));
            }
		}

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (Capture && e.Button == MouseButtons.Left)
            {
                Graphics g = CreateGraphics();
                ar.LOC.Add(new Point(e.X, e.Y));
                g.DrawLine(new Pen(ar.Color, ar.Width), (Point)ar.LOC[ar.LOC.Count-2], (Point)ar.LOC[ar.LOC.Count-1]);
                g.Dispose();
            }
        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            if (Capture && e.Button == MouseButtons.Left)
            {
                total_lines.AddLast(ar);
            }
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            
            foreach (CMyData line in total_lines)
            {
                for (int i = 1; i < line.LOC.Count; i++)
                {
                    e.Graphics.DrawLine(new Pen(line.Color, line.Width), (Point)line.LOC[i - 1], (Point)line.LOC[i]);
                }
            }
        }

        private void settingToolStripMenuItem_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = true;
            groupBox2.Visible = true;
            button2.Visible = true;
            button3.Visible = true;
        }


        
        private void radioButton1_Click(object sender, EventArgs e)        //얇게
        {
            current_Width = 2;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)        //중간
        {
            current_Width = 10;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)        //굵게
        {
            current_Width = 20;
        }

        private void radioButton4_Click(object sender, EventArgs e)        //검정
        {
            isRandom = false;
            isSelectionMode = false;
            current_Color = Color.Black;
        }

        // 임시
        private void radioButton5_CheckedChanged(object sender, EventArgs e)        //입력 후 확인 -> 선택모드
        {
            isSelectionMode = true;

            current_Color = Color.Black;
        }
        //

        private void radioButton6_CheckedChanged(object sender, EventArgs e)        //랜덤모드
        {
            isRandom = true;
            isSelectionMode = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {

            button3.PerformClick();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            groupBox1.Visible = false;
            groupBox2.Visible = false;
            button2.Visible = false;
            button3.Visible = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            radioButton1.Checked = true;
            radioButton6.Checked = true;
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            isRandom = false;
            isSelectionMode = false;
            current_Color = Color.Black;
        }
    }
}
