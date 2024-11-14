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
		// ���ļ��ж�ȡ���ڴ�
		BufferedReader br = new BufferedReader(new FileReader("files\\poem.txt"));
		StringBuffer sbuf = new StringBuffer();
		String str = null;
		while((str = br.readLine())!=null){
			sbuf.append(str+'\n');
		}
		
		
		char [] buf = sbuf.toString().toCharArray(); // Դ
		//��Դ�е����ݽ������ж�ȡ
		CharArrayReader car = new CharArrayReader(buf);
		BufferedReader car_br = new BufferedReader(car);
		while((str = car_br.readLine())!=null){
			System.out.println(str);
		}
		

		
	}

}
