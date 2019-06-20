package jay.android_conquer.a389_popupmenutest;

import android.app.Activity;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.PopupMenu;

public class popupmenutest extends AppCompatActivity {
    Button mBtn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_popupmenutest);

        mBtn = (Button)findViewById(R.id.btn);
    }

    public void mOnClick(View v){
        PopupMenu popup = new PopupMenu(popupmenutest.this, v);
       /* MenuInflater inflater = popup.getMenuInflater();
        Menu menu = popup.getMenu();
        inflater.inflate(R.menu.popupmenutestmenu, menu);*/
        popup.inflate(R.menu.popupmenutestmenu);
        popup.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() {
            public boolean onMenuItemClick(MenuItem menuItem) {
                switch (menuItem.getItemId()){
                    case R.id.red:
                        mBtn.setBackgroundColor(Color.RED);
                        break;
                    case R.id.green:
                        mBtn.setBackgroundColor(Color.GREEN);
                        break;
                    case R.id.blue:
                        mBtn.setBackgroundColor(Color.BLUE);
                        break;
                    case R.id.black:
                        mBtn.setTextColor(Color.BLACK);
                        break;
                    case R.id.white:
                        mBtn.setTextColor(Color.WHITE);
                        break;
                    case R.id.gray:
                        mBtn.setTextColor(Color.GRAY);
                        break;
                }
                return false;
            }
        });
        popup.show();
    }
}
