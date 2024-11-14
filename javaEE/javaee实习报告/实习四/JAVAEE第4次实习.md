# Java EE 第四次实习 MyBatis

|  课程   |  姓名  |    学号    |    班级    |
| :-----: | :----: | :--------: | :--------: |
| Java EE | 张宇晨 | 2020012249 | 软工2001班 |



[toc]

## 开发环境与工程结构

Intellij IDEA 2020.2

<img src="C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221015213903081.png" alt="image-20221015213903081" style="zoom:55%;" />

工程结构

![image-20221118104548121](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118104548121.png)

## 实现内容

### 1. 创建book表

id自增，由数据库auto_increment方式实现

![image-20221118104620907](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118104620907.png)

初始数据填充

![image-20221118104739366](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118104739366.png)

### 2. 主配置文件

![image-20221118105641601](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118105641601.png)

### 3. 映射文件增删改查

#### （1）声明——BookMapper.java

![image-20221118105003278](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118105003278.png)

#### （2）定义——BookMapper.xml

![image-20221118105158465](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118105158465.png)

#### （3）测试

测试代码：

```java
public static void main(String argc[]) throws IOException {
        //主配置文件
        InputStream is = Resources.getResourceAsStream("Mybatis-config.xml");
        //创建SQL会话工厂，读取主配置文件建立数据库连接
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        //打开一个数据库会话
        SqlSession session = ssf.openSession();
        //通过getMapper方法获得mapper接口的的代理对象，通过mapper调用mapper接口中定义的方法
        BookMapper mapper = session.getMapper(BookMapper.class);       
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
        session.close();
    }
```

测试结果：

![image-20221118115307511](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118115307511.png)

### 4.注解增删改查

#### （1）定义

```java
    //基于注解
    @Select("select * from books")
    List<Book> zjgetbooklist();

    @Select("select * from books where author = #{author}")
        //查询
    Book getByAuthor(String author);

    //增加书籍
    @Insert("insert into books(ISBN,name,publisher,author,price,pdate ) values (#{ISBN},#{name},#{publisher},#{author},#{price},#{pdate})")
    void zjadd(@Param("ISBN") String ISBN, @Param("name") String name,
               @Param("publisher") String publisher, @Param("author") String author, @Param("price") float price, @Param("pdate") String pdate);

    //更新书籍
    @Update("update books set ISBN=#{ISBN}, name=#{name}, publisher=#{publisher}, author=#{author}, price=#{price}, pdate=#{pdate} \n" +
            "        where id=#{id}")
    void zjupdate(@Param("id") int id, @Param("name") String name, @Param("ISBN") String ISBN, @Param("author") String author,
                  @Param("publisher") String publisher, @Param("price") float price, @Param("pdate") String pdate);//改

    //删除
    @Delete("delete from books where name=#{name}")
    void zjdelbyname(String name);
```

#### （2）测试

测试代码：

```java
public static void main(String argc[]) throws IOException {
        //主配置文件
        InputStream is = Resources.getResourceAsStream("Mybatis-config.xml");
        //创建SQL会话工厂，读取主配置文件建立数据库连接
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        //打开一个数据库会话
        SqlSession session = ssf.openSession();
        //通过getMapper方法获得mapper接口的的代理对象，通过mapper调用mapper接口中定义的方法
        BookMapper mapper = session.getMapper(BookMapper.class);       
        System.out.println("---基于注解的操作：");
        System.out.println("查询书籍列表:");
                List<HashMap<String, Object>> bl = mapper.listAll();
        for(int i=0;i<bl.size();++i)
        {
            System.out.println(bl.get(i).toString());
        }
        System.out.println("按照作者查询书籍:");
        System.out.println(mapper.getByAuthor("邹青").toString());
        System.out.println("插入测试书籍__zjTest1,zjTest1,nwafu,zyc");
        mapper.zjadd("98-09-44","zjtest","nwafu","zyc",(float)78.2,"2020-10-12");
        System.out.println("查询插入结果");
        System.out.println(mapper.getByAuthor("zyc").toString());
        System.out.println("测试更新书籍__35,\"12345\",\"张宇晨\",\"西北农林科技大学\"");
        mapper.zjupdate(12,"注解测试书1","9090","张宇晨","西北农林科技大学",(float)78.2,"2020-10-12");
        System.out.println("查询更新结果：");
        System.out.println(mapper.getById(12).toString());
        System.out.println("测试删除");
        session.close();
    }
```



