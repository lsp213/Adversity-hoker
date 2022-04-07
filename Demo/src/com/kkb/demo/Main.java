package com.kkb.demo;

import com.alibaba.fastjson.JSONObject;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class Main {
    private static JFrame jf;
    private static JEditorPane namePane,phonePane,cityPane;
    private static JButton button;
    private static Thread thread;
    //一个标记，标记停止与否
    private static boolean flag;
    private static ActionListener listener = new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
            flag = !flag;
            if(flag){
                button.setText("点击取消");
                start();
            } else{
                button.setText("点击执行");
                end();
            }
        }
    };

    private static void end() {
    }

    private static void start() {
        if(thread != null){
            thread.interrupt();
        }
        thread = new Thread(){
            @Override
            public void run(){
                while(flag) {

                    //点击开始执行程序，这里代码被执行
                    //1.获取关键信息，姓名、手机号、城市
                    //2.根据城市获取天气信息
                    //3.获得天气信息中天气情况、温度区间、建议
                    //4.发送短信
                    String name = namePane.getText();
                    String phoneNumber = phonePane.getText();
                    String city = cityPane.getText();
                    String weatherJSON = Util.getWeather(city);
                    Message message = getinfo(weatherJSON,name,phoneNumber);
                    Util.sendSms(message);
                    try {
                        Thread.sleep(3600000);
                    } catch (InterruptedException e) {
                        break;
                    }
                }

            }
        };
        thread.start();
    }

    private static Message getinfo(String weatherJSON,String name,String phoneNumber) {
        JSONObject object =JSONObject.parseObject(weatherJSON);
        JSONObject result = object.getJSONObject("result");
        //关键信息1天气情况
        String s1 = result.getString("weather");
        //关键信息2温度区间
        String templow = result.getString("templow");
        String temphigh = result.getString("temphigh");
        String s2 = templow+"-"+temphigh+"℃";
        //关键信息3建议
        String[] array = {result.getJSONArray("index").getJSONObject(0).getString("detail"),
                result.getJSONArray("index").getJSONObject(1).getString("detail"),
                result.getJSONArray("index").getJSONObject(2).getString("detail"),
                result.getJSONArray("index").getJSONObject(3).getString("detail"),
                result.getJSONArray("index").getJSONObject(4).getString("detail"),
                result.getJSONArray("index").getJSONObject(5).getString("detail"),
                result.getJSONArray("index").getJSONObject(6).getString("detail")
        };
        Random r = new Random();
        int index = r.nextInt(array.length);
        String s3 = array[index];
        Message msg = new Message(name,phoneNumber,s1,s2,s3);
        return msg;
    }

    public static void main(String[] args) {
        //初始化视图
        initView();
        //初始化数据
        initData();
    }

    private static void initData() {
    }

    private static void initView() {
        jf = new JFrame("天气查询");
        LayoutManager manager = new FlowLayout();
        jf.setLayout(manager);
        jf.setVisible(true);
        jf.setSize(280,200);
        jf.setResizable(false);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //添加姓名输入框
        JPanel pane1 = new JPanel();
        JLabel label1 = new JLabel("姓名:");
        namePane = new JEditorPane();
        pane1.add(label1);
        pane1.add(namePane);
        pane1.setSize(200,40);
        jf.add(pane1);
        //添加手机号输入框
        JPanel pane2 = new JPanel();
        JLabel label2 = new JLabel("手机号:");
        phonePane = new JEditorPane();
        pane2.add(label2);
        pane2.add(phonePane);
        pane2.setSize(200,40);
        jf.add(pane2);
        //添加所在城市输入框
        JPanel pane3 = new JPanel();
        JLabel label3 = new JLabel("所在城市");
        cityPane = new JEditorPane();
        pane3.add(label3);
        pane3.add(cityPane);
        pane3.setSize(200,40);
        jf.add(pane3);
        //添加按钮，用于发送
        JPanel pane4 = new JPanel();
        button = new JButton("点击执行");
        pane4.add(button);
        pane4.setSize(200,40);
        jf.add(pane4);
        //当用户点击按钮时，执行回调函数
        button.addActionListener(listener);



        jf.setVisible(true);
    }
}
