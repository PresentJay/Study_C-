using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ImageProcessing
{
    public partial class Form1 : Form
    {
        public Form1() { InitializeComponent(); IsMdiContainer = true; }

        private void 열기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // 이미지 파일 다이얼로그로 확인해서 가져오기
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                Image I = Image.FromFile(openFileDialog1.FileName);
                Form2 Child = new Form2();
                Child.setting(I.Width, I.Height, this, I);
            }
            //
        }

        //닫기 구현하기
        private void 닫기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form Child = (Form2)this.ActiveMdiChild;    //현재 활성화된 Mdi Child 선택
            if (Child != null)  // 선택된 게 있다면
                Child.Close();  // 제거
        }

        private void 밝게하기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 Child = (Form2)this.ActiveMdiChild;   //현재 활성화된 Mdi Child 선택

            if (Child != null)
            {
                Form2 New = new Form2();
                Bitmap B = new Bitmap(Child.Main_Image);    // Child의 Image파일과 같은 Bitmap B 생성
                for (int y = 0; y < B.Height; y++)
                    for (int x = 0; x < B.Width; x++)
                    {
                        Color color = B.GetPixel(x, y);

                        int r = color.R + 50; if (r > 255) r = 255;
                        int g = color.G + 50; if (g > 255) g = 255;
                        int b = color.B + 50; if (b > 255) b = 255;
                        B.SetPixel(x, y, Color.FromArgb(r, g, b));
                    }
                New.setting(B.Width, B.Height, this, B);
            }
        }

        private void 어둡게하기ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 Child = (Form2)this.ActiveMdiChild;

            if (Child != null)
            {
                Form2 New = new Form2();
                Bitmap B = new Bitmap(Child.Main_Image);
                for (int y = 0; y < B.Height; y++)
                    for (int x = 0; x < B.Width; x++) {
                        Color color = B.GetPixel(x, y);
                        int r = color.R - 50; if (r < 0) r = 0;
                        int g = color.G - 50; if (g < 0) g = 0;
                        int b = color.B - 50; if (b < 0) b = 0;
                        B.SetPixel(x, y, Color.FromArgb(r, g, b));
                    }
                New.setting(B.Width, B.Height, this, B);
            }
        }

        private void 흑백ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 Child = (Form2)this.ActiveMdiChild;
            if (Child != null)   {
                Form2 New = new Form2();
                Bitmap B = new Bitmap(Child.Main_Image);
                for (int y = 0; y < B.Height; y++)
                    for (int x = 0; x < B.Width; x++)
                    {
                        Color color = B.GetPixel(x, y);
                        int point = (color.R + color.G + color.B) / 3;
                        if (point > 255) point = 255;
                        B.SetPixel(x, y, Color.FromArgb(point, point, point));
                    }
                New.setting(B.Width, B.Height, this, B);
            }
        }
    }
}
