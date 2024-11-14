package io6.datastream;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class DataSreamTest {

	public static void main(String[] args) {
		
		try {
			FileOutputStream fos1 = new FileOutputStream("a.txt");
			DataOutputStream dos = new DataOutputStream(fos1);
			dos.writeUTF("2017011013");
			dos.writeUTF("小明");
			dos.writeInt(20);
			dos.writeDouble(5.77);
			dos.close();
			fos1.close();
			
			FileInputStream fis = new FileInputStream("a.txt");
			DataInputStream dis = new DataInputStream(fis);
			System.out.println("学号：" + dis.readUTF() );
			System.out.println("姓名：" + dis.readUTF() );
			System.out.println("年龄：" + dis.readInt());
			System.out.println("身高（ft）：" + dis.readDouble());
			dis.close();
			fis.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		

	}

}
