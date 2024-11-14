package io5.chararrayreader;

import java.io.BufferedReader;
import java.io.CharArrayReader;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;


public class CharArrayReaderTest {

	public static void main(String[] args) throws IOException {
		// 从文件中读取到内存
		BufferedReader br = new BufferedReader(new FileReader("files\\poem.txt"));
		StringBuffer sbuf = new StringBuffer();
		String str = null;
		while((str = br.readLine())!=null){
			sbuf.append(str+'\n');
		}
		
		
		char [] buf = sbuf.toString().toCharArray(); // 源
		//对源中的数据进行逐行读取
		CharArrayReader car = new CharArrayReader(buf);
		BufferedReader car_br = new BufferedReader(car);
		while((str = car_br.readLine())!=null){
			System.out.println(str);
		}
		

		
	}

}
