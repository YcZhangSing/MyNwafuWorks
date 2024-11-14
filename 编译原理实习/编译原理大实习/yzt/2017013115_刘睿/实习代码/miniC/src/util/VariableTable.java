package util;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class VariableTable {
	public ArrayList<Variable> varTable = new ArrayList<Variable>();
	public boolean canInsert(String name)
	{
		for(int i=0; i<varTable.size(); i++)
		{
			String str = varTable.get(i).name;
			if(str.equals(name))
			{
				return false;
			}
		} 
		return true;
	}
	
	public void insertVar(String name, String type)
	{
		int elementSize = 0;
		Variable var = new Variable(name, type, elementSize);
		varTable.add(var);
	}
	
	public void printList()
	{
		try {
			File f = new File("./output/varTable.txt");
			if (f.exists()) {
				// System.out.print("�ļ�����");
			} else {
				System.out.print("�ļ�������");
				f.createNewFile();// �������򴴽�
			}
			BufferedWriter output;
			output = new BufferedWriter(new FileWriter(f));
			for(int i=0; i<varTable.size(); i++)
			{
				output.write("< "+varTable.get(i).name+" " +varTable.get(i).type+" >\n");
			}
			output.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}