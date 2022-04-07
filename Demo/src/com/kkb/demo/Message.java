package com.kkb.demo;

import java.util.Objects;

public class Message {
    private String name;
    private String phoneNumber;
    //今天天气
    private String s1;
    //温度区间
    private String s2;
    //建议
    private String s3;


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Message message = (Message) o;
        return Objects.equals(name, message.name) &&
                Objects.equals(phoneNumber, message.phoneNumber) &&
                Objects.equals(s1, message.s1) &&
                Objects.equals(s2, message.s2) &&
                Objects.equals(s3, message.s3);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, phoneNumber, s1, s2, s3);
    }

    @Override
    public String toString() {
        return "Message{" +
                "name='" + name + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", s1='" + s1 + '\'' +
                ", s2='" + s2 + '\'' +
                ", s3='" + s3 + '\'' +
                '}';
    }

    public Message(String name, String phoneNumber, String s1, String s2, String s3) {
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
    }

    public Message() {
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getS1() {
        return s1;
    }

    public void setS1(String s1) {
        this.s1 = s1;
    }

    public String getS2() {
        return s2;
    }

    public void setS2(String s2) {
        this.s2 = s2;
    }

    public String getS3() {
        return s3;
    }

    public void setS3(String s3) {
        this.s3 = s3;
    }
}
