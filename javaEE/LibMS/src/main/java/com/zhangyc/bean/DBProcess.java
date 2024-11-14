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
