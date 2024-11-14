package Util;
//四元式的形态
public class QTInfo {
    public static int size = 0; // 四元式全局个数，这个Static变量是用来记录QTInfo实例化对象的个数的
    public int    innerId;      // 当前四元式ID
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
