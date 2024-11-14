package com.model;

import com.entity.User;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

@Service
public class UserService {
    @Resource
    DBBase dbBase;
    static String SELECTSQL = "select * from user";
 
    public List<User> list() throws SQLException, ClassNotFoundException
    {
        ResultSet rs = dbBase.selectAll(SELECTSQL);
        List<User> users = new ArrayList<User>();
        while (rs.next()){
            User user = new User();
            user.setId(rs.getInt("id"));
            user.setUserName(rs.getString("user_name"));
            user.setPasswd(rs.getString("passwd"));
            users.add(user);
        }
        return users;
    }
    public void deletebyid(int id) throws SQLException, ClassNotFoundException
    {
        String SQL="delete from user where id="+id+";";
        dbBase.exe(SQL);
    }

    public void AddNewUser(String name, String pwd) throws Exception{
        String insertSQL = "insert into user(user_name,passwd) value(?,?)";
        ArrayList<String> ps = new ArrayList<String>();


            // ps.add("'"+request.getParameter("name")+"'");
            ps.add(name);
            ps.add(pwd);

            dbBase.exePrepare(insertSQL,ps);
        }
    public boolean AlterUser(int id,String name, String pwd) throws Exception
    {
        String insertSQL = "update user set user_name=?,passwd=? where id=?";
        ArrayList<String> ps = new ArrayList<String>();


        // ps.add("'"+request.getParameter("name")+"'");
        ps.add(name);
        ps.add(pwd);
        ps.add(String.valueOf(id));
        dbBase.exePrepare(insertSQL,ps);
        return true;
    }
}
