package jay.android_conquer.a552_listviewtest;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Layout;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;

public class listviewtest extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listviewtest);

        // 데이터 원본 준비
        ArrayList<String> arGeneral = new ArrayList<String>();
        arGeneral.add("김유신");
        arGeneral.add("김유신2");
        arGeneral.add("김유신3");
        arGeneral.add("김유신4");

        // 어댑터 준비
        ArrayAdapter<String> Adapter;
        Adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, arGeneral);

        // 어댑터 연결
        ListView list = (ListView)findViewById(R.id.list);
        list.setAdapter(Adapter);
        
    }
}
