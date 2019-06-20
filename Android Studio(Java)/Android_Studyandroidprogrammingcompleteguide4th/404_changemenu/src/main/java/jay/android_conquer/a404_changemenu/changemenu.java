package jay.android_conquer.a404_changemenu;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;

public class changemenu extends AppCompatActivity {
    boolean mBeginner = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_changemenu);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        super.onCreateOptionsMenu(menu);
        MenuInflater inflater = getMenuInflater();
        if (mBeginner){
            inflater.inflate(R.menu.beginner, menu);
        }
        else{
            inflater.inflate(R.menu.professional, menu);
        }

        return  true;
    }

    public void mOnClick(View v){
        switch (v.getId()){
            case R.id.btnbeginner:
                mBeginner = true;
                invalidateOptionsMenu();
                break;
            case R.id.btnprofessional:
                mBeginner = false;
                invalidateOptionsMenu();
                break;
        }
    }
}
