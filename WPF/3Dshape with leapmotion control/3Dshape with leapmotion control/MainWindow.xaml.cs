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
            //        Model3DGroup cube = new Model3DGroup();
            //        Point3D p0 = new Point3D(0, 0, 0);
            //        Point3D p1 = new Point3D(5, 0, 0);
            //        Point3D p2 = new Point3D(5, 0, 5);
            //        Point3D p3 = new Point3D(0, 0, 5);
            //        Point3D p4 = new Point3D(0, 5, 0);
            //        Point3D p5 = new Point3D(5, 5, 0);
            //        Point3D p6 = new Point3D(5, 5, 5);
            //        Point3D p7 = new Point3D(0, 5, 5);
            //        //front side triangles
            //        cube.Children.Add(CreateTriangleModel(p3, p2, p6));
            //        cube.Children.Add(CreateTriangleModel(p3, p6, p7));

            //        //right side triangles
            //        cube.Children.Add(CreateTriangleModel(p2, p1, p5));
            //        cube.Children.Add(CreateTriangleModel(p2, p5, p6));

            //        //back side triangles
            //        cube.Children.Add(CreateTriangleModel(p1, p0, p4));
            //        cube.Children.Add(CreateTriangleModel(p1, p4, p5));

            //        //left side triangles
            //        cube.Children.Add(CreateTriangleModel(p0, p3, p7));
            //        cube.Children.Add(CreateTriangleModel(p0, p7, p4));

            //        //top side triangles
            //        cube.Children.Add(CreateTriangleModel(p7, p6, p5));
            //        cube.Children.Add(CreateTriangleModel(p7, p5, p4));

            //        //bottom side triangles
            //        cube.Children.Add(CreateTriangleModel(p2, p3, p0));
            //        cube.Children.Add(CreateTriangleModel(p2, p0, p1));

            //        ModelVisual3D model = new ModelVisual3D();
            //        model.Content = cube;
            //        this.mainViewport.Children.Add(model);
            //    }

            //    private Model3DGroup CreateTriangleModel(Point3D p0, Point3D p1, Point3D p2)
            //    {
            //        MeshGeometry3D mesh = new MeshGeometry3D();
            //        mesh.Positions.Add(p0);
            //        mesh.Positions.Add(p1);
            //        mesh.Positions.Add(p2);
            //        mesh.TriangleIndices.Add(0);
            //        mesh.TriangleIndices.Add(1);
            //        mesh.TriangleIndices.Add(2);
            //        Vector3D normal = CalculateNormal(p0, p1, p2);
            //        mesh.Normals.Add(normal);
            //        mesh.Normals.Add(normal);
            //        mesh.Normals.Add(normal);
            //        Material material = new DiffuseMaterial(new SolidColorBrush(Color.FromRgb((byte)colorSet[0], (byte)colorSet[1], (byte)colorSet[2])));
            //        GeometryModel3D model = new GeometryModel3D(mesh, material);
            //        Model3DGroup group = new Model3DGroup(); group.Children.Add(model);
            //        return group;
            //    }

            //    private Vector3D CalculateNormal(Point3D p0, Point3D p1, Point3D p2)
            //    {
            //        Vector3D v0 = new Vector3D(p1.X - p0.X, p1.Y - p0.Y, p1.Z - p0.Z);
            //        Vector3D v1 = new Vector3D(p2.X - p1.X, p2.Y - p1.Y, p2.Z - p1.Z);
            //        return Vector3D.CrossProduct(v0, v1);
            //    }


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
