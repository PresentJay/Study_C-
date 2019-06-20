package jay.android_conquer.a565_listadddelmulti;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.SparseBooleanArray;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.PopupMenu;

import java.util.ArrayList;

public class listadddelmulti extends AppCompatActivity {
    ArrayList<String> Items;
    ArrayAdapter<String> Adapter;
    ListView list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listadddelmulti);

        Items = new ArrayList<String>();
        Items.add("1");
        Items.add("2");
        Items.add("3");
        Items.add("4");
        Items.add("5");
        Items.add("6");

        Adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_multiple_choice, Items);
        list = (ListView)findViewById(R.id.list);
        list.setAdapter(Adapter);
        list.setChoiceMode(ListView.CHOICE_MODE_MULTIPLE);
    }

    public void mOnClick(View v){
        EditText ed = (EditText)findViewById(R.id.newitem);
        switch (v.getId()){
            case R.id.add:
                String text = ed.getText().toString();
                if (text.length()!=0) {
                    Items.add(text);
                    ed.setText("");
                    Adapter.notifyDataSetChanged();
                }
                break;
            case R.id.delete:
                SparseBooleanArray sb = list.getCheckedItemPositions();
                if (sb.size() != 0){
                    for (int i=list.getCount() -1; i>=0; i--) {
                        if (sb.get(i)) {
                            Items.remove(i);
                        }
                    }
                    list.clearChoices();
                    Adapter.notifyDataSetChanged();
                }
                break;
        }
    }
}
