package jay.android_conquer.a846_callother;

import android.content.ComponentName;
import android.content.Intent;
import android.net.Uri;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

import java.io.File;
import java.net.URI;

public class callother extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_callother);
    }

    public void mOnClick(View v){
        Intent intent;
        switch (v.getId()){
            case R.id.web:
                intent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.google.com"));
                startActivity(intent);
                break;

            case R.id.dial:
                intent = new Intent(Intent.ACTION_DIAL, Uri.parse("tel:015-123-4567"));
                startActivity(intent);
                break;

            case R.id.picture:
                intent = new Intent(Intent.ACTION_VIEW);
                String sd = Environment.getExternalStorageDirectory().getAbsolutePath();
                Uri uri = Uri.fromFile(new File(sd + "/test.jpg"));
                intent.setDataAndType(uri, "image/jpeg");
                startActivity(intent);
                break;

            case R.id.other:
                intent = new Intent(Intent.ACTION_MAIN);
                intent.setComponent(new ComponentName("exam.memo", "exam.memo.Memo"));
                startActivity(intent);
                break;
        }
    }
}
