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
		
		Student zhang = new Student("����");
		oos.writeObject(zhang);
		
		byte [] buf = baos.toByteArray();
		ByteArrayInputStream bais = new ByteArrayInputStream(buf);
		ObjectInputStream    bis = new ObjectInputStream(bais);
		
		Student zhangCopy = (Student)bis.readObject();
		zhangCopy.name = "����";
		System.out.println(zhang.name);
		System.out.println(zhangCopy.name);
		System.out.println(zhang == zhangCopy);  		 //false
		System.out.println(zhang.name == zhangCopy.name);//false
	}
	
	
	
	public static void cloneTest() throws CloneNotSupportedException {
		// ��Ҫ����clone()����ʵ�ָ��ƶ�����Ҫʵ��Cloneable�ӿ�
		Student zhang = new Student("����");
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
//			serializableTest();  // ��ʾ����Ҫ���л��������ͱ���ʵ��Serializabal�ӿ�
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
