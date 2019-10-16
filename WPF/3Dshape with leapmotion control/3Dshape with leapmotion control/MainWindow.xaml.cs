using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.Media3D;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _3Dshape_with_leapmotion_control
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            DiffuseMain.Color = Color.FromRgb(ColorBrush.Color.R, ColorBrush.Color.G, ColorBrush.Color.B);
            GradColor.Color = Color.FromRgb(ColorBrush.Color.R, ColorBrush.Color.G, ColorBrush.Color.B);
        }

        private void Light_TextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                light.Direction = new Vector3D(Convert.ToDouble(lightX_TB.Text), Convert.ToDouble(lightY_TB.Text), Convert.ToDouble(lightZ_TB.Text));
            }
            catch { }
        }

        private void YSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            rotate.Axis = new Vector3D(1.0, 0.0, 0.0);
        }

        private void ZSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            rotate.Axis = new Vector3D(0.0, 0.0, 1.0);
        }

        private void XSlider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            rotate.Axis = new Vector3D(0.0, 1.0, 0.0);
        }
    }
}
