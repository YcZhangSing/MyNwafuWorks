package clone;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class Student implements Cloneable,Serializable{
	String name;
	Student(String name){
		this.name = name;
	}
	
	public static void serializableTest() throws IOException, ClassNotFoundException {
	
		ByteArrayOutputStream baos = new ByteArrayOutputStream(1024);
		ObjectOutputStream    oos = new ObjectOutputStream(baos);
		
		Student zhang = new Student("张三");
		oos.writeObject(zhang);
		
		byte [] buf = baos.toByteArray();
		ByteArrayInputStream bais = new ByteArrayInputStream(buf);
		ObjectInputStream    bis = new ObjectInputStream(bais);
		
		Student zhangCopy = (Student)bis.readObject();
		zhangCopy.name = "张四";
		System.out.println(zhang.name);
		System.out.println(zhangCopy.name);
		System.out.println(zhang == zhangCopy);  		 //false
		System.out.println(zhang.name == zhangCopy.name);//false
	}
	
	
	
	public static void cloneTest() throws CloneNotSupportedException {
		// 想要调用clone()方法实现复制对象，需要实现Cloneable接口
		Student zhang = new Student("张三");
		Student zhangCopy = zhang.clone();
		
		System.out.println(zhang.name);
		System.out.println(zhangCopy.name);
		System.out.println(zhang == zhangCopy);  		 //false
		System.out.println(zhang.name == zhangCopy.name);//true
	}
	
	public Student clone() throws CloneNotSupportedException {
		Student stu = (Student) super.clone();
		return stu;
	}
	
	public static void main(String[] args) {
//		try {
//			serializableTest();  // 提示：想要序列化对象，类型必须实现Serializabal接口
//		} catch (ClassNotFoundException e) {
//			e.printStackTrace();
//		} catch (IOException e) {
//			e.printStackTrace();
//		} 
		
		try {
			cloneTest();
		} catch (CloneNotSupportedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
