package jay.android_conquer.a559_listitemselect;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

public class listitemselect extends AppCompatActivity {

    String[] arGeneral = {"김유신", "이순신", "강감찬", "을지문덕"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listitemselect);

        ArrayAdapter<String> Adapter;
        Adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, arGeneral);
        ListView list = (ListView)findViewById(R.id.list);
        list.setAdapter(Adapter);
        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String mes;
                mes = "Select Item = " + arGeneral[i];
                Toast.makeText(listitemselect.this, mes, Toast.LENGTH_SHORT).show();
            }
        });
    }
}
