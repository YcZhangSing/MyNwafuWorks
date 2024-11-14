# Java EE 第三次实习 EL、JSTL及MVC

|  课程   |  姓名  |    学号    |    班级    |
| :-----: | :----: | :--------: | :--------: |
| Java EE | 张宇晨 | 2020012249 | 软工2001班 |



[toc]

## 开发环境与工程结构

Intellij IDEA 2020.2

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221015213903081.png" alt="image-20221015213903081" style="zoom:55%;" />

工程结构

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221112224400853.png" alt="image-20221112224400853" style="zoom:77%;" />

## 实现内容

### 1. 登陆实现

![image-20221113114116182](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113114116182.png)

#### View: login.jsp

![image-20221113110150777](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113110150777.png)

#### Control: action=check

![image-20221113110449563](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113110449563.png)

#### Model: dbp.LoginCheck()

![image-20221113110736261](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113110736261.png)

### 2. 数据库监听器

![image-20221113111634033](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113111634033.png)



### 3. 查看书列表

![image-20221113114133817](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113114133817.png)

#### View: list.jsp

![image-20221113112328395](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113112328395.png)

![image-20221113112346960](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113112346960.png)

#### Control: action为其他字符

![image-20221113112736427](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113112736427.png)

#### Model: dbp.getBookList()

![image-20221113112755377](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113112755377.png)

### 4. 增加书

![image-20221113114149689](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113114149689.png)

#### View: add.jsp

![image-20221113112936902](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113112936902.png)

#### Control: action=save

![image-20221113113022140](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113022140.png)

#### Model: dbp.save()

![image-20221113113134511](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113134511.png)

### 5. 修改书

![image-20221113114208256](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113114208256.png)

#### View: edit.jsp

![image-20221113113234742](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113234742.png)

#### Control: action=save

![image-20221113113022140](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113022140.png)

#### Model: dbp.save()

![image-20221113113146714](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113146714.png)

### 6.删除书

![image-20221113114226245](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113114226245.png)

#### View: list.jsp , SResult.jsp

![image-20221113113300126](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113300126.png)

#### Control: action=delete

![image-20221113113343009](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113343009.png)

#### Model: dbp.deleteBookById()

![image-20221113113426704](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113426704.png)



### 7.按照书名查询

#### View: list.jsp  

![image-20221113113604153](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113604153.png)

#### Control: action=select

![image-20221113113644377](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113644377.png)

#### Model: dbp.deleteBookListByName()

![image-20221113113701117](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113113701117.png)

### 8.过滤器保护

LoginFilter

```java
package com.zhangyc.filter;
import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;

//@WebFilter(filterName = "log",urlPatterns = "")
public class LoginFilter implements Filter {
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws IOException, ServletException {
        //1.强制转换
        HttpServletRequest request = (HttpServletRequest) req;
        //2.获取请求资源路径
        String requestURI = request.getRequestURI();
        //3.判断是否包含check.jsp页面
        //if (requestURI.contains("/check.jsp") )
        if (requestURI.contains("/Controller") )
        {
            //放行
            chain.doFilter(req, resp);
        }
        else
        {
            //4.判断是否登录
            Object permission = request.getAttribute("Login");
            if (permission != null)
            {
                //已登录，放行
                chain.doFilter(req, resp);
            }else
            {
                //未登录，跳转登陆页面
                request.setAttribute("login_msg","您未登录");
                request.getRequestDispatcher("/login.jsp").forward(request,resp);
            }
        }

    }

    public void destroy() {

    }
}

```

web.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    <filter>
        <filter-name>log</filter-name>
        <filter-class>com.zhangyc.filter.LoginFilter</filter-class>
    </filter>
    <filter-mapping>
        <filter-name>log</filter-name>
        <url-pattern>/add.jsp</url-pattern>
    </filter-mapping>
    <filter-mapping>
        <filter-name>log</filter-name>
        <url-pattern>/list.jsp</url-pattern>
    </filter-mapping>
    <filter-mapping>
        <filter-name>log</filter-name>
        <url-pattern>/edit.jsp</url-pattern>
    </filter-mapping>
    <filter-mapping>
        <filter-name>log</filter-name>
        <url-pattern>/SResult.jsp</url-pattern>
    </filter-mapping>
