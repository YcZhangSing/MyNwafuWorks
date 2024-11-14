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
			dos.writeUTF("С��");
			dos.writeInt(20);
			dos.writeDouble(5.77);
			dos.close();
			fos1.close();
			
			FileInputStream fis = new FileInputStream("a.txt");
			DataInputStream dis = new DataInputStream(fis);
			System.out.println("ѧ�ţ�" + dis.readUTF() );
			System.out.println("������" + dis.readUTF() );
			System.out.println("���䣺" + dis.readInt());
			System.out.println("��ߣ�ft����" + dis.readDouble());
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
