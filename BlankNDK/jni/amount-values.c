#include <string.h>
#include <jni.h>

/**
 *   配列の数値をすべて加算して返す
 */
 jint
 // Java側から呼び出されるメソッドを定義
 Java_com_websarva_wings_android_ndk_MainActivity_amountValues(JNIEnv* env,
                                                jobject thiz,
                                                jintArray arr)
{
    jint *carr;
    jint i, sum = 0;
    // Javaの配列を、Cでアクセスできるように変換：２
    carr = (*env)->GetIntArrayElements(env, arr, NULL);

    // 配列の長さを取得
    int size = (*env)->GetArrayLength(env, arr);

    // 配列領域が確保できているかチェック
    if (carr == NULL) {
        return 0;
    }

    // 合計値を計算
    for (i=0; i<size; i++) {
        sum += carr[i];
    }

    // ２：で取得した配列情報を開放
    (*env)->ReleaseIntArrayElements(env, arr, carr, 0); // 取得した領域を解放
    return sum;
}