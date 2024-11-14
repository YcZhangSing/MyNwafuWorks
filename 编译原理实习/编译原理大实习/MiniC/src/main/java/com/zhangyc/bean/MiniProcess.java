package com.zhangyc.bean;

import com.zhangyc.MiniCGrammar.MyNewGrammar;
import com.zhangyc.MiniCGrammar.ParseException;
import com.zhangyc.MiniCGrammar.test;

import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;
import java.util.ArrayList;

public class MiniProcess {
    private HttpServletRequest request;
    private com.zhangyc.MiniCGrammar.test t = new test();
    public MiniProcess(HttpServletRequest request)
    {
        this.request= request;
        ServletContext ctx = request.getSession().getServletContext();

    }

    public void gettest() {
        String res = "";
//        res=t.getres();
        request.setAttribute("Output",res);

    }
    public void tofile(String str) throws IOException {//将前端传回的inputstring 转为file文件
        request.setAttribute("input",str);
        Str2Stream a = new Str2Stream();
        a.tofile(str);
    }
//进行词法分析
    public void cifa() throws IOException {
        String res = "";
        MyNewGrammar mng = new MyNewGrammar();
        MyNewGrammar.ifright=true;
        mng.qtlist.QTListclear();
        mng.ERRclear();
        res = mng.Cifa();
        if(!mng.ifright)
        {
            res="";
            res=readTostring.readToString();
        }
        request.setAttribute("Output",res);
//        mng.ifright=true;//置回TRUE,便于用户调整输入测试
    }
//语法分析
    public void yufa() throws IOException, ParseException {
        String res = "";
        MyNewGrammar mng = new MyNewGrammar();
        MyNewGrammar.ifright=true;
        System.out.println("ifright:"+mng.ifright);
        System.out.println("yufa is called");
        mng.qtlist.QTListclear();
        mng.ERRclear();
        System.out.println("now,ifright:"+mng.ifright);
        res=mng.par()[0];
        System.out.println("par() , ifright:"+mng.ifright);
        if(!mng.ifright)
        {
            res="";
            res=readTostring.readToString();
        }
        request.setAttribute("Output",res);
//        mng.ifright=true;
    }
//语义分析
    public void yuyi() throws IOException, ParseException {
        String[] res = new String[4];
        MyNewGrammar mng = new MyNewGrammar();
        MyNewGrammar.ifright=true;
        mng.qtlist.QTListclear();
        mng.ERRclear();
        res = mng.par();
        System.out.println("String  "+res[3]);
        if(!mng.ifright)
        {
            res[1]="";
            res[1]=readTostring.readToString();
        }
        request.setAttribute("Output",res[1]);
//        mng.ifright=true;
    }
//变量表
    public void chartable() throws IOException, ParseException {
        String res = "";
        MyNewGrammar mng = new MyNewGrammar();
        MyNewGrammar.ifright=true;
        mng.qtlist.QTListclear();
        mng.ERRclear();
        res = mng.par()[2];

        if(!mng.ifright)
        {
            res="";
            res=readTostring.readToString();
        }
        request.setAttribute("Output",res);
//        mng.ifright=true;
    }

}
