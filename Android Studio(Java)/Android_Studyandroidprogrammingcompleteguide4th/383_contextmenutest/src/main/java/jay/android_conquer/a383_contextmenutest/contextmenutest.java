package jay.android_conquer.a383_contextmenutest;

import android.app.AlertDialog;
import android.content.Context;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.AttributeSet;
import android.view.ContextMenu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

public class contextmenutest extends AppCompatActivity {
    Button mBtn;
    EditText mEdit;
    MyImage mImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_contextmenutest);

        mBtn = (Button)findViewById(R.id.button);
        registerForContextMenu(mBtn);
        mEdit = (EditText)findViewById(R.id.editText);
        registerForContextMenu(mEdit);
        mImage = (MyImage)findViewById(R.id.myimage);
        registerForContextMenu(mImage);
    }

    @Override
    public void onCreateContextMenu(ContextMenu menu, View v, ContextMenu.ContextMenuInfo menuInfo) {
        super.onCreateContextMenu(menu, v, menuInfo);

        if (v == mBtn) {
            menu.setHeaderTitle("Button Menu");
            menu.add(0,1,0,"Red");
            menu.add(0,2,0,"Green");
            menu.add(0,3,0,"Blue");
        }
        if (v==mEdit){
            menu.add(0,4,0,"번역하기");
            menu.add(0,5,0,"필기 인식");
        }
    }

    public boolean onContextItemSelected (MenuItem item){
        switch ( item.getItemId()){
            case 1:
                mBtn.setTextColor(Color.RED);
                return true;
            case 2:
                mBtn.setTextColor(Color.GREEN);
                return true;
            case 3:
                mBtn.setTextColor(Color.BLUE);
                return true;
            case 4:
                Toast.makeText(this,"번역했다.",Toast.LENGTH_SHORT).show();
                return true;
            case 5:
                Toast.makeText(this,"필기 인식했다.",Toast.LENGTH_SHORT).show();
                return true;
            case 100:
                Toast.makeText(this,"회전했다 치고.",Toast.LENGTH_SHORT).show();
                return true;
            case 101:
                Toast.makeText(this,"크기 변경 했다 치고.",Toast.LENGTH_SHORT).show();
                return true;
        }
        return true;
    }

    class MyImage extends android.support.v7.widget.AppCompatImageView{
        public MyImage(Context context){
            super(context);
        }

        public MyImage(Context context, AttributeSet attrs){
            super(context, attrs);
        }

        public void onCreateContextMenu(ContextMenu menu){
            super.onCreateContextMenu(menu);

            menu.setHeaderTitle("MyImage Menu");
            menu.add(0,100,0,"이미지 회전");
            menu.add(0,101,0,"크기 변경");
        }
    }
}
