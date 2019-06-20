package jay.android_conquer.a792_dialogbutton;

import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class dialogbutton extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dialogbutton);
    }

    public void mOnClick(View v){
        new AlertDialog.Builder(this)
                .setTitle("알린다")
                .setMessage("대화상자오픈")
                .setIcon(R.drawable.ic_launcher_background)
                .setPositiveButton("닫어", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                    }
                })
        .show();
    }
}
