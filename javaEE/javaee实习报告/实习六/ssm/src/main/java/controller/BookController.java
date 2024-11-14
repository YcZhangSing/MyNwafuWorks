package controller;

import entity.Book;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import services.BookService;

@Controller
@RequestMapping("/book")
public class BookController {
    @Autowired
    BookService bookService;

    @RequestMapping("/list")
    public String list(Model model){
        model.addAttribute("books",bookService.list());
        return "/list.jsp";
    }

    @RequestMapping("/edit")
    public String getOne(Integer id,Model model){
        model.addAttribute("book",bookService.getById(id));
        return "/edit.jsp";
    }

    @RequestMapping("/save")
    public String save(Book book){
        bookService.save(book);
        return "/list.jsp";
    }
    @RequestMapping("/add")
    public String add(){
        return "/edit.jsp";
    }

    @RequestMapping("/delete")
    public String del(Integer id){
        bookService.deleteById(id);
        return "/list.jsp";
    }
}
