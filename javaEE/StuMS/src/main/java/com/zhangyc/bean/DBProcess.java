package com.zhangyc.bean;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
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
        String insertSQL = "insert into students(name,sex,class) value(?,?,?)";
        String updateSQL = "update students set name=?,sex=?,class=? where id=?";
        ArrayList<String> ps = new ArrayList<String>();
        String id = request.getParameter("id");
        System.out.println("id"+id);
        if(id == null || id.length() == 0)
        {
            request.setCharacterEncoding("UTF-8");
           // ps.add("'"+request.getParameter("name")+"'");
            ps.add(request.getParameter("name"));
            ps.add(request.getParameter("sex"));
            ps.add(request.getParameter("cls"));
            //request.setAttribute("pstest",ps);
            exePrepare(insertSQL,ps);
        }
        else
        {
            request.setCharacterEncoding("UTF-8");
            System.out.println(request.getParameter("name"));
            ps.add(request.getParameter("name"));
            //System.out.println(new String(request.getParameter("name").getBytes("iso-8859-1"), "utf-8"));
            ps.add(request.getParameter("sex"));
            ps.add(request.getParameter("cls"));
            ps.add(id);
            //request.setAttribute("pstest",ps);
            exePrepare(updateSQL,ps);
        }
    }
    //获取学生信息列表方法
    public void getStudentList() throws SQLException{
        String sql = "select * from students;";
        ResultSet rs = getRS(sql);
        ArrayList<Student> stuList = new ArrayList<Student>();
        while(rs.next())
        {
            stuList.add(toStudent(rs));
        }
        request.setAttribute("stuList",stuList);
        closeRS(rs);
    }
    public void getStudentListByName(String n) throws SQLException{
        String sql = "select * from students where name like ";
        sql = sql + "'%" + n + "%'" + ";" ;
        ResultSet rs = getRS(sql);
        ArrayList<Student> stuList = new ArrayList<Student>();
        while(rs.next())
        {
            stuList.add(toStudent(rs));
        }
        request.setAttribute("stuList",stuList);
        System.out.println(stuList);
        closeRS(rs);
    }
    //通过学号获取学生信息并绑定到request对象
    public void getStuById() throws SQLException
    {
        String sql = "select * from students where id=";
        String id = request.getParameter("id");
        sql+=id+";";
        ResultSet rs = getRS(sql);
        if(rs.next())
        {
            Student stu = toStudent(rs);
            request.setAttribute("stu",stu);
        }
    }
    public void deleteStuById() throws SQLException{
        String sql = "delete from students where id=?";
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
    private Student toStudent(ResultSet rs) throws SQLException
    {
        Student stu = new Student();
        stu.setId(rs.getInt("id"));
        stu.setName(rs.getString("name"));
        stu.setSex(rs.getString("sex"));
        stu.setCls(rs.getString("class"));
        return stu;
    }
    //关闭连接
    private void closeRS(ResultSet rs) throws SQLException
    {

        stat.close();
        rs.close();

    }


}
