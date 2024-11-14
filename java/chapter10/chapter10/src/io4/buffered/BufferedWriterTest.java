package io4.buffered;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedWriterTest {

	public static void main(String[] args) throws IOException {
		// TODO 自动生成的方法存根
		FileWriter fw = new FileWriter("output.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		
		bw.write("从明天起，做一个幸福的人");bw.newLine();
		bw.write("喂马，劈柴，周游世界");bw.newLine();
		bw.write("从明天起，关心粮食和蔬菜");bw.newLine();
		bw.write("我有一所大房子，面朝大海，春暖花开");bw.newLine();
		bw.close();  //不关闭流，缓冲区中的数据不会写入目的地
//		fw.close();
	}

}
