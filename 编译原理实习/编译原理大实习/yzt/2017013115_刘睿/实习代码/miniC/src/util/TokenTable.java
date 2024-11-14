package util;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Iterator;
import myPackage.Token;


public class TokenTable {
	public ArrayList<Token> LEXList = new ArrayList<Token>();
	public static boolean flag = true;
	
	public void addToken(Token token)
	{
		LEXList.add(token);
	}
	 
	public void addToken(int index, Token token)
	{
		LEXList.add(index, token);
	}
	
	public Token remove(int index)
	{
		return LEXList.remove(index-1);
	}
	
	public Token get(int index)
	{
		return (Token)LEXList.get(index);
	}
	
	public void clear()
	{
		LEXList.clear();
	}
	
	public void printTokenTable() {
//		 System.out.println(toString());
		Iterator<Token> itr = LEXList.iterator();
		try {
			File f = new File("./output/lexInfo.txt");
			if (f.exists()) {
				// System.out.print("文件存在");
			} else {
				System.out.print("文件不存在");
				f.createNewFile();// 不存在则创建
			}
			BufferedWriter output;
			output = new BufferedWriter(new FileWriter(f));
			while (itr.hasNext()) {
				Token tmp = (Token) itr.next();
//				System.out.println(tmp.toString2());
				output.write(tmp.toString2()+'\n');
			}
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}