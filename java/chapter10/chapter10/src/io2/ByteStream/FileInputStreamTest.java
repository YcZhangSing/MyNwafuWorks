package io2.ByteStream;
/*
 * FileInputStream
 * int read()
 * int read(byte[])
 */
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class FileInputStreamTest {

	public static void main(String[] args) {
		File f1 = new File(".\\files\\file1.txt");
		FileInputStream fis1 ;
		byte [] b1 = new byte[50];
		try {
			fis1 = new FileInputStream(f1);
			System.out.println(fis1.read()); // 返回一个字节
			System.out.println((int)'W');
			int reads = fis1.read(b1);
			System.out.println((char)b1[0]);
			System.out.println(reads);  //b未写满
			
			byte [] b2 = new byte[10];
			reads = fis1.read(b2, 5, 4);
			System.out.println(reads);
			fis1.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
