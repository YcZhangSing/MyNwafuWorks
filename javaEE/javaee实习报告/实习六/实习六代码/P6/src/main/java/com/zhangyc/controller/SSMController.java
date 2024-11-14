package com.zhangyc.controller;

import com.zhangyc.pojo.Book;
import com.zhangyc.service.BookService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.List;

@Controller
@RequestMapping("/book")
public class SSMController {
    @Autowired
    @Qualifier("bookServiceImpl")
    private BookService bookService;

    //查询全部书籍
    @RequestMapping("/allBook")
    public String list(Model model){
        List<Book> books = bookService.selectAllBook();
        model.addAttribute("list", books);

        return "allBook";
    }

    //跳转到增加书籍
    @RequestMapping("/toAddBook")
    private String toAddBookPage(){
        return "addBook";
    }

    //添加书籍的请求
    @RequestMapping("/addBook")
    public String addBookByPage(Book book){
        System.out.println("addBook=>"+book);
        bookService.addBook(book);
        return "redirect:/book/allBook";
    }

    //跳转到修改页面
    @RequestMapping("/toUpdateBook")
    public String toUpdateBookPage(int id, Model model){
        Book book = bookService.selectBookById(id);
        model.addAttribute("book", book);
        return "updateBook";
    }

    @RequestMapping("/updateBook")
    public String updateBook(Book book){
        System.out.println("updateBook=>"+ book);
        bookService.updateBook(book);
        return "redirect:/book/allBook";
    }

    @RequestMapping("/deleteBook")
    public String deleteBook(int id){
        System.out.println("deleteBook=>"+id);
        bookService.deleteBook(id);
        return "redirect:/book/allBook";
    }

    @RequestMapping("/selectBookByName")
    public String selectBookByName(String bookName, Model model){
        List<Book> books = bookService.selectBookByName(bookName);;
        if (books.isEmpty()){
            model.addAttribute("errorr", "未找到");
            books = bookService.selectAllBook();
        }

        model.addAttribute("list", books);
        return "allBook";
    }
}
