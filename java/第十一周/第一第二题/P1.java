package 第十周实习;

import java.util.Iterator;
import java.util.LinkedList;





class person
{
	String name;
	String ID;
	public person(String n,String I)
	{
		name=n;
		ID=I;
	}
	@Override
	public String toString() {
		return "person [姓名:" + name + ", 身份证号:" + ID + "]";
	}
}
class student extends person
{
	String yuwen;
	String shuxue;
	String yingyu;
	public student(String n, String I,String y,String s,String yy) {
		super(n, I);
		// TODO Auto-generated constructor stub
		yuwen = y;
		shuxue = s;
		yingyu = yy;
	}
	@Override
	public String toString() {
		return "姓名："+name+"语文成绩：" + yuwen + ", 数学成绩：" + shuxue + ", 英语成绩：" + yingyu ;
	}
	
}
class teacher extends person
{
	String salary;

	public teacher(String n, String I, String salary) {
		super(n, I);
		this.salary = salary;
	}

	@Override
	public String toString() {
		return "teacher [姓名：" + name + ", 身份证号：" + ID + ", 工资:" + salary + "]";
	}
	

}
public class P1 {
	public static void main(String args[]) {
		//List list = new List();
		LinkedList<person> list = new LinkedList<person>();
		person p=new person("张三","12310000");
		person s=new student("李四","12320000","89","93","94");
		person t=new teacher("王五","12330000","3000");
		list.add(p);
		list.add(s);
		list.add(t);
		Iterator<person> i = list.iterator();
		while(i.hasNext())
		{
			System.out.println(i.next().toString());
		}
	}
	
	

}
