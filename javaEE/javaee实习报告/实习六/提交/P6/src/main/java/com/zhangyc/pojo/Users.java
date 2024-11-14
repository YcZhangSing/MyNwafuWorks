package com.zhangyc.pojo;

public class Users {
    private String user_name;
    private String passwd;

    public String getuser_name() {
        return user_name;
    }

    public void setuser_name(String user_name) {
        this.user_name = user_name;
    }

    public String getpasswd() {
        return passwd;
    }

    public void setpasswd(String passwd) {
        this.passwd = passwd;
    }

    public Users(String user_name, String passwd) {
        this.user_name = user_name;
        this.passwd = passwd;
    }

    public Users() {
    }

    @Override
    public String toString() {
        return "Users{" +
                "user_name='" + user_name + '\'' +
                ", passwd='" + passwd + '\'' +
                '}';
    }
}
