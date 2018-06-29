package com.example.mlanie.camerara;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffXfermode;
import android.graphics.RectF;
import android.util.AttributeSet;
import android.view.View;

/**
 * Created by Mélanie on 15/06/2018.
 */

public class MyView extends View {

    public MyView(Context context) {
        super(context);
    }

    public MyView(Context context, AttributeSet attrs) {
        super(context, attrs);
        if (android.os.Build.VERSION.SDK_INT >= 11)
        {
            setLayerType(View.LAYER_TYPE_SOFTWARE, null);
        }
    }

    public MyView(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        canvas.drawColor(Color.TRANSPARENT, PorterDuff.Mode.CLEAR);

        Paint paint = new Paint();
        paint.setStrokeWidth(5);

        float y0 = (float) 0;
        float x0 = (float) 0;
        float rotate_angle = (float) 0;

        /* Draw a oval on a rotated canvas */
        canvas.rotate(rotate_angle, x0, y0);
        paint.setStyle(Paint.Style.STROKE);
        paint.setColor(Color.RED);
        RectF ellipse = new RectF(x0-0, y0-0, x0+0, y0+0);
        canvas.drawOval(ellipse, paint);
        // Resume original angle
        canvas.rotate(-rotate_angle, x0, y0);

    }
}