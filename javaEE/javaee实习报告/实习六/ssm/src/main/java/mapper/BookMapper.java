package mapper;

import entity.Book;
import lombok.Data;
import org.apache.ibatis.annotations.*;

import java.util.List;

public interface BookMapper {
    @Select("select * from book")
    List<Book> list();

    @Select("select * from book where id = #{id}")
    Book getById(@Param("id") Integer id);

    @Insert("insert into book set name=#{bookName},author=#{author},price=#{price}")
    void insert(Book book);

    @Update("update book set name=#{bookName},author=#{author},price=#{price} where id = #{id}")
    void update(Book book);

    @Delete("delete from book where id = #{id}")
    void deleteById(@Param("id")Integer id);
}
