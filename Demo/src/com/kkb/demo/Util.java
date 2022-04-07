package com.kkb.demo;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.net.URLEncoder;

public class Util {
    /**
     * 用于基于城市获取天气信息
     * @param city 城市名称
     * @return 天气信息
     */
    public static String getWeather(String city){
        //网址：协议://域名:端口号/虚拟路径?参数列表#锚点
        //1.描述网站：https://itdage.cn/hw
        try {
            //0.将城市转化为URL编码
            city = URLEncoder.encode(city,"utf-8");
            URL url = new URL("http://itdage.cn/hw/weather?city="+city);
            //2.打开连接并得到连接对象
            URLConnection conn = url.openConnection();
            //3.获取数据的流
            InputStream is = conn.getInputStream();
            //4.将只能读取字节的流转换为能读取生活中文字的字符流
            BufferedReader br = new BufferedReader(new InputStreamReader(is,"UTF-8"));
            //5.获取地址下的一行文字信息（天气信息)
            String text = br.readLine();
            return text;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    /**
     * 短信发送功能
     * @param msg 包含一些关键信息
     * @return 结果
     */
    public static String sendSms(Message msg){
        //网址：协议://域名:端口号/虚拟路径?参数列表#锚点
        try {
            //0.对关键信息进行编码处理
            msg.setName(URLEncoder.encode(msg.getName(),"utf-8"));
            msg.setS1(URLEncoder.encode(msg.getS1(),"utf-8"));
            msg.setS2(URLEncoder.encode(msg.getS2(),"utf-8"));
            msg.setS3(URLEncoder.encode(msg.getS3(),"utf-8"));
            //1.描述网站：https://itdage.cn/hw
            URL url = new URL("http://itdage.cn/hw/hwSms?name="+msg.getName()+"&phoneNumber="+msg.getPhoneNumber()+"&s1="+msg.getS1()+"&s2="+msg.getS2()+"&s3="+msg.getS3());
            //2.打开连接并得到连接对象
            URLConnection conn = url.openConnection();
            //3.获取数据的流
            InputStream is = conn.getInputStream();
            //4.将只能读取字节的流转换为能读取生活中文字的字符流
            BufferedReader br = new BufferedReader(new InputStreamReader(is,"UTF-8"));
            //5.获取地址下的一行文字信息（短信反馈结果信息)
            String text = br.readLine();
            return text;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }


    public static void main(String[] args) {
       String weather = getWeather("苏州");
        System.out.println(weather);
        //Message msg = new Message ("宝","13813688321","晴","10-20度","我喜欢你");
        //sendSms(msg);
    }
}
