package io3.filechar;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class FileWriterTest {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		try {
			FileReader fr = new FileReader("files\\poem.txt");
			FileWriter fw = new FileWriter("files\\new poem.txt");
			char [] buf = new char[10];
			int n = 0;
			while((n = fr.read(buf,0,buf.length))!=-1){
//				System.out.println(buf);
				fw.write(buf, 0, n);			
			}
			fw.write("---��ʫ��");
//			fw.flush(); 
			fw.close();
		} catch (FileNotFoundException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		} catch (IOException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		}
	}

}
