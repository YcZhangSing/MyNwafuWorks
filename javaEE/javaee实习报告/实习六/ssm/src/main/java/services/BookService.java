package services;

import entity.Book;
import mapper.BookMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class BookService {
    @Autowired
    BookMapper bookMapper;

    public List<Book> list(){
        return bookMapper.list();
    }

    public Book getById(Integer id){
        return bookMapper.getById(id);
    }

    public void save(Book book){
        if(book.getId() == null){
            bookMapper.insert(book);
        }
        else {
            bookMapper.update(book);
        }
    }

    public void deleteById(Integer id){
        bookMapper.deleteById(id);
    }
}
