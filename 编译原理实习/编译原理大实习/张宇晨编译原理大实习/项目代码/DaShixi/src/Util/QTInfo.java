package Util;
//��Ԫʽ����̬
public class QTInfo {
	public static int size = 0; // ��Ԫʽȫ�ָ��������Static������������¼QTInfoʵ��������ĸ�����
	public int    innerId;      // ��ǰ��ԪʽID
	public String operator;
	public String arg1;
	public String arg2;
	public String result;
	public QTInfo(String operator, String arg1, String arg2, String result) {
		super();
		this.innerId   = ++size;
		this.operator   = operator;
		this.arg1 = arg1;
		this.arg2 = arg2;
		this.result = result;
	}
	
	public QTInfo(String operator, String arg1, String arg2, int result) {
		this(operator, arg1, arg2, ""+result);
	}
	
	
	public String getOperator() {
		return this.operator;
	}
	
	public void setResult(String result) {
		this.result = result;
	}
	
	public void setResult(int result) {
		this.result = ""+result;
	}
	
	public String getResult() {
		return this.result;
	}
	
	public void setInnerId(int innerId) {
		this.innerId = innerId;
	}
	
	public int getInnerIdSeqen() {
		return size;
	}
	
	public String toString() {
		return "(" + innerId + ")(" + operator + ", " + arg1 + ", " + arg2 + ", " + result + ")";
	}
}
