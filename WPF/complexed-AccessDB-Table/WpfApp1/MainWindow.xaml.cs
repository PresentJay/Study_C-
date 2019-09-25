using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using System.Data.OleDb;

namespace WpfApp1
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

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            string sql;

            string source = @"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=C:\Temp\영화.mdb";
            OleDbConnection conn = new OleDbConnection(source);
            conn.Open();

            sql = "Select * FROM 영화";

            OleDbCommand cmd = new OleDbCommand(sql, conn);
            cmd.CommandText = sql;
            OleDbDataReader reader = cmd.ExecuteReader();

            while (reader.Read())
            {
                //string item = "";
                //영화테이블에 등록되어 있는 경우

                name.Text += reader["영화명"].ToString() + "\n";
                direct.Text += reader["감독"].ToString() + "\n";
                main.Text += reader["주연"].ToString() + "\n";
                jang.Text += reader["장르"].ToString() + "\n";
                since.Text += reader["제작연도"].ToString() + "\n";
            }

            reader.Close();
            conn.Close();
        }
    }
}
