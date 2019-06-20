package jay.android_conquer.a841_commactivity;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class ActEdit extends AppCompatActivity {
    EditText mEdit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_act_edit);

        mEdit = (EditText)findViewById(R.id.stredit);

        Intent intent = getIntent();
        String text = intent.getStringExtra("TextIn");
        if (text != null){
            mEdit.setText(text);
        }
    }

    public void mOnClick(View v){
        switch(v.getId()){
            case R.id.btnok:
                Intent intent = new Intent();
                intent.putExtra("TextOut", mEdit.getText().toString());
                setResult(RESULT_OK, intent);
                finish();
                break;

            case R.id.btncancel:
                setResult(RESULT_CANCELED);
                finish();
                break;
        }
    }
}
