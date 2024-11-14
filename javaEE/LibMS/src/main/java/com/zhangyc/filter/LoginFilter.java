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
