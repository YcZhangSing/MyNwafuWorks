package com.main;

import com.entity.User;
import com.model.DBBase;
import com.model.DBConnection;
import com.model.UserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.sql.SQLException;
import java.util.List;

public class Main {
    public static void main(String[] argv) throws Exception {
        ApplicationContext context = new ClassPathXmlApplicationContext("spring-config.xml");
        UserService userService = context.getBean(UserService.class);

//        DBConnection dc = context.getBean(DBConnection.class);
        System.out.println("User表初始状态：");
        List<User> test = userService.list();
        if(test!=null) {
            for (int i = 0; i < test.size(); ++i) {
                System.out.println(test.get(i));
            }
        }
        userService.AddNewUser("wzx","123");
        System.out.println("User表增加记录后的状态：");
        test = userService.list();
        if(test!=null) {
        for (int i = 0;i<test.size();++i)
        {
            System.out.println(test.get(i));
        }}
        userService.AlterUser(14,"WZX","666");
        System.out.println("User表修改记录后的状态：");
        test = userService.list();
        if(test!=null) {
        for (int i = 0;i<test.size();++i)
        {
            System.out.println(test.get(i));
        }}
        userService.deletebyid(14);
        System.out.println("User表删除记录后的状态：");
        test = userService.list();
        if(test!=null) {
        for (int i = 0;i<test.size();++i)
        {
            System.out.println(test.get(i));
        }}
    }
}
