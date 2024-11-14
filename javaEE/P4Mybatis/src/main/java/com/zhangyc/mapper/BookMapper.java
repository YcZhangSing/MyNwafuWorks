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

//    动态SQL
//    @Select(
//            "<script>"+
//             "select * "+
//             "from books"+
//            "<where>"+
//            "<if test='name != null'>"+
//            "and name like concat('%'+#{name}+'%')"+
//             "</if>"+
//            "</where>"+
//            "</script>"
//    );

}


