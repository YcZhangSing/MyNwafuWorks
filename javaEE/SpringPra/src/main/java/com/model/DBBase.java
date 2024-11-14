package com.model;

import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.sql.*;
import java.util.ArrayList;

@Component
public class DBBase {
    @Resource
    DBConnection connection;

    public ResultSet selectAll(String sql) throws SQLException, ClassNotFoundException
    {
        Connection con = connection.getCon();
        Statement stat = con.createStatement();
        ResultSet res = stat.executeQuery(sql);
        return res;
    }
    public void exe(String sql) throws SQLException, ClassNotFoundException
    {
        Connection con = connection.getCon();
        Statement stat = con.createStatement();
        stat.execute(sql);
    }
    public void exePrepare(String sql,  ArrayList<String> params) throws SQLException, ClassNotFoundException {
        Connection con = connection.getCon();
        PreparedStatement pstat = con.prepareStatement(sql);
        int i=1;
        for(String p:params)
        {
            pstat.setString(i++,p);
        }
        pstat.execute();
        pstat.close();
    }
}
