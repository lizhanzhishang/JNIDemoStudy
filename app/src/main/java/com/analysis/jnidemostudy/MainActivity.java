package com.analysis.jnidemostudy;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.analysis.jnidemostudy.databinding.ActivityMainBinding;
import com.google.gson.Gson;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        String[] array=new String[6];
        for (int i = 0; i < array.length; i++) {
            array[i]="I will "+(i+1);
        }

        char[] chars=new char[]{'A','B'};
        short[] shorts=new short[]{'A','B'};

        tv.setText(stringFromJNITest(array));
        UserInfo user=new UserInfo();
        sendString("dsadadadasdasdsad",user);

        Log.e("zyInfo", "---android.util.Log--- :"+new Gson().toJson(getOnffice(1,"zhuziyong")));
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
//    public native String stringFromJNI();
//    public native String stringFromJNI(String[] array);
    public native String stringFromJNITest(String[] array);
    public native String stringFromJNIListTest(List<String> array);
    public native void sendString(String info,UserInfo user);
    public native UserInfo getOnffice(int a,String b);
}