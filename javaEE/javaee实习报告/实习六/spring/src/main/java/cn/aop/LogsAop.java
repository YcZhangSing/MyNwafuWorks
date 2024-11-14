package cn.aop;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class LogsAop {
    @Pointcut("execution(* cn.aop.DBBase.*(..))")
    public void pt(){}

    @Before("pt()")
    public void before(JoinPoint jp){
        System.out.println(jp.getSignature().getName() + ",before.....");
    }
    @Around("pt()")
    public Object around(ProceedingJoinPoint pjp) throws Throwable {
        long start = System.currentTimeMillis();
        Object obj = pjp.proceed();
        long end = System.currentTimeMillis();
        System.out.println("coast Time: " + (end - start));
        return obj;
    }
}
