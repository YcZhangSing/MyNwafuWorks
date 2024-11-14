package io6.serializable;

public class CloneTest {

	public static void main(String[] args) throws CloneNotSupportedException {
		// TODO �Զ����ɵķ������
		System.out.println("CloneTest");
		Monkey sun = new Monkey("�����",150);
		sun.setName("��սʤ��");
		
		Monkey sunCopy = sun.clone();
		sunCopy.setHeight(140);
		
		System.out.println(sun == sunCopy);
		System.out.println(sun.name == sunCopy.name);
		System.out.println(sun.height == sunCopy.height);
		System.out.println(sun.goldenCudgel == sunCopy.goldenCudgel);
	}

}
