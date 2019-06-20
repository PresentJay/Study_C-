package jay.android_conquer.a337_handleraccess;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

import org.w3c.dom.Text;

public class handleraccess extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_handleraccess);

        final TextView mText = (TextView)findViewById(R.id.text);
        LinearLayout linear = (LinearLayout)findViewById(R.id.linear);
        linear.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                if (motionEvent.getAction()==MotionEvent.ACTION_DOWN){
                    // 매번 차일드에서 검색하는 것은 불필요요
                   mText.setText("Touched");
                    return true;
                }
                return false;
            }
        }); //*/
    }
}
