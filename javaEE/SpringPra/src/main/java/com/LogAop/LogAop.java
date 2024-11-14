package com.LogAop;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class LogAop {
    @Pointcut(value = "execution(* com.model.*Service.*(..))")
    public void cutPoint(){}

    @After(value = "cutPoint()")
    public void log(JoinPoint point){
        System.out.println(point.getSignature() + "方法被执行.....");
    }
}
