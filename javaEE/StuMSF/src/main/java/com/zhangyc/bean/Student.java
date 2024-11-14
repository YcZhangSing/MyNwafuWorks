package com.zhangyc.bean;
public class Student {
    private int id;
    private String name;
    private String sex;
    private String cls;

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCls() {
        return cls;
    }

    public String getSex() {
        return sex;
    }

    public void setCls(String cls) {
        this.cls = cls;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setSex(String sex) {
        this.sex = sex;

    }
}
