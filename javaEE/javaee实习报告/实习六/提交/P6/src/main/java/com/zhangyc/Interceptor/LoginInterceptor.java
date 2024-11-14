package com.zhangyc.Interceptor;

import com.zhangyc.service.UserServiceImpl;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

public class LoginInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserServiceImpl userServiceImpl = (UserServiceImpl) applicationContext.getBean("userServiceImpl");
        HttpSession session = request.getSession();
        if (session.getAttribute("login") != null){
            return true;
        }
        String name = request.getParameter("name");
        String pwd = request.getParameter("pwd");

        if(name == null){
            session.setAttribute("err","没有账号信息，请先登录");

            System.out.println("无账号");
            response.sendRedirect( request.getContextPath() + "/");
            return false;
        }

        String s = userServiceImpl.selectUserByName(name);
        if (s == null || !s.equals(pwd)){
            session.setAttribute("err","账号密码错误");
            System.out.println("账号密码错误");
            response.sendRedirect( request.getContextPath() + "/");
            System.out.println(""+request.getContextPath() + "/");
            return false;
        }else {
            session.setAttribute("login", true);
            System.out.println("账号密码正确");
            session.removeAttribute("error");
        }

        return true;
    }

    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {
        System.out.println("<--拦截器即将运行-->");
    }

    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {
        System.out.println("<--拦截器运行完毕-->");
    }
}
