package com.zhangyc.listener;

import javax.servlet.ServletContext;
import javax.servlet.ServletRequestEvent;
import javax.servlet.ServletRequestListener;
import javax.servlet.annotation.WebListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

@WebListener()
public class DBManagerListener implements ServletRequestListener {

    public void requestDestroyed(ServletRequestEvent sre) {
        ServletContext ctx = sre.getServletContext();
        Object con = ctx.getAttribute("DBCon");
        if(con != null)
        {
            Connection conn = (Connection) con;
            try {
                if(!conn.isClosed())
                {
                    conn.close();
                }
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
        }
    }

    public void requestInitialized(ServletRequestEvent sre) {

        //        1.加载驱动
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
//        2.用户信息和url
//        String url = "jdbc:mysql://localhost:3306/stums?useUnicode=true&characterEncoding=utf8&useSSL=true";
        String url = "jdbc:mysql://81.70.54.158:3306/sb?useUnicode=true&characterEncoding=utf8&useSSL=true";
        String username="root";
        String password="zyc123456";
        Connection con = null;
        try {
            con = DriverManager.getConnection(url,username,password);
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        ServletContext ctx = sre.getServletContext();
        ctx.setAttribute("DBCon",con);
    }
}
