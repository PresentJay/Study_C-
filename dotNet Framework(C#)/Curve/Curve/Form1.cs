using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Collections;

namespace Curve
{

    public partial class Form1 : Form
    {
        private LinkedList<CMyData> total_lines;
        CMyData data;
        private int x, y;
        private int iCurrentWidth;

        public Form1()
        {
            total_lines = new LinkedList<CMyData>();
            InitializeComponent();
        }

		private void Form1_MouseDown(object sender, MouseEventArgs e)
		{
            Random random = new Random();
			if (e.Button == MouseButtons.Left)
			{
                //생성자 선언
                data = new CMyData();
                //색깔 굵기 랜덤값
                data.Color = Color.FromArgb(random.Next(256), random.Next(256), random.Next(256));
                data.Width = iCurrentWidth;
                x = e.X;
                y = e.Y;
                data.AR.Add(new Point(x, y));
			}
		}

		private void Form1_MouseMove(object sender, MouseEventArgs e)
		{
            if (Capture && e.Button == MouseButtons.Left)
            {
                Graphics G = CreateGraphics();
                //펜 설정하기(색깔과 굵기) 
                Pen p = new Pen(data.Color, data.Width);
                G.DrawLine(p, x, y, e.X, e.Y);
                //누루고 있을때 계속 위치 저장
                x = e.X;
                y = e.Y;
                data.AR.Add(new Point(x, y));
                G.Dispose();
            }
		}
        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            total_lines.AddLast(data);
            //this.Invalidate();
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            foreach (CMyData line in total_lines)
            {
                //설정 후 그리기
                Pen p = new Pen(line.Color, line.Width);
                for (int i = 1; i < line.AR.Count; i++) //count가 총 갯수
                {
                    e.Graphics.DrawLine(p, (Point)line.AR[i - 1], (Point)line.AR[i]);
                }
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            iCurrentWidth = 2;
        }

        private void 대화상자ToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            Form2 dlg = new Form2();
            dlg.iWidth = iCurrentWidth;
            if (dlg.ShowDialog() == DialogResult.OK)
            {
                iCurrentWidth = dlg.iWidth;
            }
            dlg.Dispose(); //쓰레기 처리
        }
       
	}
    class CMyData
    {
        private ArrayList Ar;

        public CMyData()  //생성자함수
        {
            Ar = new ArrayList();
        }
        public Color Color
        {
            get;
            set;
        }
        public int Width
        {
            get;
            set;
        }
        public ArrayList AR
        {
            get { return Ar; }
        }
    }
}
