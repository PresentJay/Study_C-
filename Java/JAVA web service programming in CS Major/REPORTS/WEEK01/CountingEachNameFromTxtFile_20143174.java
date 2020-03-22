package REPORTS.WEEK01;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;

// 인제대학교 컴퓨터공학부 20143174 정현재
// WEB SERVICE PROGRAMMING 1주차 과제물입니다.

// 기본적으로 객체지향 + 함수형 프로그래밍으로 구성하였습니다.

public class CountingEachNameFromTxtFile_20143174 {

    static String[] core;
    static ArrayList<String> raw = new ArrayList<String>();
    static HashMap<String, Integer> cnt = new HashMap<String, Integer>();

    public static void getData() {
        // filepath 변수는 info.txt 파일의 경로를 지정하는 변수입니다.
        // 과제 작성을 visual studio code의 java compile extension으로 진행하여서,
        // 프로젝트 폴더가 임시로 구성되는 설정 때문에 상대경로 지정에 있어 어려움을 겪었고,
        // 만약 상대경로 지정이 가능하다면 "./info.txt"로 통일하는 방식으로 효율을 높였을 것 같습니다.
        String filepath = "REPORTS/WEEK01/info.txt";
        String tmp_line = "";

        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(filepath)));
            // 스트림을 받는 버퍼를 이용해 파일을 한 번에 받는 방식을 선택했습니다.
            // tmp_line에 버퍼리더의 데이터를 넘겨줍니다.
            while ((tmp_line = in.readLine()) != null) {
                // core 변수에 버퍼리더 데이터에서 줄바꿈을 기준으로 split합니다.
                core = tmp_line.replace("|*|", " ").split(" ");
                // split된 core는 raw의 각 이름(cnt의 카운팅 기준)이 됩니다.
                for (int i = 0; i < core.length; i++)
                    if (core[i].length() != 0)
                        raw.add(core[i]);
            }
            // 버퍼리더를 닫습니다. (필수)
            in.close();
        } catch (FileNotFoundException e) {
            // 파일 경로가 변경되었는데, filepath변수가 변경되지 않았을 경우 파일을 찾지 못합니다.
            // 따라서 해당 상황에 대비한 Exception을 준비합니다.
            System.out.println("file not found.");
            e.getStackTrace();
        } catch (IOException e) {
            // input과정에서 문제가 생길 경우 trace할 수 있는 Exception을 준비합니다.
            System.out.println("Input/Output error.");
            e.getStackTrace();
        }
    }

    // raw의 이름을 세어 cnt 해쉬맵에 카운팅하는 함수입니다.
    public static void counting() {
        int tmp_cnt = 1;
        for (int i = 0; i < raw.size(); i++) {
            if (cnt.containsKey(raw.get(i)))
                tmp_cnt = cnt.get(raw.get(i)) + 1;
            else
                tmp_cnt = 1;
            cnt.put(raw.get(i), tmp_cnt);
        }
    }

    // 결과값 keyset을 출력하는 함수입니다.
    public static void print() {
        for (String key : cnt.keySet())
            System.out.println(key + " " + cnt.get(key));
    }

    public static void main(String[] args) {
        getData();
        counting();
        print();
    }
}