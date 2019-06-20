package jay.android_conquer.a379_optionmenuxml;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.widget.TextView;
import android.widget.Toast;

public class optionmenuxml extends AppCompatActivity {

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
        inflater.inflate(R.menu.optionmenu, menu);

        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()){
            case R.id.jjajang:
                Toast.makeText(this,"짜장",Toast.LENGTH_SHORT).show();
                return true;
            case R.id.jjambbong:
                Toast.makeText(this,"짬뽕",Toast.LENGTH_SHORT).show();
                return true;
            case R.id.udong:
                Toast.makeText(this,"우동",Toast.LENGTH_SHORT).show();
                return true;
            case R.id.mandoo:
                Toast.makeText(this,"만두",Toast.LENGTH_SHORT).show();
                return true;
        }
        return  false;
    }
}
