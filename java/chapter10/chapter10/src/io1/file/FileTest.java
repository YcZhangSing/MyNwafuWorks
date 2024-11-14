package io1.file;

/*
 * 创建文件、目录
 * File类的基本方法
 * File对象不能修改文件内部数据
 */
import java.io.File;
import java.io.IOException;

public class FileTest {

	public static void main(String[] args) {

		File f1 = new File("file1.txt"); // 绝对路径实例化File对象
		File f11 = new File("C:\\Users\\Administrator\\Desktop","chapter10\\b.txt");
		System.out.println("f11 length:"+f11.length());
		
		File f21 = new File(".");
		System.out.println(f21.getName());
		
		if (!f1.exists()) {
			try {
				f1.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		} else {
			System.out.println("f1.getName:"+f1.getName());
			System.out.println("f1.getAbsolutePath:"+f1.getAbsolutePath());
			System.out.println("f1.getParent:"+f1.getParent());
			System.out.println(f1.canRead());
			System.out.println(f1.length());
			System.out.println(f1.isFile());
//			System.out.println("rename:"+f1.renameTo(f11));
		}
//		f1.delete();

		File f2 = new File(".\\files");
		if (!f2.exists()) {
			f2.mkdir();
		} else {
			System.out.println(f2.isDirectory());
			String[] fileList1 = f2.list();
			File[] fileList2 = f2.listFiles();
			for(String str:fileList1) {
				System.out.println(str);
			}
		}
		
	}

}
