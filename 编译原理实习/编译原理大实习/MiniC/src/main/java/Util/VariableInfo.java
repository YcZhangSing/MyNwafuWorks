package Util;

public class VariableInfo {
    private String type="";
    private String name="";
    private int arrdemention=0;
    public VariableInfo(String type, String name) {
        this.type = type;
        this.name = name;
        this.arrdemention=0;
    }

    public int getArrdemention() {
        return arrdemention;
    }

    public void setArrdemention(int arrdemention) {
        this.arrdemention = arrdemention;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "VariableInfo{" +
                "type='" + type + '\'' +
                ", name='" + name + '\'' +
                '}';
    }
}
