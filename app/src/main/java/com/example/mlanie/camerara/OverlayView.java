package com.example.mlanie.camerara;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.Rect;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.View;

public class OverlayView extends View {

    private float x0;
    private float y0;
    private float a;
    private float b;
    private float rotate_angle;
    private Rect rect;

    public OverlayView(Context context) {
        super(context);
    }

    public OverlayView(Context context, AttributeSet attrs) {
        super(context, attrs);
        if (android.os.Build.VERSION.SDK_INT >= 11)
        {
            setLayerType(View.LAYER_TYPE_SOFTWARE, null);
        }
        x0 = 0;
        y0 = 0;
        a = 0;
        b = 0;
        rotate_angle = 0;
        rect = new Rect(0,0,0,0);
    }

    public OverlayView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        canvas.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);

        Paint paint = new Paint();
        paint.setStrokeWidth(5);

        /*float y0 = (float) 287.002991;
        float x0 = (float) 339.319153;
        float rotate_angle = (float) 4.554904;*/

        /* Draw a oval on a rotated canvas */
        canvas.rotate(rotate_angle, x0, y0);
        paint.setStyle(Paint.Style.STROKE);
        paint.setColor(Color.RED);
        RectF ellipse = new RectF(x0-a, y0-b, x0+a, y0+b);
        canvas.drawOval(ellipse, paint);
        // Resume original angle
        canvas.rotate(-rotate_angle, x0, y0);

        canvas.drawRect(this.rect, paint);

    }

    public void setEllipse(float x0, float y0, float a, float b, float rotate_angle) {
        this.x0 = x0;
        this.y0 = y0;
        this.a = a;
        this.b = b;
        this.rotate_angle = rotate_angle;
    }

    public void setRect(Rect rectangle) {
        this.rect = rectangle;
    }
}
