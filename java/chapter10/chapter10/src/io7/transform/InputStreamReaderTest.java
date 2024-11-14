package io7.transform;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;

public class InputStreamReaderTest {

	public static void main(String[] args) throws IOException  {
		// TODO �Զ����ɵķ������
//		readFile();
//		Charset.defaultCharset():��ǰ����Ĭ�ϱ���		
		System.out.println(Charset.defaultCharset());
//		readSystemIn();
	}

	public static void readFile()throws IOException{
		// ת����
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
			System.out.print("��������ǣ�");
			System.out.println(str);
		}
		br.close();isr.close();
	}
}