</web-app>
```



## 扩展——过滤器充当控制器

过滤器实现控制器也非常简单。只需要在过滤器的dofilter方法中获取动作参数，并处理即可。需要将jsp表单的提交地址改为目的jsp页面，然后将过滤器过滤路径映射为相应的jsp页面，这样 过滤器才可以起到控制器的作用。

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113122349735.png" alt="image-20221113122349735" style="zoom:80%;" />

### 工程结构

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113121720166.png" alt="image-20221113121720166" style="zoom:50%;" />

### 过滤器控制

![image-20221113121908306](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113121908306.png)

### web.xml

```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app xmlns="http://xmlns.jcp.org/xml/ns/javaee"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd"
         version="4.0">
    <filter>
        <filter-name>control</filter-name>
        <filter-class>com.zhangyc.controll.Controller</filter-class>
    </filter>
    <filter-mapping>
        <filter-name>control</filter-name>
        <url-pattern>/add.jsp</url-pattern>
    </filter-mapping>
    <filter-mapping>
        <filter-name>control</filter-name>
        <url-pattern>/list.jsp</url-pattern>
    </filter-mapping>
    <filter-mapping>
        <filter-name>control</filter-name>
        <url-pattern>/edit.jsp</url-pattern>
    </filter-mapping>
    <filter-mapping>
        <filter-name>control</filter-name>
        <url-pattern>/SResult.jsp</url-pattern>
    </filter-mapping>
</web-app>
```

## 补充

### 项目已部署在个人网站，欢迎老师访问评阅 (登陆界面的用户名是 ：zyc    密码是：123456  )

（http://www.zhangyuchen.cn/javaEE_wk/）[点击访问](http://www.zhangyuchen.cn/javaEE_wk/)

![image-20221113123805359](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221113123805359.png)



## 附录

### JavaBean代码

book

```java
package com.zhangyc.bean;

public class book {
    private int id;
    private String ISBN;
    private String name;
    private String publisher;
    private String author;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    @Override
    public String toString() {
        return "book{" +
                "id=" + id +
                ", ISBN='" + ISBN + '\'' +
                ", name='" + name + '\'' +
                ", publisher='" + publisher + '\'' +
                ", author='" + author + '\'' +
                '}';
    }

    public book() {
    }
}

```



DBProcess

```java
package com.zhangyc.bean;

import com.mysql.cj.xdevapi.Session;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.sql.*;
import java.util.ArrayList;

