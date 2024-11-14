import com.zhangyc.Mapper.BookMapper;
import com.zhangyc.pojo.Book;
import com.zhangyc.service.UserServiceImpl;
import com.zhangyc.utils.MybatisUtils;
import org.apache.ibatis.session.SqlSession;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.List;

public class mytest {
    @Test
    public void test(){
        SqlSession sqlSession = MybatisUtils.getSqlSession();
        BookMapper mapper = sqlSession.getMapper(BookMapper.class);
        List<Book> books = mapper.selectAllBook();
        for (Book book : books) {
            System.out.println(book);
        }
    }

    @Test
    public void user(){
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserServiceImpl userServiceImpl = (UserServiceImpl) applicationContext.getBean("userServiceImpl");
        String s = userServiceImpl.selectUserByName("123456");
        System.out.println(s);
    }
}
