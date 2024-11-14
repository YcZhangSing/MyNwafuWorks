package com.zhangyc.Mapper;

import com.zhangyc.pojo.Book;

import java.util.List;


public interface BookMapper {
    //增
    int addBook(Book book);

    //删
    int deleteBook(int id);

    //改
    int updateBook(Book book);

    //查一本书
    Book selectBookById(int id);

    //查全部书
    List<Book> selectAllBook();

    List<Book> selectBookByName(String bookName);
}