测试结果：

![image-20221118113334879](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118113334879.png)

### 5.动态SQL

#### （1）定义

```xml
    <select id="DtSQL" parameterType="map" resultType="com.zhangyc.bean.Book">
        select  * from books where 1=1
        <if test="name!=null and name!=''">and book_name like concat('%',#{name},'%')</if>
        <if test="author!=null and author!=''">and author like concat('%',#{author},'%')</if>
        <if test="publisher!=null and publisher!=''">and publisher like concat('%',#{publisher},'%')</if>
        <if test="ISBN!=null and ISBN!=''">and ISBN like concat('%',#{ISBN},'%') </if>
        <if test="price!=null and price!=''">and price between #{price}-20.0 and #{price}+20.0 </if>
        <if test="pdate!=null and pdate!=''">and pdate between date_add('${pdate}',INTERVAL -365 DAY) and date_add('${pdate}',INTERVAL 365 DAY)</if>

    </select>
```



#### （2）测试

测试代码：

```java
public static void main(String argc[]) throws IOException {
        //主配置文件
        InputStream is = Resources.getResourceAsStream("Mybatis-config.xml");
        //创建SQL会话工厂，读取主配置文件建立数据库连接
        SqlSessionFactory ssf = new SqlSessionFactoryBuilder().build(is);
        //打开一个数据库会话
        SqlSession session = ssf.openSession();
        //通过getMapper方法获得mapper接口的的代理对象，通过mapper调用mapper接口中定义的方法
        BookMapper mapper = session.getMapper(BookMapper.class);       
		System.out.println("执行动态SQL前的数据库状态");
        List<HashMap<String, Object>> bl = mapper.listAll();
        for(int i=0;i<bl.size();++i)
        {
            System.out.println(bl.get(i).toString());
        }

        Map map = new HashMap();
        System.out.println("加入时间2020-10-1");
        map.put("pdate","2020-10-1");
        List<Book> lb = mapper.DtSQL(map);
        for(int i=0;i<lb.size();++i)
        {
            System.out.println(lb.get(i).toString());
        }
        System.out.println("加入出版社模糊查询——清华");
        map.put("publisher","清华");
        lb = mapper.DtSQL(map);
        for(int i=0;i<lb.size();++i)
        {
            System.out.println(lb.get(i).toString());
        }
        System.out.println("加入出版社模糊查询——价格90");
        map.put("price",90.0);
        lb = mapper.DtSQL(map);
        for(int i=0;i<lb.size();++i)
        {
            System.out.println(lb.get(i).toString());
        }
        session.close();
    }
```

测试结果：

![image-20221118111516459](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20221118111516459.png)

## 附录

JavaBean代码

```java
package com.zhangyc.bean;

public class Book {
    private int id;
    private String ISBN;
    private String name;
    private String publisher;
    private String author;
    private float price;
    private String pdate;

    public int getId() {
        return id;
    }

    public float getPrice() {
        return price;
    }

    public String getPdate() {
        return pdate;
    }

    public void setPrice(float price) {
        this.price = price;
    }



    public void setId(int id) {
        this.id = id;
    }

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPublisher() {
        return publisher;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    @Override
    public String toString() {
        return "Book{" +
                "id=" + id +
                ", ISBN='" + ISBN + '\'' +
                ", name='" + name + '\'' +
                ", publisher='" + publisher + '\'' +
                ", author='" + author + '\'' +
                ", price=" + price +
                ", pdate='" + pdate + '\'' +
                '}';
    }

    public void setPdate(String pdate) {
        this.pdate = pdate;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }



    public Book() {
    }
}

```

主配置文件

Mybatis-config.xml

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<!--核心配置文件-->
<configuration>
<!--    <settings>-->
<!--        &lt;!&ndash; 打印查询语句 &ndash;&gt;-->
<!--        <setting name="logImpl" value="STDOUT_LOGGING" />-->
<!--    </settings>-->
    <environments default="development">
    <environment id="development">
    <transactionManager type="JDBC"/>
    <dataSource type="POOLED">
        <property name="driver" value="com.mysql.cj.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://81.70.54.158:3306/JavaEEPtc?useUnicode=true&amp;characterEncoding=utf8&amp;useSSL=true"/>
                <property name="username" value="root"/>
                <property name="password" value="zyc123456"/>
    </dataSource>
    </environment>
    </environments>

    <mappers>
        <mapper resource="mappers/BookMapper.xml"/>
    </mappers>

