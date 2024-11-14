package com.zhangyc.controll;


import com.zhangyc.bean.DBProcess;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.SQLException;

//@WebFilter(filterName = "log",urlPatterns = "")
public class FilterCtrl implements Filter {
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws IOException, ServletException {
        //1.强制转换
        HttpServletRequest request = (HttpServletRequest) req;
        HttpServletResponse response = (HttpServletResponse) resp;
//        String requestURI = request.getRequestURI();
        req.setCharacterEncoding("UTF-8");
        resp.setCharacterEncoding("UTF-8");
        String redirect = "";
        String fwd = "";
        DBProcess dbp = new DBProcess(request);
        String action = req.getParameter("action");
        if ("save".equals(action))
        {
            try {
                dbp.save();
            } catch (Exception e) {
                e.printStackTrace();
            }
            redirect="/StuMSF/list.jsp";

            //fwd="index.jsp";
        }
        else if ("delete".equals(action))
        {
            try {
                dbp.deleteStuById();
            } catch (SQLException throwables) {
                throwables.printStackTrace();
            }
            redirect="/StuMSF/list.jsp";
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
        } else {
            response.sendRedirect(redirect);
        }

    }

    public void destroy() {

    }
}
