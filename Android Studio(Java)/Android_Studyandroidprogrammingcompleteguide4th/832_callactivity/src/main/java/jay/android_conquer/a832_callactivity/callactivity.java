package jay.android_conquer.a832_callactivity;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class callactivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_callactivity);
    }

    public void mOnClick(View v){
        Intent intent = new Intent(this, SubActivity.class);
        startActivity(intent);
    }
}
