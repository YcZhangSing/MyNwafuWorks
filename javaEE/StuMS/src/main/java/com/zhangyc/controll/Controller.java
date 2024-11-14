package com.zhangyc.controll;

import com.zhangyc.bean.DBProcess;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
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


        if ("save".equals(action))
        {
            try {
                dbp.save();
            } catch (Exception e) {
                e.printStackTrace();
            }
            redirect="/StuMS/Controller";

            //fwd="index.jsp";
        }
        else if ("delete".equals(action))
        {
            try {
                dbp.deleteStuById();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
            redirect="/StuMS/Controller";
        }
        else if ("edit".equals(action))
        {
            try {
                dbp.getStuById();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
            fwd="edit.jsp";
        }
        else if ("add".equals(action))
        {
            fwd="add.jsp";
        }
        else if ("select".equals(action))
        {
            String name = req.getParameter("name");
            try {
                dbp.getStudentListByName(name);
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
            fwd = "SResult.jsp";
        }
        else {
            try {
                dbp.getStudentList();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
            fwd = "list.jsp";
        }

        if ("".equals(redirect)) {
            req.getRequestDispatcher(fwd).forward(req, resp);
//            req.getRequestDispatcher(fwd).forward(arg0, arg1);
        } else {
            resp.sendRedirect(redirect);
        }

    }

}
