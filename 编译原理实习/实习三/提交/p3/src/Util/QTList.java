package Util;

import java.util.ArrayList;
import java.util.Iterator;
//将四元式保存到这里
public class QTList {
	ArrayList<QTInfo> QTList =  new ArrayList<QTInfo>();
	public void addQTInfo(QTInfo info) {
		QTList.add(info);
	}
	
	public void addQTInfo(int index, QTInfo info) {
		QTList.add(index, info);
	}
	
	public QTInfo get(int index) {
		return (QTInfo) QTList.get(index);
	}
	public void setResultbyIndex(int index, int Result)
	{
		QTInfo temp = QTList.get(index-1);
		temp.setResult(Result);
		QTList.set(index-1, temp);
	}
	
	public QTInfo remove(int index) {
		return QTList.remove(index - 1);
	}
	
	public void clear() {
		QTList.clear();
		QTInfo.size = 0;
	}
	
	public String printQTTable() {
		String res = "\n";
		Iterator<QTInfo> it = QTList.iterator();
		try {
			while (it.hasNext()) {
				QTInfo tmp = (QTInfo) it.next();
				res += tmp.toString()+"\n";
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return res;
		
	}
}