public class DBProcess {
    private HttpServletRequest request;
    private Connection con;
    private Statement stat;
    public DBProcess(HttpServletRequest request)
    {
        this.request= request;
        ServletContext ctx = request.getSession().getServletContext();
        con = (Connection)ctx.getAttribute("DBCon");//获取数据库连接属性
    }
    public void save() throws Exception{
        String insertSQL = "insert into books(ISBN,name,publisher,author) value(?,?,?,?)";
        String updateSQL = "update books set ISBN=?,name=?,publisher=?, author=? where id=?";
        ArrayList<String> ps = new ArrayList<String>();
        String id = request.getParameter("id");
        System.out.println("id"+id);
        if(id == null || id.length() == 0)
        {
            request.setCharacterEncoding("UTF-8");
           // ps.add("'"+request.getParameter("name")+"'");
            ps.add(request.getParameter("ISBN"));
            ps.add(request.getParameter("name"));
            ps.add(request.getParameter("publisher"));
            ps.add(request.getParameter("author"));

            exePrepare(insertSQL,ps);
        }
        else
        {
            request.setCharacterEncoding("UTF-8");
            System.out.println(request.getParameter("name"));
            ps.add(request.getParameter("ISBN"));
            ps.add(request.getParameter("name"));
            //System.out.println(new String(request.getParameter("name").getBytes("iso-8859-1"), "utf-8"));
            ps.add(request.getParameter("publisher"));
            ps.add(request.getParameter("author"));
            ps.add(id);
            //request.setAttribute("pstest",ps);
            exePrepare(updateSQL,ps);
        }
    }
    //获取图书列表方法
    public void getBookList() throws SQLException{
        String sql = "select * from books;";
        ResultSet rs = getRS(sql);
        ArrayList<book> bookList = new ArrayList<book>();
        while(rs.next())
        {
            bookList.add(toBook(rs));
        }
        request.setAttribute("bkList",bookList);
        closeRS(rs);
    }
    public boolean LoginCheck() throws SQLException
    {
        System.out.println("来到check函数了");
        String username = request.getParameter("username");
        String pwd = request.getParameter("password");
        String LogcheckSQL="select passwd from user_pass where name='"+username+"';";
        System.out.println(LogcheckSQL);
        ResultSet rs = getRS(LogcheckSQL);
        if(rs.next())
        {
            String dbpwd = rs.getString("passwd");
            System.out.println(dbpwd);
            if(!(pwd==null || pwd.length()==0) && pwd.equals(dbpwd))
            {
                HttpSession session =  request.getSession();
                session.setAttribute("login",true);
                return true;
            }
        }
        return false;
    }
    public void getBookListByName(String n) throws SQLException{
        String sql = "select * from books where name like ";
        sql = sql + "'%" + n + "%'" + ";" ;
        ResultSet rs = getRS(sql);
        ArrayList<book> bookList = new ArrayList<book>();
        while(rs.next())
        {
            bookList.add(toBook(rs));
        }
        request.setAttribute("bkList",bookList);
        System.out.println(bookList);
        closeRS(rs);
    }
    //通过学号获取学生信息并绑定到request对象
    public void getBookById() throws SQLException
    {
        String sql = "select * from books where id=";
        String id = request.getParameter("id");
        sql+=id+";";
        ResultSet rs = getRS(sql);
        if(rs.next())
        {
            book bk = toBook(rs);
            request.setAttribute("bk",bk);
        }
    }
    public void deleteBookById() throws SQLException{
        String sql = "delete from books where id=?";
        String id = request.getParameter("id");
        ArrayList<String> params = new ArrayList<String>();
        params.add(id);
        exePrepare(sql,params);
    }
    //执行带参数的SQL，不返回数据集
    public void exePrepare(String sql,  ArrayList<String> params) throws SQLException
    {
        PreparedStatement pstat = con.prepareStatement(sql);
        int i=1;
        for(String p:params)
        {
            pstat.setString(i++,p);
        }
        pstat.execute();
        pstat.close();
    }
    //执行SQL语句,返回数据集
    private ResultSet getRS(String sql) throws SQLException
    {
        stat = con.createStatement();
        ResultSet rs = stat.executeQuery(sql);
        return rs;
    }
    //对象转换
    private book toBook(ResultSet rs) throws SQLException
    {
        book bk = new book();
        bk.setId(rs.getInt("id"));
        bk.setISBN(rs.getString("ISBN"));
        bk.setName(rs.getString("name"));
        bk.setPublisher(rs.getString("publisher"));
        bk.setAuthor(rs.getString("author"));
        return bk;
    }
    //关闭连接
    private void closeRS(ResultSet rs) throws SQLException
    {

        stat.close();
        rs.close();

    }
}
```

### 监听器

```java
package com.zhangyc.listener;

import javax.servlet.*;
import javax.servlet.annotation.WebListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

