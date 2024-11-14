package io6.serializable;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class SerializableTest {

	public static void main(String[] args) throws ClassNotFoundException, IOException {
		// TODO 自动生成的方法存根
		System.out.println("SerializableTest");
		Monkey sun = new Monkey("孙悟空",150);
		
		Monkey sunCopy = sun.serializableClone();
		sunCopy.setHeight(140);
		
		System.out.println(sun == sunCopy);
		System.out.println(sun.name == sunCopy.name);
		System.out.println(sun.height == sunCopy.height);
		System.out.println(sun.goldenCudgel == sunCopy.goldenCudgel);
	
	}
	


}
