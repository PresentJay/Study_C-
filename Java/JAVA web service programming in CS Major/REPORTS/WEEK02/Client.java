package REPORTS.WEEK02;

import java.net.*;
import java.io.*;

public class Client {
    public static void main(String args[]) throws Exception {

        Socket socket = new Socket("localhost", 1000);

        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            String str = "";

            while ((str = in.readLine()) != null)
                System.out.println(str);

            socket.close();
        } catch (IOException e) {
            System.out.println("Client : Input/Output error.");
            e.getStackTrace();
        }
    }
}
