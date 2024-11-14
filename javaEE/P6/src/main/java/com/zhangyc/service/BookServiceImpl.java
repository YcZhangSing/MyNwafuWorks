package com.zhangyc.service;

import com.zhangyc.Mapper.BookMapper;
import com.zhangyc.pojo.Book;

import java.util.List;

public class BookServiceImpl implements BookService{

    private BookMapper mapper;


    public int addBook(Book book) {
        return mapper.addBook(book);
    }

    public int deleteBook(int id) {
        return mapper.deleteBook(id);
    }

    public int updateBook(Book book) {
        return mapper.updateBook(book);
    }

    public Book selectBookById(int id) {
        return mapper.selectBookById(id);
    }

    public List<Book> selectAllBook() {
        return mapper.selectAllBook();
    }

    @Override
    public List<Book> selectBookByName(String bookName) {
        return mapper.selectBookByName(bookName);
    }

    public BookMapper getMapper() {
        return mapper;
    }

    public void setMapper(BookMapper mapper) {
        this.mapper = mapper;
    }
}
