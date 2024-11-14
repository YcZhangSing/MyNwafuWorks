
import sun.net.www.http.HttpClient;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;


public class Main {

    public static String execCurl(String[] cmds) {
        ProcessBuilder process = new ProcessBuilder(cmds);
        Process p;
        try {
            p = process.start();
            BufferedReader reader = new BufferedReader(new InputStreamReader(p.getInputStream()));
            StringBuilder builder = new StringBuilder();
            String line;
            while ((line = reader.readLine()) != null) {
                builder.append(line);
                builder.append(System.getProperty("line.separator"));
            }
            return builder.toString();

        } catch (IOException e) {
            System.out.print("获取线程异常"+e);
        }
        return null;
    }
    public static void getMsg() {
        String jsonStr = "{'content':'testtest','creator':'creator''name':'lili'}";        //这里为发送的json串
        String url = "https://api.esmatlas.com/foldSequence/v1/pdb/";   //这里为连接发送的url
        String seq="GENGEIPLEIRATTGAEVDTRAVTAVEMTEGTLGIFRLPEEDYTALENFRYNRVAGENWKPASTVIYVGGTYARLCAYAPYNSVEFKNSSLKTEAGLTMQTYAAEKDMRFAVSGGDEVWKKTPTANFELKRAYARLVLSVVRDATYPNTCKITKAKIEAFTGNIITANTVDISTGTEGSGTQTPQYIHTVTTGLKDGFAIGLPQQTFSGGVVLTLTVDGMEYSVTIPANKLSTFVRGTKYIVSLAVKGGKLTLMSDKILIDKDWAEVQTGTGGSGDDYDTSFN";
        String accessToken = "123456";   //这一步这个token为上面get获取到的，有些简单的接口不需要获取这个
        String[] cmds = {"curl",
                "-X", "POST", "--data"+" \""+ seq +"\" "+url+ " "};   //超级注意：这个拼接json串的时候不要拼接双引号或者单引号，这个是踩坑提示，因为这个改了好久
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < cmds.length; i++) {
            sb.append(cmds[i] + " ");
        }
        System.out.println(sb);//这个是测试中调试输出你的发送命令航
        System.out.println(execCurl(cmds));
    }

    public class ArrayInfo {

        private int col=0;
        private int raw=0;

        public ArrayInfo(int raw, int col) {

            this.col = col;
            this.raw = raw;
        }

        public ArrayInfo(int raw) {

            this.col = 1;
            this.raw = raw;
        }

        public ArrayInfo() {

            this.col = 1;
            this.raw = 1;
        }

        public void setCol(int col) {
            this.col = col;
        }

        public void setRaw(int raw) {
            this.raw = raw;
        }



        public int getCol() {
            return col;
        }

        @Override
        public String toString() {
            return "ArrayInfo{" +
                    ", col=" + col +
                    ", raw=" + raw +
                    '}';
        }

        public int getRaw() {
            return raw;
        }


    }

    public class ArrayMap {
        private HashMap<String, ArrayInfo> map = new HashMap<>();

        public boolean createArray(String name,int col, int raw)
        {
            if(map.containsKey(name))
            {
                return false;
            }
            ArrayInfo aif = new ArrayInfo(col,raw);
            map.put(name,aif);
            return true;
        }
        public int getcol(String name)
        {
            return map.get(name).getCol();
        }

        public int getraw(String name)
        {
            return map.get(name).getRaw();
        }
    }


public static void main(String args[])
{
    System.out.println("E2\u7684\u771f\u51fa\u53e3\u662fS1\u5047\u51fa\u53e3\u662fS1+1 S1\u6267\u884c\u5b8c\u540e\u6267\u884cE3 E3\u65e0\u6761\u4ef6\u8df3\u8f6c\u5230E2");

}

}


