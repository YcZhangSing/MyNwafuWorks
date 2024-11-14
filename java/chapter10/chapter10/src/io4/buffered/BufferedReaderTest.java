package io4.buffered;

/*
 * BufferedReader: readLine()
 */
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class BufferedReaderTest {

	public static void main(String[] args) throws IOException {
		// TODO 自动生成的方法存根
		FileReader fr = new FileReader("files\\poem.txt");
		BufferedReader br = new BufferedReader(fr);
		
		String str;
		while((str = br.readLine())!=null){ //1 readLine()
			System.out.println(str);
		}
//		br.close();   // 2.不要忘记关闭缓冲流
//		fr.close();
	}
}
