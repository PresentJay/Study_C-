package jay.android_conquer.a999_simpleadapter;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;

public class simpleadapter extends AppCompatActivity {

    ListView list;
    String[] mySter2 = new String[] {"111", "222", "333", "444", "555", "666"};
    String[] myStr = new String[] {"Benz", "Bike", "Car", "carrera", "ferrari", "harly"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_simpleadapter);

        list=(ListView)findViewById(R.id.list);
        ArrayList<HashMap<String,String>> arrayList = new ArrayList<>();
        for (int i=0; i<6; i++){
            HashMap<String, String> hashMap = new HashMap<>();
            hashMap.put("order", mySter2[i]);
            hashMap.put("Name", myStr[i]);
            arrayList.add(hashMap);
        }
        String[] from = {"order", "Name"};
        int[] to= {R.id.order, R.id.Name};

        SimpleAdapter simpleAdapter = new SimpleAdapter(this, arrayList, R.layout.activity_simpleadapter, from, to);
        list.setAdapter(simpleAdapter);
    }
}
