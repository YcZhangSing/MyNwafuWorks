package util;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ExpressionType {
	private String type = null;
	private String value = null; //变量名、临时变量名或常量名
	public ArrayList<String> valueList = new ArrayList<String>();// for commaExpression，存储逗号表达式中的变量名
	public ArrayList<String> typeList = new ArrayList<String>();// for commaExpression
	public ArrayList<QTInfo> trueList = new ArrayList<QTInfo>();
	public ArrayList<QTInfo> falseList = new ArrayList<QTInfo>();

	public void printList(ArrayList<String> list){
		for(int i=0;i<list.size();i++)
			System.out.print(list.get(i)+"   ");
		System.out.println();
	}
 
	public void printValue() {
		File f = new File("./output/Expre.txt");
		BufferedWriter output;
		try {
			output = new BufferedWriter(new FileWriter(f));
			if (typeList.size() == valueList.size()) {
				for (int i = 0; i < valueList.size(); i++)
					output.write("< " + valueList.get(i) + "   " + typeList.get(i) + " >\n");
			} else {
				output.write("isn`t equal!");
			}
		} catch (IOException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		
	}
	public String toString() {
		return this.value;
	}
	public ArrayList<String> getTypeList(){
		return this.typeList;
	}
	public void addValue(String value,String type){
		this.setValue(value);
		this.setType(type);
		this.valueList.add(value);
		this.typeList.add(type);
	}
	
	public void setValue(String value) {
		this.value = value;
	}
	
	public void setType(String type) {
		this.type = type;
	}
	public String getValue() {
		return this.value;
	}
	public String getType() {
		return this.type;
	}
	public void addTrueQT(QTInfo info) {
		trueList.add(info);
	}

	public void addFalseQT(QTInfo info) {
		falseList.add(info);
	}

	public void changeTrueFalseList() {
		ArrayList<QTInfo> tmp;
		tmp = trueList;
		trueList = falseList;
		falseList = tmp;
	}

	public void fillBackTrue(int trueExit) {
		if(trueList!=null)
		for (int i = 0; i < trueList.size(); i++) {
			QTInfo info = trueList.get(i);
			info.setResult(trueExit);
		}
	}

	public void fillBackFalse(int falseExit) {
		if(falseList!=null)
		for (int i = 0; i < falseList.size(); i++) {
			QTInfo info = falseList.get(i);
			info.setResult(falseExit);
		}
	}

	public static ArrayList<QTInfo> merge(ArrayList<QTInfo> list1,
			ArrayList<QTInfo> list2) {
		for (int i = 0; i < list2.size(); i++) {
			QTInfo info = list2.get(i);
			list1.add(info);
		}
		return list1;
	}

	public static void mergeTV(ExpressionType e1, ExpressionType e2)
	{
		for(int i=0; i<e2.typeList.size(); i++)
		{
			e1.typeList.add(e2.typeList.get(i));
			e1.valueList.add(e2.valueList.get(i));
		}
//		for(int i=0; i<e2.valueList.size(); i++)
//		{
//			e1.valueList.add(e2.valueList.get(i));
//		}
	}
	
	public void clear() {
		this.trueList.clear();
		this.falseList.clear();
	}
}
