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
