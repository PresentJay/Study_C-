using System;
using System.IO;
using System.Text;
using System.Data;
using System.Net.Sockets;
using System.Net;
using System.Threading;

namespace EchoServer_20143174
{
    class Program
    {
        static public Thread tServer;
        static void Main(string[] args)
        {
            string IP = "127.0.0.1";
            int PORT = 9000;

            TcpListener _server = null;
            TcpClient tc = null;
            byte[] recevbyte = new byte[513];
            NetworkStream ns = null;
            Socket clientsocket = null;
            Encoding encode = System.Text.Encoding.GetEncoding("ks_c_5601-1987");

            try
            {
                _server = new TcpListener(IPAddress.Parse(IP), PORT);
                Console.WriteLine("{0}:{1}에 서버를 개설하였습니다.", IP, PORT);
                _server.Start();

                while (true)
                {
                    tc = _server.AcceptTcpClient();
                    Console.Write("Thread {0} Start", Thread.CurrentThread.ManagedThreadId);
                    tServer = new Thread(new ThreadStart(ThreadServer));
                    tServer.Start();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Exception :" + ex);
            }
            finally
            {
                _server.Stop();
            }

            void ThreadServer()
            {
                try
                {
                    while (true)
                    {
                        clientsocket = tc.Client;
                        ns = new NetworkStream(clientsocket);

                        string address = clientsocket.RemoteEndPoint.ToString();
                        string[] array = address.Split(new char[] { ':' });

                        Console.WriteLine("[TCP Server] Client 접속 : IP Address = {0}, PortNumber = {1}", array[0], array[1]);

                        if (tc.Connected)
                        {
                            ns = new NetworkStream(clientsocket);
                            while (true)
                            {
                                int bytes = ns.Read(recevbyte, 0, recevbyte.Length);
                                string strbyte = encode.GetString(recevbyte, 0, bytes);
                                Console.WriteLine("TCP : {0}", strbyte);
                                ns.Write(recevbyte, 0, bytes);
                            }
                        }
                    }
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.ToString());
                }
                finally
                {
                    clientsocket.Close();
                }
            }
        }
    }
}