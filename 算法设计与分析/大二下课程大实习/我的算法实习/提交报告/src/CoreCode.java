import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class CoreCode 
{
	final static int SSRMINLEN =16;//报告SSR的最短长度
	final static int SSRCELLMAXLEN =8;//报告SSR循环序列的最大长度
	final static int SSRCELLMINLEN =4;//报告SSR循环序列的最短长度
	private static Boolean[] filter;
	private static String sequence = "";
	private static String header = "";
	public static  String input_path = "src/test_input";
	private static int n;//sequence 的长度
	private static int[] SA;
	private static int[] LCP;
	private static int p;
	private static String result="";
	private static Queue<String> sequenceque = new LinkedList<>();;//基因序列队列
	private static Queue<String> headque = new LinkedList<>();;//基因序列名队列
	private static String outputPath = "./test_output.txt";
    private static void saveAsFileWriter(String content) {
        FileWriter fwriter = null;
        try {
            fwriter = new FileWriter(outputPath, true);
            fwriter.write(content);
        } catch (IOException ex) {
            ex.printStackTrace();
        } finally {
            try {
                fwriter.flush();
                fwriter.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }
	static  void  getsequence()
	{
		sequence=null;
		System.out.println("正在读取基因序列...");
		try {
			List<String> lines = Files.readAllLines(Paths.get(input_path),Charset.forName("UTF-8"));
			for(int i=0;i<lines.size();++i)
			{
				if(lines.get(i).charAt(0) == '>')
				{
					if(sequence != null) sequenceque.add(sequence);
					header = lines.get(i).toString().substring(1);
					headque.add(header);
					i++;
				}
				else
				{
					sequence += lines.get(i).toString().toUpperCase();
				}	
			}
			if(sequence != null)
			{
				sequenceque.offer(sequence);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		n = sequence.length();
		filter = new Boolean[n+1];
		LCP = new int[n+1];
		System.out.println("读入完成");
		
	}
	
//###############################################################################-getLCP
	static void getLCP()
	{
		int[] rk = new int[n+1];
		for(int i=1;i<=n;++i)
		{
			rk[SA[i]] = i;
		}
		int h =0;//前一次计算的两个后缀的lcp
		LCP = new int[n+1];
		LCP[1]=0;
		for(int i=1;i<n;++i)
		{
			int j = SA[rk[i]-1];
			if(h>0) h--;
			for(;j+h<n && i+h<n;h++)
			{
				if(sequence.charAt(j+h) != sequence.charAt(i+h)) break;
			}
			LCP[rk[i]] = h;
		}
	}
//###############################################################################-getLCP
	
//###############################################################################-isgoodSSR
	static boolean isgoodSSR(int r,int k)//SSR过滤
	{
		int len = k*(r+1);
		if(r<=0) return false;
		else if(len<SSRMINLEN) return false;
		else if (k>SSRCELLMAXLEN) return false;
		else if( k<SSRCELLMINLEN) return false;
		for(int i=0;i<len;++i)
		{
			if(filter[p+i] != null) 
			{
				return false;
			}
			filter[p+i]=true;
		}
		return true;
	}
//###############################################################################-isgoodSSR

	public static void main(String[] args) {
		getsequence();
		//-测试
//		sequence ="CAGAGA$";
//		n = sequence.length();
//		filter = new Boolean[n+1];
//		LCP = new int[n+1];
		//-测试
		System.out.println(sequenceque.size());
		for(int se=0;se<headque.size();++se)
		{
			sequence = sequenceque.remove();
			header = headque.remove();
			System.out.println(sequence);
			result=header;
			SAIS sais = new SAIS();
			SA = sais.makeSuffixArrayByInducedSorting(sequence,256);
			System.out.println("第"+se+"个序列："+header+"  开始查找");
			System.out.println("SA数组计算完成");
			getLCP();
			System.out.println("LCP数组计算完成");
			System.out.println("正在查找SSR序列...");
			saveAsFileWriter("SSR\t\trepest\t\tposition\n");
			//System.out.println("SSR\t\trepest\t\tposition\n");
			for(int i = 2;i<=n;++i)
	    	{
	    		int k = Math.abs(SA[i]-SA[i-1]);
	    		int r = Math.abs((int)LCP[i]/k);
	    		p=Math.min(SA[i],SA[i-1]);
	    		if(isgoodSSR(r,k))
	    		//if(r>0)
	    		{	
		    			for(int j=0;j<k;++j)
		    			{
		    				result+=sequence.charAt(p+j); 
		    			}
		    			result+="\t\t";
		    			r++;
		    			result+=r;
		    			result+="\t\t";
		    			result+=p;
		    			result+="\n";
		    			result+=header;
	    		}
	    	}
		}
		saveAsFileWriter(result);
		System.out.println("查找完毕，结果已经写入文件"+outputPath);	
    }
		
}




