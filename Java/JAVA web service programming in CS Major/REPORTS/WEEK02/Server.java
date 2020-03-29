package REPORTS.WEEK02;

import java.net.*;
import java.io.*;

public class Server {
    public static void main(String args[]) throws Exception {

        // 서버소켓 생성
        ServerSocket serverSocket = new ServerSocket(1000);
        // 접속 대기
        Socket socket = serverSocket.accept();
        // filepath 변수는 info.txt 파일의 경로를 지정하는 변수입니다. (기존 주어진 형태는 "info.txt")
        // 과제 작성을 visual studio code의 java compile extension으로 진행하여서,
        // 프로젝트 폴더가 임시로 구성되는 설정 때문에 파일의 상대위치를 지정할 수 없었습니다.
        String filepath = "REPORTS/WEEK02/info.txt";

        try {
            // Client로부터 데이터를 읽어들이기 위한 스트림
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(filepath)));
            // Client로 데이터를 내보내기 위한 스트림
            PrintStream out = new PrintStream(socket.getOutputStream());

            // Client로부터 데이터를 받았을 때 이용하는 구간
            String str = "";
            while ((str = in.readLine()) != null)
                out.println(str);

            // 메모리 누수방지를 위해 사용한 오브젝트들을 close해줍니다.
            socket.close();
            serverSocket.close();
            in.close();
        } catch (FileNotFoundException e) {
            System.out.println("file not found.");
            e.getStackTrace();
        } catch (IOException e) {
            System.out.println("Server : Input/Output error.");
            e.getStackTrace();
        }
    }
}