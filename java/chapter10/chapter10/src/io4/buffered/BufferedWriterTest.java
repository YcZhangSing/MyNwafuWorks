package io4.buffered;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class BufferedWriterTest {

	public static void main(String[] args) throws IOException {
		// TODO �Զ����ɵķ������
		FileWriter fw = new FileWriter("output.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		
		bw.write("����������һ���Ҹ�����");bw.newLine();
		bw.write("ι��������������");bw.newLine();
		bw.write("�������𣬹�����ʳ���߲�");bw.newLine();
		bw.write("����һ�����ӣ��泯�󺣣���ů����");bw.newLine();
		bw.close();  //���ر������������е����ݲ���д��Ŀ�ĵ�
//		fw.close();
	}

}