</configuration>

```

映射配置

BookMapper.java

```java
package com.zhangyc.mapper;

import com.zhangyc.bean.Book;
import org.apache.ibatis.annotations.*;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public interface BookMapper {


    //基于配置文件
    List<HashMap<String, Object>> listAll();//查

    Book getById(Integer id);//查

    Book getByISBN(String ISBN);//查

    void add(Map map);//增

    void delbyid(Integer id);//删除

    void update(Map map);//改

    List<Book> DtSQL(Map map);//动态sql


    //基于注解
    @Select("select * from books")
    List<Book> zjgetbooklist();

    @Select("select * from books where author = #{author}")
        //查询
    Book getByAuthor(String author);

    //增加书籍
    @Insert("insert into books(ISBN,name,publisher,author,price,pdate ) values (#{ISBN},#{name},#{publisher},#{author},#{price},#{pdate})")
    void zjadd(@Param("ISBN") String ISBN, @Param("name") String name,
               @Param("publisher") String publisher, @Param("author") String author, @Param("price") float price, @Param("pdate") String pdate);

    //更新书籍
    @Update("update books set ISBN=#{ISBN}, name=#{name}, publisher=#{publisher}, author=#{author}, price=#{price}, pdate=#{pdate} \n" +
            "        where id=#{id}")
    void zjupdate(@Param("id") int id, @Param("name") String name, @Param("ISBN") String ISBN, @Param("author") String author,
                  @Param("publisher") String publisher, @Param("price") float price, @Param("pdate") String pdate);//改

    //删除
    @Delete("delete from books where name=#{name}")
    void zjdelbyname(String name);


}
```

BookMapper.xml

```xml
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE mapper PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN" "http://mybatis.org/dtd/mybatis-3-mapper.dtd" >
<mapper namespace="com.zhangyc.mapper.BookMapper">


    <select id="listAll" resultType="hashmap">
        select * from books
    </select>

    <select id="getById" parameterType="int" resultType="com.zhangyc.bean.Book">
        select  * from books where id= #{id}
    </select>
    <select id="getByISBN" parameterType="String" resultType="com.zhangyc.bean.Book">
        select * from books where ISBN=#{ISBN}
    </select>

    <insert id="add" parameterType="map">
        insert into books(ISBN,name,publisher,author,price,pdate) values(#{ISBN}, #{name}, #{publisher}, #{author},#{price},#{pdate})
    </insert>

    <delete id="delbyid" parameterType="int">
        delete from books where id = #{id}
    </delete>

    <update id="update" parameterType="map">
        update books set ISBN = #{ISBN},book.name=#{name}, publisher=#{publisher},author=#{author},price=#{price},pdate=#{pdate}
        where id=#{id}
    </update>

    <!--动态SQL-->
    <select id="DtSQL" parameterType="map" resultType="com.zhangyc.bean.Book">
        select  * from books where 1=1
        <if test="name!=null and name!=''">and book_name like concat('%',#{name},'%')</if>
        <if test="author!=null and author!=''">and author like concat('%',#{author},'%')</if>
        <if test="publisher!=null and publisher!=''">and publisher like concat('%',#{publisher},'%')</if>
        <if test="ISBN!=null and ISBN!=''">and ISBN like concat('%',#{ISBN},'%') </if>
        <if test="price!=null and price!=''">and price between #{price}-20.0 and #{price}+20.0 </if>
        <if test="pdate!=null and pdate!=''">and pdate between date_add('${pdate}',INTERVAL -365 DAY) and date_add('${pdate}',INTERVAL 365 DAY)</if>

    </select>

</mapper>

```

测试-Main

Main.java

```java
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
        //插入
        System.out.println("添加新书，ISBN=123，书名=测试一，出版社=西农出版社，作者=作者一:");
        Map map = new HashMap();
        map.put("ISBN","123");
        map.put("name","测试一");
        map.put("publisher","西农出版社");
        map.put("author","作者一");
        mapper.add(map);
        System.out.println("插入结果：");
        System.out.println(mapper.getByISBN("123").toString());
        //删除
        System.out.println("删除id=25的书籍：");
        mapper.delbyid(30);
        System.out.println("删除结果：");
        if(mapper.getById(30)==null)
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

//动态SQL操作
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
```





