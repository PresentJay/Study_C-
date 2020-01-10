using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.Threading;

namespace _190530_TcpServerExWinForm
{
    public partial class Form1 : Form
    {
        // 폼 전역 요소 선언부 - - - - - - - - - - - - - - - - - - - -
        private delegate void SafeCallDelegate(string text);
        TcpListener listener;     
        TcpClient client; 
        Thread t1;
        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)  // 버튼 토글식 알고리즘
        {

            if (button1.Text.Equals("열기"))  // #1. SERVER ON------------------------
            {
                int port = int.Parse(textBox2.Text);  // 포트번호를 저장
                t1 = new Thread(new ParameterizedThreadStart(waitForClient)); 
                // t1 전역 스레드변수에 waitForClient기능을 담은 새 (인수전달가능)스레드 객체 할당
                t1.Start(port); // t1 전역스레드 시작 (배경스레드)

                button1.Text = "닫기"; // 버튼 토글
            }
            //--------------------------------------------------------------------------

            else if (button1.Text.Equals("닫기")) // #2. SERVER QUIT-----------------
            {
                button1.Text = "열기"; // 버튼 토글
                listener.Stop();             // 전역 리스너 수신 중단(#END)
                t1.Abort();                   // t1 전역스레드 종료 (배경스레드)
            }
            //--------------------------------------------------------------------------
        }

        private void waitForClient(Object o)    // 배경 스레드 method    [#서버 본체]
        {
            Thread t;    // 서버 구성단에서 작동하는 지역 스레드 t 선언

            int port = (int)o;   // 포트번호 단일인자로 받아, 값 배치
            listener = new TcpListener(IPAddress.Any, port); 
            // 전역 리스너에 새로운 (모든 IP를 받는, 포트번호)의 TcpListener 객체 할당
            client = new TcpClient();
            // 전역 클라이언트에 새로운 TcpClient 객체 할당
            listener.Start();  // 전역 리스너 수신 시작(#START)
            listBox1AccessInThread("[TCP 서버] 서버가 시작되었습니다.");

            try 
            {
                while (true)  // [#서버 스레드 핵심내용]
                {
                    client = listener.AcceptTcpClient();
                    // 전역 TcpClient 객체의 상태를,  전역 TcpListener 객체의 수신상태로 변경
                    //  ------- 연결 입력까지 System Blocked --------

                    if (client.Connected)  // 연결 입력 감지(Block해제) 이후, 전역 TcpClient 객체의 Socket이 연결된 상태인 경우
                    {
                        t = new Thread(new ParameterizedThreadStart(threadedWorks));
                        // t 서버 지역스레드변수에 threadedWorks기능을 담은 새 (인수전달가능)스레드 객체 할당
                        t.Start(client);  // t 지역스레드 시작
                    }
                    else // 연결 입력 감지(Block해제) 이후, 전역 TcpClient 객체의 Socket이 연결되지 않은 상태인 경우
                    {
                        listBox1AccessInThread("이전에 소켓이 연결되지 않았습니다. ");
                        break;    // [#서버 스레드 활동 중지]
                    }
                }
            }
            catch (Exception ex)    // 서버 Exception 발생시 Catch
            {
                listBox1AccessInThread("Except Thrown: " + ex.ToString());
                listBox1AccessInThread("[TCP 서버] 서버가 닫혔습니다.");
            }
            finally  // 서버 Exception의 발생 여부와 상관 없이, 스레드 종료단 실행부
            {
                client.Close(); //전역 TcpClient 객체를 삭제하고, 내부 TCP 연결 해제
            }
        }

        private void threadedWorks(Object o) //  지역 스레드 method   [#연결된 Client 1:1 관리]
        {
            TcpClient tclient = (TcpClient)o;   // 지역 TcpClient인 tclient 변수에, 인수로 전달된 객체(서버 스레드에서 Accept되고, Connect된 TcpClient)를 배치
            Socket s = tclient.Client;              // 지역 Socket인 s 변수에, tclient 객체의 내부 Socket을 배치
            string address = s.RemoteEndPoint.ToString();    // address(주소)는 소켓 끝점의 "IP주소:포트번호"형식으로 전달된 것을 String형태로 할당한 변수
            string[] array = address.Split(new char[] { ':' });     // address를 IP주소와 포트번호, 두 가지로 나누는 array 변수
            byte[] recevbyte = new byte[513];                       
            NetworkStream ns = tclient.GetStream();         // NetworkStream 형태의 ns 변수에, tclient의 NetworkStream을 배치
            Encoding ASCII = Encoding.ASCII;                   // ASCII 인코딩 준비

            listBox1AccessInThread("[TCP 서버] 클라이언트 접속 : IP 주소 = " + array[0] + " 포트번호 = " + array[1]);

            while (true)    // [#연결된 Client 1:1 관리 핵심 내용]
            {
                try
                {
                    int bytes = ns.Read(recevbyte, 0, recevbyte.Length);   // ns에 바이트가 남아있다면, 512바이트 단위로 na로부터 Data Read (데이터 실제값이 int형으로 나열, 저장)
                    String strbyte = ASCII.GetString(recevbyte, 0, bytes);  // String 변수에, 읽어들인 recevbyte를 ASCII형으로 변환하여 배치

                    if (bytes == 0) // ns의 모든 바이트를 읽어들여,  null byte 상태가 되었다면
                    {
                        ns.Write(recevbyte, 0, bytes);  //?

                        // [#Client 연결 해제]
                        listBox1AccessInThread("[TCP 서버] 클라이언트 연결 해제 : IP 주소 = " + array[0] + " 포트번호 = " + array[1]); 
                        break;  
                        //
                    }
                    else
                    {
                        listBox1AccessInThread("[TCP/" + array[0] + ":" + array[1] + "] " + strbyte);
                        ns.Write(recevbyte, 0, bytes);  //Echo
                       // ns.Write(ASCII.GetBytes("Echo전송") , 0 , "Echo전송".Length);
                    }
                }
                catch (Exception ex)  // Exception catch시 Client 연결 해제
                {
                    listBox1AccessInThread("[TCP 서버] 클라이언트 연결 해제 : IP 주소 = " + array[0] + " 포트번호 = " + array[1]);
                    ex.ToString(); //오류발생 처리 획득 형식적으로만..
                    break;
                }
            }
            tclient.Close();
        }

        //멀티스레드 충돌관리
        public void listBox1AccessInThread(string text)
        {
            if (listBox1.InvokeRequired)
            {
                SafeCallDelegate d = new SafeCallDelegate(listBox1AccessInThread);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                listBox1.Items.Add(text);
            }
        }
        //

    }
}
