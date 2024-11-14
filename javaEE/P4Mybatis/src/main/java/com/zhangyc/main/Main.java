package com.zhangyc.main;

import com.zhangyc.bean.Book;
import com.zhangyc.mapper.BookMapper;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class Main {
    public static void main(String argc[]) throws IOException {

        //主配置文件
        InputStream is = Resources.getResourceAsStream("Mybatis-config.xml");
        //创建SQL会话工厂，读取主配置文件建立数据库连接
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        //打开一个数据库会话
        SqlSession session = ssf.openSession();
        //通过getMapper方法获得mapper接口的的代理对象，通过mapper调用mapper接口中定义的方法
        BookMapper mapper = session.getMapper(BookMapper.class);

////基于配置文件的数据库操作
        System.out.println("---基于配置文件的操作：");
        //查询
        System.out.println("查询书籍列表:");
        List<HashMap<String, Object>> bl = mapper.listAll();
        for(int i=0;i<bl.size();++i)
        {
            System.out.println(bl.get(i).toString());
        }
        System.out.println("查询id=1的书:");
        System.out.println(mapper.getById(1).toString());
        //增
        System.out.println("添加新书，ISBN=123，书名=测试一，出版社=西农出版社，作者=作者一:");
        Map map = new HashMap();
        map.put("ISBN","123");
        map.put("name","测试一");
        map.put("publisher","西农出版社");
        map.put("author","作者一");
        map.put("price",89.0);
        map.put("pdate","2020-1-1");
        mapper.add(map);
        System.out.println("插入结果：");
        System.out.println(mapper.getByISBN("123").toString());
        //改
        System.out.println("修改新插入的书");
        map.put("ISBN","11-22-33");
        map.put("id",20);
        mapper.update(map);
        System.out.println("修改结果：");
        System.out.println(mapper.getByISBN("11-22-33").toString());
        //删除
        System.out.println("删除id=18的书籍：");
        mapper.delbyid(20);
        System.out.println("删除结果：");
        if(mapper.getById(20)==null)
        {
            System.out.println("删除成功");
        }
////基于注解的数据库操作
//
//        System.out.println("---基于注解的操作：");
//        System.out.println("查询书籍列表:");
//                List<HashMap<String, Object>> bl = mapper.listAll();
//        for(int i=0;i<bl.size();++i)
//        {
//            System.out.println(bl.get(i).toString());
//        }
//        System.out.println("按照作者查询书籍:");
//        System.out.println(mapper.getByAuthor("邹青").toString());
//        System.out.println("插入测试书籍__zjTest1,zjTest1,nwafu,zyc");
//        mapper.zjadd("98-09-44","zjtest","nwafu","zyc",(float)78.2,"2020-10-12");
//        System.out.println("查询插入结果");
//        System.out.println(mapper.getByAuthor("zyc").toString());
//        System.out.println("测试更新书籍__35,\"12345\",\"张宇晨\",\"西北农林科技大学\"");
//        mapper.zjupdate(12,"注解测试书1","9090","张宇晨","西北农林科技大学",(float)78.2,"2020-10-12");
//        System.out.println("查询更新结果：");
//        System.out.println(mapper.getById(12).toString());
//        System.out.println("测试删除");
//        mapper.zjdelbyname("注解测试书1");

//动态SQL
//        System.out.println("执行动态SQL前的数据库状态");
//        List<HashMap<String, Object>> bl = mapper.listAll();
//        for(int i=0;i<bl.size();++i)
//        {
//            System.out.println(bl.get(i).toString());
//        }
//
//        Map map = new HashMap();
//        System.out.println("加入时间2020-10-1");
//        map.put("pdate","2020-10-1");
//        List<Book> lb = mapper.DtSQL(map);
//        for(int i=0;i<lb.size();++i)
//        {
//            System.out.println(lb.get(i).toString());
//        }
//        System.out.println("加入出版社模糊查询——清华");
//        map.put("publisher","清华");
//        lb = mapper.DtSQL(map);
//        for(int i=0;i<lb.size();++i)
//        {
//            System.out.println(lb.get(i).toString());
//        }
//        System.out.println("加入价格模糊查询——价格90");
//        map.put("price",90.0);
//        lb = mapper.DtSQL(map);
//        for(int i=0;i<lb.size();++i)
//        {
//            System.out.println(lb.get(i).toString());
//        }
        session.close();
    }
}
