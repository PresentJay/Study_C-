package jay.android_conquer.a857_actparent;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class actparent extends AppCompatActivity {
    static final String TAG = "ActParent";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.i(TAG, "onCreate");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_actparent);
    }

    public void mOnClick(View v){
        Log.i(TAG, "startActivity");
    }
}
