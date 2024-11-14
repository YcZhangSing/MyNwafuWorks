package 第十周实习;

import java.util.HashSet;
import java.util.Iterator;
import java.util.TreeSet;

class Person1 implements Comparable
{
	String name;
	public int ID;
	public Person1(String n,int I)
	{
		name=n;
		ID=I;
	}
	@Override
	public String toString() {
		return "person [姓名:" + name + ", 身份证号:" + ID + "]";
	}
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Person1 other = (Person1) obj;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		if (ID != other.ID)
			return false;
		return true;
	}	
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		result = prime * result + ID;
		return result;
	}
	@Override
	public int compareTo(Object o) {
		// TODO Auto-generated method stub
		Person1 p1 = (Person1) o;
		int m=0;
		if(p1.ID>this.ID)
		{
			m=1;
		}
		else if(p1.ID<this.ID)
		{
			m=-1;
		}
		return m;
	}
}

public class P2 {
	public static void main(String args[]) {
		Person1 a = new Person1("张三",12310001);
		Person1 b = new Person1("李四",12310002);
		Person1 c = new Person1("王五",12310003);
		Person1 e = new Person1("王五",12310003);
		HashSet<Person1> hst = new HashSet<Person1>();
		hst.add(a);
		hst.add(b);
		hst.add(c);
		hst.add(e);
		Iterator it = hst.iterator();
		while(it.hasNext())
		{
			
			System.out.println(it.next().toString());
			
		}
		TreeSet<Person1> ts =  new TreeSet<Person1>();
		ts.add(a);
		ts.add(b);
		ts.add(c);
		Iterator tit = ts.iterator();
		System.out.println();
		while(tit.hasNext())
		{
			
			System.out.println(tit.next().toString());
			
		}
		
	}

}
