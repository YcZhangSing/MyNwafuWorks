package com.zhangyc.MiniCGrammar;

import com.zhangyc.bean.Str2Stream;
import com.zhangyc.bean.readTostring;

import java.io.IOException;

public class test {
public static void main(String[] args) throws IOException, ParseException {
    MyNewGrammar mng = new MyNewGrammar();
    mng.qtlist.QTListclear();
    mng.par();
    System.out.println(mng.printQTTable());

//    System.out.println(mng.Cifa());

//    Str2Stream tofile = new Str2Stream();
//    tofile.tofile("tofile2");
    readTostring r = new readTostring();
    System.out.println(""+r.readToString());
}
}
