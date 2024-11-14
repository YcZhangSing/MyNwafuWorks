package Util;

import java.util.Iterator;

public class test {
    public static void main(String[] args)
    {
        QTList q = new QTList();
        System.out.println("22");
        q.addQTInfo(new QTInfo("1","1","1","1"));
        q.addQTInfo(new QTInfo("1","1","1","1"));
        q.addQTInfo(new QTInfo("1","1","1","1"));
        System.out.println(q.printQTTable());
        SwitchHDL a = new SwitchHDL();
        a.clean();
        a.addIndex(1);
        a.addOutIndex(2);
        a.addOutIndex(3);
        a.SwitchDefaultBackPatch(2,3,q);
        System.out.println("test:"+q.printQTTable());


    }
}
