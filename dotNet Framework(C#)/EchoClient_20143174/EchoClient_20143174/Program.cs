using System;
using System.Text;
using System.Net.Sockets;

namespace EchoClient_20143174
{
    class Program
    {
        static string _strHostName = "127.0.0.1";
        public static int _svrPort = 9000;
        static void Main(string[] args)
        {
            TcpClient tclient = null;
            NetworkStream ns = null;
            string send_str;
            byte[] recev = new byte[513];
            Console.WriteLine("Client Program");
            try
            {
                tclient = new TcpClient(_strHostName, _svrPort);
                while (true)
                {
                    Console.WriteLine("소켓이 연결되었습니다.");
                    ns = tclient.GetStream();
                    Console.Write("보낼 데이터 : ");
                    send_str = Console.ReadLine();
                    if (send_str == null)
                        break;

                    Byte[] sendbyte = Encoding.GetEncoding("ks_c_5601-1987").GetBytes(send_str);
//                    Byte[] sendbyte = Encoding.ASCII.GetBytes(send_str);

                    if (tclient == null)
                    ns.Write(sendbyte, 0, sendbyte.Length);
                    Console.WriteLine("[TCP Client] {0}바이트를 보냈습니다.", sendbyte.Length);

                    int recvbyte = ns.Read(recev, 0, recev.Length);
                    if (recvbyte == -1)
                    {
                        Console.WriteLine("메세지 받기 실패");
                        break;
                    }
                    string recvstr = Encoding.GetEncoding("ks_c_5601-1987").GetString(recev, 0, recvbyte);
                    //string recvstr = Encoding.ASCII.GetString(recev, 0, recvbyte);
                    Console.WriteLine("[TCP Client] {0}바이트를 받았습니다.", recvbyte);
                    Console.WriteLine("다시 받은 데이터 : {0}", recvstr);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception Thrown: " + ex.ToString());
            }
            finally
            {
                tclient.Close();
            }
        }
    }
}
