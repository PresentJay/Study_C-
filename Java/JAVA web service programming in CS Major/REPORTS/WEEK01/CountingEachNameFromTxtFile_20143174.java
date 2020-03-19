package REPORTS.WEEK01;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class CountingEachNameFromTxtFile_20143174 {

    public static void main(String[] args) {
        try {

            System.out.println(new File(".").getAbsolutePath());

            // Create a File Object (from java.io.File)
            File f = new File("info.txt");
            // Create a Input-Stream (from java.io.FileReader)
            FileReader r = new FileReader(f);

            int line = 0;
            while ((line = r.read()) != -1) {
                System.out.println((char) line);
            }
            r.close();
        } catch (FileNotFoundException e) {
            System.out.println("file not found.");
            e.getStackTrace();
        } catch (IOException e) {
            System.out.println("Infut/Outfut error.");
            e.getStackTrace();
        }
    }

}