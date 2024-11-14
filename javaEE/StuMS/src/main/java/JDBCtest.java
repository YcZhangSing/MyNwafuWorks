
import java.sql.*;

public class JDBCtest {
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
        String x ="张宇晨";
        System.out.print("'"+x+"'");
//        1.加载驱动
        Class.forName("com.mysql.cj.jdbc.Driver");
//        2.用户信息和url
        String url = "jdbc:mysql://81.70.54.158:3306/sb?useUnicode=true&characterEncoding=utf8&useSSL=true";
        String username="root";
        String password="zyc123456";
//        3.连接成功，数据库对象 Connection
        Connection connection = DriverManager.getConnection(url,username,password);
//        4.执行SQL对象Statement，执行SQL的对象
        Statement statement = connection.createStatement();
//        5.执行SQL的对象去执行SQL，返回结果集
        String sql = "insert into students(name,sex,class) value('王升亮3','女','园艺2001班')";
        statement.executeUpdate(sql);

//        6.释放连接

        statement.close();
        connection.close();
    }
}

