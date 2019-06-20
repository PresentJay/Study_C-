package jay.android_conquer.a381_menuonclick;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;

public class onclickmenu extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TextView myText = new TextView(this);
        myText.setText("메뉴 키를 누르세요.");
        setContentView(myText);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.onclickmenu, menu);

        return true;
    }

    public void mOnClick(MenuItem item){
        switch (item.getItemId()){
            case R.id.about:
                Toast.makeText(this,"onClick 속성으로 메뉴 이벤트를 처리합니다.",Toast.LENGTH_SHORT).show();
                break;
            case R.id.help:
                Toast.makeText(this,"도움말입니다.",Toast.LENGTH_SHORT).show();
                break;
        }
    }
}
