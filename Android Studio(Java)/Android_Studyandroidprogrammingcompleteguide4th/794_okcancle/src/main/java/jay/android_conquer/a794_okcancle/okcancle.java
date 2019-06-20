package jay.android_conquer.a794_okcancle;

import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class okcancle extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_okcancle);
    }

    public void mOnClick(View v){
        new AlertDialog.Builder(this)
                .setTitle("퀘스챤")
                .setMessage("나한테 100마넌 줄랭?")
                .setIcon(R.drawable.ic_launcher_background)
                .setPositiveButton("확인",null)
                .setNegativeButton("취소",null)
                .show();
    }
}
