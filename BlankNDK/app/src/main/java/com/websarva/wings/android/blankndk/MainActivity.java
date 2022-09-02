package com.websarva.wings.android.blankndk;

import android.os.Bundle;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 渡すデータを作成する
        int[] list = {1,2,3,4,5};

        // viewを取得する
        TextView textView = (TextView)findViewById(R.id.textArea);

        // 配列の数値の合計を求める
        int val = amountValues(list); //　C言語で定義したメソッドを呼び出す

        // 結果を表示
        textView.setText("amountValues=" + val);
    }

    // AndroidNDKで作成したメソッドの定義
    public native int amountValues(int[] list);

    // Android NDKで作成したライブラリを呼び出し
    static {
        System.loadLibrary("amount-values");
    }
}