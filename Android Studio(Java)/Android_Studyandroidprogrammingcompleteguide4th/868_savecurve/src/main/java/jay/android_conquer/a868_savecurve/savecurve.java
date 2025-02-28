package jay.android_conquer.a868_savecurve;

import android.app.Activity;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.PersistableBundle;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;

import java.io.Serializable;
import java.util.ArrayList;

public class savecurve extends AppCompatActivity {
    private MyView vw;
    ArrayList<Vertex> arVertex;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        vw = new MyView(this);
        setContentView(vw);

        if (savedInstanceState == null){
            arVertex = new ArrayList<Vertex>();
        } else {
            arVertex = (ArrayList<Vertex>)savedInstanceState.getSerializable("Curve");
        }
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putSerializable("Curve", arVertex);
    }

    public class Vertex implements Serializable{
        private static final long serialVersionUID = 100L;
        Vertex(float ax, float ay, boolean ad){
            x = ax;
            y = ay;
            draw = ad;
        }
        float x;
        float y;
        boolean draw;
    }

    protected class MyView extends View {
        Paint mPaint;

        public MyView(Context context) {
            super(context);

            // Paint 객체 미리 초기화
            mPaint = new Paint();
            mPaint.setColor(Color.BLACK);
            mPaint.setStrokeWidth(3);
            mPaint.setAntiAlias(true);
        }

        public void onDraw(Canvas canvas) {
            canvas.drawColor(Color.LTGRAY);

            // 정점을 순회하면서 선분으로 잇는다.
            for (int i=0;i<arVertex.size();i++) {
                if (arVertex.get(i).draw) {
                    canvas.drawLine(arVertex.get(i-1).x, arVertex.get(i-1).y,
                            arVertex.get(i).x, arVertex.get(i).y, mPaint);
                }
            }
        }

        // 터치 이동 시마다 정점을 추가한다.
        public boolean onTouchEvent(MotionEvent event) {
            if (event.getAction() == MotionEvent.ACTION_DOWN) {
                arVertex.add(new Vertex(event.getX(), event.getY(), false));
                return true;
            }
            if (event.getAction() == MotionEvent.ACTION_MOVE) {
                arVertex.add(new Vertex(event.getX(), event.getY(), true));
                invalidate();
                return true;
            }
            return false;
        }
    }
}
