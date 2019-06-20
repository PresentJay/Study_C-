package jay.android_conquer.a796_cancelable;

import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class cancelable extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cancelable);
    }

    public void mOnClick(View v){
        AlertDialog dialog = new AlertDialog.Builder(this)
                .setTitle("erro")
                .setMessage("일거")
                .setIcon(R.drawable.ic_launcher_background)
                .setNegativeButton("닫기",null)
                .create();
        dialog.setCanceledOnTouchOutside(true);
        dialog.show();
    }
}
