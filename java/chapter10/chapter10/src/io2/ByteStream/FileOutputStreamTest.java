package io2.ByteStream;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class FileOutputStreamTest {

	public static void main(String[] args) {
		try {
			FileOutputStream fos = new FileOutputStream(".\\files\\file2.txt");
			byte[] a = "happy new year ".getBytes();
			byte[] b = "ÐÂÄê¿ìÀÖ".getBytes();
			System.out.println(b.length);
//			fos.write(77);
			fos.write(b,0,5);
			fos.write(a);
			fos.close();
			
			FileInputStream fis = new FileInputStream(".\\files\\file2.txt");
			while(true){
				int n = fis.read();
				if(n != -1){
					System.out.print((char)n);
				}else
					break;
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
