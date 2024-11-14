package io3.filechar;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class FileReaderTest {

	public static void main(String[] args) {
		FileReader fr  = null;
		try {
			fr = new FileReader(".\\files\\poem.txt");
			char [] buf = new char[10];
			int n = 0;
			while((n = fr.read(buf,0,buf.length))!=-1){
				System.out.println(buf);
			}
			fr.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} 
	}

}
