package com.model;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.sql.SQLException;
import java.util.ArrayList;

@Aspect
@Component
public class LogAop
{
    @Resource
    DBBase dbBase;
    @Pointcut(value = "execution(* com.model.UserService.*(..))")
    public void cutPoint(){}

    @After("cutPoint()")
    public void log(JoinPoint point) throws SQLException, ClassNotFoundException
    {

        String process = "exe:"+point.getSignature();
        String insertSQL = "insert into SpringLog(pro) value(?)";
        ArrayList<String> ps = new ArrayList<String>();
        ps.add(process);
        dbBase.exePrepare(insertSQL,ps);
    }
//    @Around("cutPoint()")
//    public void around(ProceedingJoinPoint pjp) throws Throwable {
//        long s = System.currentTimeMillis();
//        Object obj = pjp.proceed();
//        long e = System.currentTimeMillis();
//        System.out.println(s - e);
//    }

}
