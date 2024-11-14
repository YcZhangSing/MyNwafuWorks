package com.zhangyc.bean;

import java.io.*;

public class Str2Stream {
    public void tofile(String in) throws IOException {
        File file=new File("in.txt");
        if(file.exists())
        {
            try {
                file.delete();
                file.createNewFile();
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
        FileWriter fw = null;
        fw = new FileWriter("in.txt", true);
        fw.write("");
        fw.flush();
        PrintWriter pw = new PrintWriter(fw);
        pw.print(in);
        pw.flush();
        pw.close();
    }
}
