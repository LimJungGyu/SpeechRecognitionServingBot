package com.example.myapplication;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        EditText editText = findViewById(R.id.editText);


        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                InputMethodManager manager = (InputMethodManager)getSystemService(INPUT_METHOD_SERVICE);
                manager.hideSoftInputFromWindow(getCurrentFocus().getWindowToken(), InputMethodManager.HIDE_NOT_ALWAYS);

            }
        });
        Button table1 = findViewById(R.id.table1);
        table1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editText.setText("1");
                ClientThread thread = new ClientThread();
                thread.start();

            }
        });
        Button table2 = findViewById(R.id.table2);
        table2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editText.setText("2");
                ClientThread thread = new ClientThread();
                thread.start();
            }
        });
        Button table3 = findViewById(R.id.table3);
        table3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editText.setText("3");
                ClientThread thread = new ClientThread();
                thread.start();
            }
        });
        Button table4 = findViewById(R.id.table4);
        table4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editText.setText("4");
                ClientThread thread = new ClientThread();
                thread.start();
            }
        });
        Button table5 = findViewById(R.id.table5);
        table5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editText.setText("5");
                ClientThread thread = new ClientThread();
                thread.start();
            }
        });
        Button table6 = findViewById(R.id.table6);
        table6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                editText.setText("6");
                ClientThread thread = new ClientThread();
                thread.start();
            }
        });
    }

    class ClientThread extends Thread {
        @Override
        public void run() {
            EditText editText = findViewById(R.id.editText);
            TextView textView = findViewById(R.id.textView);
            EditText ServerIP = findViewById(R.id.ServerIP);
//            String host = "192.168.0.16";
            String host =ServerIP.getText().toString(); //정수값 가져오기
            int port = 9997;

            try {
                Socket socket = new Socket(host, port);
                DataOutputStream dataOutputStream = new DataOutputStream(socket.getOutputStream());
                String TableNum = editText.getText().toString();
                dataOutputStream.write(TableNum.getBytes(StandardCharsets.UTF_8));
                editText.setText("");
                dataOutputStream.flush();
                Log.d("ClientStream", "Sent to server.");

                DataInputStream dataInputStream = new DataInputStream(socket.getInputStream());
                byte[] in = new byte[100];
                dataInputStream.read(in, 0, in.length);
                String input = new String(in, 0, in.length);
                input = input.trim().toString();
                Log.d("ClientThread", "Received data: " + input);
                textView.setText(TableNum+"번 테이블: "+input);

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

}
