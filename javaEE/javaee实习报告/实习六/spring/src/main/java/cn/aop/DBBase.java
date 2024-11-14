package cn.aop;

import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@Component
public class DBBase {
    static Connection conn;
    static String SELECT_SQL = "select * from student";
    static String UPDATE_SQL = "update student set stu_xh=?, stu_name=?,sex=?,age=? where xh=?";
    static String INSERT_SQL = "insert into student (stu_xh,stu_name,sex,age) values(?,?,?,?)";
    static String DELETE_SQL = "delete from student where stu_xh=?";

    protected Connection  getCon() throws ClassNotFoundException, SQLException {
        if(conn == null){
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            conn = DriverManager.getConnection("jdbc:derby://localhost:1527/demo;");
        }
        return conn;
    }

    public List<Student> stuList() throws SQLException, ClassNotFoundException {
        getCon();
        Statement stat = conn.createStatement();
        ResultSet rs = stat.executeQuery(SELECT_SQL);
        List<Student> stus = new ArrayList<Student>();
        while(rs.next()){
            Student st = new Student();
            st.setXh(rs.getInt("stu_xh"));
            st.setUname(rs.getString("stu_name"));
            st.setAge(rs.getInt("age"));
            st.setSex(rs.getString("sex"));
            stus.add(st);
        }
        return  stus;
    }

    public Student get(Integer xh) throws SQLException, ClassNotFoundException {
        getCon();
        PreparedStatement pstat = conn.prepareStatement("select * from student where xh = ?");
        pstat.setInt(1,xh);
        ResultSet rs = pstat.executeQuery();
        Student st = new Student();
        if (rs.next()){
            st.setXh(rs.getInt("xh"));
            st.setUname(rs.getString("uname"));
            st.setAge(rs.getInt("age"));
            st.setSex(rs.getString("sex"));
        }
        return st;
    }

    public void insert(Student stu) throws SQLException, ClassNotFoundException {
        getCon();
        PreparedStatement pstat = conn.prepareStatement(INSERT_SQL);
        pstat.setInt(1,stu.getXh());
        pstat.setString(2,stu.getUname());
        pstat.setString(3,stu.getSex());
        pstat.setInt(4,stu.getAge());
        pstat.execute();
    }

    public void delete(Integer xh) throws SQLException, ClassNotFoundException {
        getCon();
        PreparedStatement pstat = conn.prepareStatement(DELETE_SQL);
        pstat.setInt(1,xh);
        pstat.execute();
    }

    public void update(Student stu, Integer oldxh) throws SQLException, ClassNotFoundException {
        getCon();
        PreparedStatement pstat = conn.prepareStatement(UPDATE_SQL);
        pstat.setInt(1,stu.getXh());
        pstat.setString(2,stu.getUname());
        pstat.setString(3,stu.getSex());
        pstat.setInt(4,stu.getAge());
        pstat.setInt(5,oldxh);
        pstat.execute();
    }
}
