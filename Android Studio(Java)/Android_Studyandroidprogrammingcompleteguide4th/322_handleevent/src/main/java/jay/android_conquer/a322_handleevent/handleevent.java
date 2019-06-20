package jay.android_conquer.a322_handleevent;

import android.app.Activity;
import android.content.Context;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Toast;

public class handleevent extends AppCompatActivity implements View.OnTouchListener {  // 3.방법 액티비티에서 인터페이스 상속
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //View vw = new MyView(this); // 1.방법

        /* 2.방법
        View vw = new View(this);
        vw.setOnTouchListener(TouchListener); // 2-3. 리스너 등록
        //*/

        /* 3.방법
        View vw = new View(this);
        vw.setOnTouchListener(this);
        //*/

        /* 4.방법
        MyView vw = new MyView(this);
        vw.setOnTouchListener(vw);
        //*/

        //* 6.방법
        View vw = new View(this);
        vw.setOnTouchListener(new View.OnTouchListener(){
            public boolean onTouch(View v, MotionEvent event){
                if (event.getAction()==MotionEvent.ACTION_DOWN){
                    Toast.makeText(handleevent.this, "Touch Event Received", Toast.LENGTH_SHORT).show();
                    return true;
                }
                return false;
            }
        });
        setContentView(vw);
    }
    /* 1. 콜백메서드 재정의 방식
    class MyView extends View{
        public MyView(Context context){
            super(context);
        }

        public boolean onTouchEvent(MotionEvent event){
            super.onTouchEvent(event);
            if (event.getAction() == MotionEvent.ACTION_DOWN){
                Toast.makeText(handleevent.this, "Touch Event Received", Toast.LENGTH_SHORT).show();
                return true;
            }
            return false;
        }
    }
    */

    //* 4. 방법 클래스 선언
    class MyView extends View implements View.OnTouchListener{
        public MyView(Context context){
            super(context);
        }
        public boolean onTouch(View v, MotionEvent event){
            if (event.getAction()==MotionEvent.ACTION_DOWN){
                Toast.makeText(handleevent.this, "Touch Event Received", Toast.LENGTH_SHORT).show();
                return true;
            }
            return false;
        }
    }

    // 2. 리스너 인터페이스 구현 방법
    // 2-1. 리스너 구현 클래스 선언
    class TouchListenerClass implements View.OnTouchListener{
        public boolean onTouch(View v, MotionEvent event){
            if (event.getAction()==MotionEvent.ACTION_DOWN){
                Toast.makeText(handleevent.this, "Touch Event Received", Toast.LENGTH_SHORT).show();
                return true;
            }
            return false;
        }
    }
    // 2-2. 리스너 객체 생성
    TouchListenerClass TouchListener = new TouchListenerClass();

    // 3-1. 액티비티 리스너 인터페이스 구현
    public boolean onTouch(View v, MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN){
            Toast.makeText(handleevent.this, "Touch Event Received", Toast.LENGTH_SHORT).show();
            return true;
        }
        return false;
    }
}
