package io7.transform;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;

public class InputStreamReaderTest {

	public static void main(String[] args) throws IOException  {
		// TODO 自动生成的方法存根
//		readFile();
//		Charset.defaultCharset():当前机器默认编码		
		System.out.println(Charset.defaultCharset());
//		readSystemIn();
	}

	public static void readFile()throws IOException{
		// 转换流
		FileInputStream fis = new FileInputStream("poem.txt");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);
		String str;
		while((str = br.readLine())!=null){
			System.out.println(str);
		}
		br.close();isr.close();
	}
	
	public static void readSystemIn() throws IOException{
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String str;
		while((str = br.readLine())!=null){
			System.out.print("您输入的是：");
			System.out.println(str);
		}
		br.close();isr.close();
	}
}
