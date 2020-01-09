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
    public partial class Form2 : Form
    {
        public Image Main_Image { get; set; }

        public Form2() { InitializeComponent(); }
        public void setting(int w, int h, Form1 p, Image i){
            SetBounds(0, 0, w, h);
            MdiParent = p;     // 부모관계 설정
            Main_Image = i;             // Form2의 image속성 setter
            Show();
        }


        private void Form2_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawImage(Main_Image,0,0);
        }
    }
}
