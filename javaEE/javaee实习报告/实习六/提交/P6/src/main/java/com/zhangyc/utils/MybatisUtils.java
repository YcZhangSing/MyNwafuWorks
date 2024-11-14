package com.zhangyc.utils;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;

//sqlSession工具类
public class MybatisUtils {
    private static SqlSessionFactory sqlSessionFactory;
    static {
        try{
            //mybatis配置文件
            String resources = "mybatis-config.xml";
            InputStream inputStream = Resources.getResourceAsStream(resources);
            sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
        } catch(IOException e){
            e.printStackTrace();
        }
    }

    public  static SqlSession getSqlSession(){
        return sqlSessionFactory.openSession();
    }
}