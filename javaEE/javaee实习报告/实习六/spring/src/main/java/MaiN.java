
import cn.aop.DBBase;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.sql.SQLException;

public class MaiN {
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        ApplicationContext ctx =
                new ClassPathXmlApplicationContext("spring-config.xml");
        DBBase db = ctx.getBean(DBBase.class);
        System.out.println(db.stuList());
    }
}