@WebListener()
public class DBManagerListener implements ServletContextListener {
    public void contextInitialized(ServletContextEvent sce) {

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
        ServletContext ctx = sce.getServletContext();
        ctx.setAttribute("DBCon",con);
    }
    public void contextDestroyed(ServletContextEvent sce) {
        ServletContext ctx = sce.getServletContext();
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

}
```

### Servlet控制器

```java
package com.zhangyc.controll;

import com.zhangyc.bean.DBProcess;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;
@WebServlet("/Controller")
public class Controller extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
        doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
//        resp.setHeader("Content-Type","text/html;charset=UTF-8");
        String redirect = "";
        String fwd = "";
        DBProcess dbp = new DBProcess(req);
        String action = req.getParameter("action");
        boolean login = false;
        HttpSession session =  req.getSession();
        if(session.getAttribute("login")!=null)
        {
            login=true;
        }
        System.out.println(action);
        if ("save".equals(action))
        {
            System.out.println("save的login   :"+login);
            if (login) {
                try {
                    dbp.save();
                } catch (Exception e) {
                    e.printStackTrace();
                }
                redirect = "/LibMS/Controller";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("login".equals(action))
        {
            fwd="login.jsp";
        }

        else if ("check".equals(action))
        {
            System.out.println("check6666666");
            try {
                login = dbp.LoginCheck();
            } catch (Exception e) {
                e.printStackTrace();
            }
            if(login) {
                redirect = "/LibMS/Controller?action=list";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("delete".equals(action))
        {
            if(login) {
                try {
                    dbp.deleteBookById();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                redirect = "/LibMS/Controller";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("edit".equals(action))
        {
            if(login) {
                try {
                    dbp.getBookById();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                fwd = "edit.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("add".equals(action))
        {
            if(login) {
                fwd = "add.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("select".equals(action))
        {
            if(login) {
                String name = req.getParameter("name");
                try {
                    dbp.getBookListByName(name);
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                fwd = "SResult.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else {
            //System.out.println("else里面的：login   " + login);
            if(login)
            {
                try {
                    dbp.getBookList();
                   // System.out.println("执行查询书库完毕");
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                fwd = "list.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }

        if ("".equals(redirect)) {
            req.getRequestDispatcher(fwd).forward(req, resp);
        } else {
            resp.sendRedirect(redirect);
        }

    }

}
```



### Filter控制器

```java
package com.zhangyc.controll;

import com.zhangyc.bean.DBProcess;

import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.sql.SQLException;

public class Controller implements Filter {

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest req = (HttpServletRequest) request;
        HttpServletResponse resp = (HttpServletResponse) response;
        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
//        resp.setHeader("Content-Type","text/html;charset=UTF-8");
        String redirect = "";
        String fwd = "";
        DBProcess dbp = new DBProcess(req);
        String action = req.getParameter("action");
        boolean login = false;
        HttpSession session =  req.getSession();
        if(session.getAttribute("login")!=null)
        {
            login=true;
        }
        System.out.println(action);
        if ("save".equals(action))
        {
            System.out.println("save的login   :"+login);
            if (login) {
                try {
                    dbp.save();
                } catch (Exception e) {
                    e.printStackTrace();
                }
                redirect = "/LibMSF/list.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("login".equals(action))
        {
            fwd="login.jsp";
        }

        else if ("check".equals(action))
        {
            System.out.println("check6666666");
            try {
                login = dbp.LoginCheck();
            } catch (Exception e) {
                e.printStackTrace();
            }
            if(login) {
                redirect = "/LibMSF/list.jsp?action=list";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("delete".equals(action))
        {
            if(login) {
                try {
                    dbp.deleteBookById();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                redirect = "/LibMSF/list.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("edit".equals(action))
        {
            if(login) {
                try {
                    dbp.getBookById();
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                fwd = "edit.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("add".equals(action))
        {
            if(login) {
                fwd = "add.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else if ("select".equals(action))
        {
            if(login) {
                String name = req.getParameter("name");
                try {
                    dbp.getBookListByName(name);
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                fwd = "SResult.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }
        else {
            //System.out.println("else里面的：login   " + login);
            if(login)
            {
                try {
                    dbp.getBookList();
                    // System.out.println("执行查询书库完毕");
                } catch (SQLException throwables) {
                    throwables.printStackTrace();
                }
                fwd = "list.jsp";
            }
            else
            {
                fwd="login.jsp";
            }
        }

        if ("".equals(redirect)) {
            req.getRequestDispatcher(fwd).forward(req, resp);
        } else {
            resp.sendRedirect(redirect);
        }
    }


    public void init(FilterConfig filterConfig) throws ServletException {

    }

    public void destroy() {

    }
}
```

### view层代码-过滤器当控制器

add.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>添加图书信息页面</title>
    <style>
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
        input{
            background-color: transparent;
        }
        .btn {
            text-align: center;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: #fff;
            border: #fbc2eb;
            color: black;
            display: block;
            margin: auto;
        }
    </style>
</head>


<body>

<h3>添加图书页面</h3>

<form method="post" action="list.jsp?action=save" onsubmit="return check()">
    <input type="hidden" name="sid" value="${bk.id }">
    <table border="1" width="600">
        <tr>
            <td>ISBN号</td>
            <td><input type="text" name="ISBN" id="1" value="${bk.ISBN }"></td>
            </td>
        </tr>
        <tr>
            <td>书名</td>
            <td><input type="text" name="name" id="2" value="${bk.name}"></td>
        </tr>
        <tr>
            <td>出版社</td>
            <td><input type="text" name="publisher" id="3" value="${bk.publisher }"></td>
        </tr>
        <tr>
            <td>作者</td>
            <td><input type="text" name="author" id="4" value="${bk.author }"></td>
        </tr>

        <tr>
            <td colspan="2"><button type="submit" value="添加" class="btn" >添加 </button></td>
        </tr>
    </table>
    <script>
        function check()
        {
            console.log("调用检查函数");
            if(document.getElementById("1").value=="" || document.getElementById("2").value=="" || document.getElementById("3").value=="" || document.getElementById("4").value=="")
            {
                alert("请完整填写书籍信息后再提交！");
                return false;
            }
            else {
                return true;
            }
        }
    </script>
</form>
</body>
</html>
```

edit.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>更新图书信息页面</title>
    <style>
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
        input{
            background-color: transparent;
        }
        .btn {
            text-align: center;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: #fff;
            border: #fbc2eb;
            color: black;
            display: block;
            margin: auto;
            align: center;

        }
    </style>
</head>


<body>

<h3>更新图书页面</h3>

<form method="post" action="list.jsp?action=save&id=${bk.id}" onsubmit="return check()">
    <input type="hidden" name="sid" value="${bk.id }">
    <table border="1" width="600">
        <tr>
            <td>唯一序列号</td>
            <td><input type="text" name="id" value="${bk.id }" disabled></td>
        </tr>
        <tr>
            <td>ISBN</td>
            <td><input type="text" id="1" name="ISBN" value="${bk.ISBN }"></td>
            </td>
        </tr>
        <tr>
            <td>书名</td>
            <td><input type="text" id="2" name="name" value="${bk.name}"></td>
        </tr>
        <tr>
            <td>出版社</td>
            <td><input type="text" id="3" name="publisher" value="${bk.publisher }"></td>
        </tr>
        <tr>
            <td>作者</td>
            <td><input type="text" id="4" name="author" value="${bk.author }"></td>
        </tr>

        <tr >
            <td colspan="2" style="margin: auto ;align-content: center;align-self: center;align-items: center"><button type="submit" value="更新" class="btn"> 更新</button></td>
        </tr>
    </table>
    <script>
        function check()
        {
            console.log("调用检查函数");
            if(document.getElementById("1").value=="" || document.getElementById("2").value=="" || document.getElementById("3").value=="" || document.getElementById("4").value=="")
            {
                alert("请完整填写书籍信息后再提交！");
                return false;
            }
            else {
                return true;
            }
        }
    </script>
</form>
</body>
</html>

```

index.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>首页</title>
    <style>
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);

        }
        .colortxt{

            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;

        }

    </style>
</head>
<body>
<div style="
    position: absolute;
    left: 50%;top: 50%;
    transform: translate(-50%,-50%); text-align: center;">
    <h2 class="colortxt">欢迎来到图书管理系统</h2>
    <h3><a href="login.jsp?action=login" class="colortxt">点此登陆系统</a></h3><br>

</div>
</body>
</html>

```

list.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>学生列表页面</title>

    <style>
        .colortxt{

            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;

        }
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
        .btn {
            text-align: center;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: #fff;
            border: #fbc2eb;
            color: black;
        }
    </style>

</head>
<body>
<div style="margin: 0 auto">
<form action="SResult.jsp?action=select" method="post">
    <table border="1" width="700">
        <tr >
            <td colspan="8">
                按书名查询:<input type="text" name="name" style="background-color: transparent"/>
            </select>
                <input type="submit" value="查询" class="btn">
                <a href="add.jsp?action=add">添加</a>
            </td>
        </tr>
        <tr align="center">
            <td>唯一序列号</td>
            <td>ISBN</td>
            <td>书名</td>
            <td>出版社</td>
            <td>作者</td>
            <td>管理</td>
        </tr>
        <c:forEach items="${bkList }" var="bk">
            <tr align="center">
                <td>${bk.id }</td>
                <td>${bk.ISBN }</td>
                <td>${bk.name }</td>
                <td>${bk.publisher }</td>
                <td>${bk.author }</td>
                <td><a href="edit.jsp?action=edit&id=${bk.id }">更新</a>   <a  href="list.jsp?id=${bk.id }&action=delete" onclick='return confirm("确认要删除这本书吗？")'>删除</a></td>
            </tr>
        </c:forEach>
    </table>
</form>
</div>

<h2>${pstest}</h2>
</body>
</html>

```

login.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!DOCTYPE html>
<html lang="en">
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>登陆</title>
    <style>
        * {
            margin: 0;
            padding: 0;
        }
        html {
            height: 100%;
        }
        body {
            height: 100%;
        }
        .container {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
        .login-wrapper {
            background-color: #fff;
            width: 358px;
            height: 588px;
            border-radius: 15px;
            padding: 0 50px;
            position: relative;
            left: 50%;
            top: 50%;
            transform: translate(-50%, -50%);
        }
        .header {
            font-size: 38px;
            font-weight: bold;
            text-align: center;
            line-height: 200px;
        }
        .alert {
            font-size: 28px;
            font-weight: bold;
            text-align: center;
            color: red;
        }
        .input-item {
            display: block;
            width: 100%;
            margin-bottom: 20px;
            border: 0;
            padding: 10px;
            border-bottom: 1px solid rgb(128, 125, 125);
            font-size: 15px;
            outline: none;
        }
        .input-item:placeholder {
            text-transform: uppercase;
        }
        .btn {
            text-align: center;
            padding: 10px;
            width: 100%;
            margin-top: 40px;
            background-image: linear-gradient(to right, #a6c1ee, #fbc2eb);
            color: #fff;
            border: #fbc2eb;
        }
        .msg {
            text-align: center;
            line-height: 88px;
        }
        a {
            text-decoration-line: none;
            color: #abc1ee;
        }
    </style>
</head>
<body>
<div class="container">
    <div class="login-wrapper">
        <div class="header">登陆</div>
        <c:if test="${login_msg!=null}">
            <div class="alert">请先登陆!</div>
        </c:if>
        <div class="form-wrapper">
            <form method="post" action="list.jsp?action=check">
            <input type="text" name="username" placeholder="用户名" class="input-item">
            <input type="password" name="password" placeholder="密码" class="input-item">
                <button class="btn" type="submit">登陆</button>
            </form>
        </div>
    </div>
</div>
</body>
</html>

```

SResult.jsp

```jsp
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<%@ taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>查询"${name}的结果"</title>

    <style>
        .colortxt{

            background: linear-gradient(to right, red, blue);
            -webkit-background-clip: text;
            color: transparent;

        }
        body {
            height: 100%;
            background-image: linear-gradient(to right, #fbc2eb, #a6c1ee);
        }
    </style>

</head>
<body>
<div style="margin: 0 auto">
    <form>
        <table border="1" width="700">
            <tr align="center">
                <td>唯一序列号</td>
                <td>ISBN</td>
                <td>书名</td>
                <td>出版社</td>
                <td>作者</td>
                <td>管理</td>
            </tr>

            <c:forEach items="${bkList }" var="bk">
                <tr align="center">
                    <td>${bk.id }</td>
                    <td>${bk.ISBN }</td>
                    <td>${bk.name }</td>
                    <td>${bk.publisher }</td>
                    <td>${bk.author }</td>
                    <td><a href="edit.jsp?action=edit&id=${bk.id }">更新</a>   <a href="list.jsp?id=${bk.id }&action=delete">删除</a></td>
                </tr>
            </c:forEach>
        </table>
    </form>
</div>
<h2>${pstest}</h2>
</body>
</html>

```





