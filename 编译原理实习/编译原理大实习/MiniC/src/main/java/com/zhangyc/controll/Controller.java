package com.zhangyc.controll;

import com.zhangyc.bean.MiniProcess;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

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


        String action = req.getParameter("action");
        System.out.println("收到action："+action);
        String input = req.getParameter("input");
        System.out.println("收到input："+input);
        if ("cifa".equals(action))
        {
            MiniProcess mp = new MiniProcess(req);

            try {
                mp.tofile(input);
                mp.cifa();
            } catch (Exception e) {
                e.printStackTrace();
            }
//            redirect="/StuMS/Controller";

            fwd="main.jsp";
        }
        else if ("yufa".equals(action))
        {
            MiniProcess mp = new MiniProcess(req);
            try {
                mp.tofile(input);
                mp.yufa();
            } catch (Exception e) {
                e.printStackTrace();
            }
//            redirect="/StuMS/Controller";

            fwd="main.jsp";
        }
        else if ("yuyi".equals(action))
        {
            MiniProcess mp = new MiniProcess(req);
            try {
                mp.tofile(input);
                mp.yuyi();
            } catch (Exception e) {
                e.printStackTrace();
            }


            fwd="main.jsp";
        }

        else if ("bl".equals(action))
        {
            MiniProcess mp = new MiniProcess(req);
            try {
                mp.tofile(input);
                mp.chartable();
            } catch (Exception e) {
                e.printStackTrace();
            }
//            redirect="/StuMS/Controller";

            fwd="main.jsp";
        }

        else {
//            try {
//                dbp.getStudentList();
//            } catch (SQLException throwables) {
//                throwables.printStackTrace();
//            }
            fwd = "main.jsp";
        }

        if ("".equals(redirect)) {
            req.getRequestDispatcher(fwd).forward(req, resp);
        } else {
            resp.sendRedirect(redirect);
        }

    }

}
