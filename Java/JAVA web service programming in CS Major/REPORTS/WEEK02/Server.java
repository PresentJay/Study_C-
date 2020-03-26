package REPORTS.WEEK02;

import java.net.*;
import java.io.*;

public class Server {
    public static void main(String args[]) throws Exception {

        ServerSocket serverSocket = new ServerSocket(1000);
        Socket socket = serverSocket.accept();
        String filepath = "REPORTS/WEEK02/info.txt";

        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(filepath)));
            PrintStream out = new PrintStream(socket.getOutputStream());

            String str = "";

            while ((str = in.readLine()) != null)
                out.println(str);

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