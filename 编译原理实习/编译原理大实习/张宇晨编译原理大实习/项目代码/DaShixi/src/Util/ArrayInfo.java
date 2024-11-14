package Util;

public class ArrayInfo {
    private String col=""+0;
    private String raw=""+0;

    public ArrayInfo(String raw, String col) {

        this.col = col;
        this.raw = raw;
    }

    public ArrayInfo(String raw) {

        this.col = 1+"";
        this.raw = raw;
    }
    
    public ArrayInfo() {

        this.col = 1+"";
        this.raw = 1+"";
    }

    public void setCol(String col) {
        this.col = col;
    }

    public void setRaw(String raw) {
        this.raw = raw;
    }

    public String getCol() {
        return col;
    }

    @Override
    public String toString() {
        return "ArrayInfo{"  + '\'' +
                ", col=" + col +
                ", raw=" + raw +
                '}';
    }

    public String getRaw() {
        return raw;
    }

}
