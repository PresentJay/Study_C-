package jay.android_conquer.a841_commactivity;

import android.content.Intent;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class commactivity extends AppCompatActivity {
    TextView mText;
    final static int ACT_EDIT = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_commactivity);

        mText = (TextView)findViewById(R.id.text);
    }

    public void mOnClick(View v){
        switch (v.getId()){
            case R.id.btnedit:
                Intent intent = new Intent(this, ActEdit.class);
                intent.putExtra("TextIn", mText.getText().toString());
                startActivityForResult(intent, ACT_EDIT);
                break;
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        switch (requestCode){
            case ACT_EDIT:
                if(resultCode == RESULT_OK){
                    mText.setText(data.getStringExtra("TextOut"));
                }
                break;
        }
    }
}
