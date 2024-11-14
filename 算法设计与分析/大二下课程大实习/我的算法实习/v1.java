package ss;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Vector;

public class q6 {
	final static int SSRMINLEN =16;//报告SSR的最短长度
	final static int SSRCELLMAXLEN =8;//报告SSR循环序列的最大长度
	final static int SSRCELLMINLEN =4;//报告SSR循环序列的最短长度
    private static int n;               // length of input string
    private String text;         // input text
    private int[] index;         // offset of ith string in order
    private int[] rank;          // rank of ith string
    private int[] newrank;       // rank of ith string (temporary)
    private int offset;
    private static String sequence = "";
    private static int[] LCP;
    public static  String input_path = "src/ss/test_input.fa";
    public static  String header = "";//基因序列名
    public static q6 suffix;
    public static String result = "";
    public static Boolean[] filter;//过滤数组
    public static int p;
    public q6(String s) {
        n = s.length();
        text = s;
        index   = new int[n+1];
        rank    = new int[n+1];
        newrank = new int[n+1];

        index[n] = n;
        rank[n] = -1;

        msd();
        doit();
    }

    public int length() {
        return n;
    }

    public int index(int i) {
        if (i < 0 || i >= n) throw new IllegalArgumentException();
        return index[i];
    }

    public String select(int i) {
        if (i < 0 || i >= n) throw new IllegalArgumentException();
        return text.substring(index[i]);
    }

    private void doit() {
        for (offset = 1; offset < n; offset += offset) {
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (rank[index[i]] == rank[index[i-1]]) count++;
                else if (count > 0) {
                    // sort
                    int left = i-1-count;
                    int right = i-1;
                    quicksort(left, right);

                    int r = rank[index[left]];
                    for (int j = left + 1; j <= right; j++) {
                        if (less(index[j-1], index[j]))  {
                            r = rank[index[left]] + j - left; 
                        }
                        newrank[index[j]] = r;
                    }

                    // copy back - note can't update rank too eagerly
                    for (int j = left + 1; j <= right; j++) {
                        rank[index[j]] = newrank[index[j]];
                    }

                    count = 0;
                }
            }
        }
    }

    // sort by leading char, assumes extended ASCII (256 values)
    private void msd() {
        final int R = 256;

        // calculate frequencies
        int[] freq = new int[R];
        for (int i = 0; i < n; i++)
            freq[text.charAt(i)]++;

        // calculate cumulative frequencies
        int[] cumm = new int[R];
        for (int i = 1; i < R; i++)
            cumm[i] = cumm[i-1] + freq[i-1];

        // compute ranks
        for (int i = 0; i < n; i++)
            rank[i] = cumm[text.charAt(i)];

        // sort by first char
        for (int i = 0; i < n; i++)
            index[cumm[text.charAt(i)]++] = i;
    }

    private boolean less(int v, int w) {
        return rank[v + offset] < rank[w + offset];
    }

    private void exch(int i, int j) {
        int swap = index[i];
        index[i] = index[j];
        index[j] = swap;
    }

    private void quicksort(int lo, int hi) { 
        if (hi <= lo) return;
        int i = partition(lo, hi);
        quicksort(lo, i-1);
        quicksort(i+1, hi);
    }

    private int partition(int lo, int hi) {
        int i = lo-1, j = hi;
        int v = index[hi];

        while (true) { 

            // find item on left to swap
            while (less(index[++i], v))
                if (i == hi) break;   // redundant

            // find item on right to swap
            while (less(v, index[--j]))
                if (j == lo) break;

            // check if pointers cross
            if (i >= j) break;

            exch(i, j);
        }

        // swap with partition element
        exch(i, hi);

        return i;
    }
	static  String getsequence()
	{
		
		try {
			List<String> lines = Files.readAllLines(Paths.get(input_path),Charset.forName("UTF-8"));
			for(int i=0;i<lines.size();++i)
			{
					if(lines.get(i).charAt(0) != '>')
					{
						sequence += lines.get(i).toString().toUpperCase();
					}
					else
					{
						header=lines.get(i).toString();
						//System.out.println(header);
					}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("读入完成");
		return sequence;
	}
	static void getLCP()
	//后缀i的最长公共前缀为k 则后缀i+1的最长公共前缀至少为k-1
	{ 

    //Vector<Integer> suffix_map = new Vector<>(n);
		int[] suffix_map = new int[n];
    for(int i=0;i<n;++i)
    {
        suffix_map[suffix.index(i)]=i;
    }
 
    int pre_lcp=0;
    for(int i=0;i<n;++i){
        //后缀i的最长公共前缀
        //pre_lcp:后缀i-1的最长公共前缀
        int suffix_index=suffix_map[i];
        if(suffix_index==n-1){
            LCP[suffix_index+1]=0;
            continue;
        }
        int _next=suffix.index(suffix_index+1);
        if(pre_lcp==0){
            LCP[suffix_index+1]=0;
            for(int j=0;i+j<n && _next+j<n;++j){
                if(sequence.charAt(i+j) == sequence.charAt(j+_next)) ++LCP[suffix_index+1];
                else break;
            }
        }else{
            LCP[suffix_index+1]=pre_lcp-1;
            for(int j=pre_lcp-1;i+j<n && _next+j<n;++j){
                if(sequence.charAt(i+j) == sequence.charAt(j+_next)) ++LCP[suffix_index+1];
                else break;
            }
        }
        pre_lcp=LCP[suffix_index+1];
    }
	}
	static boolean isgoodSSR(int r,int k)//SSR过滤
	{
		int len = k*(r+1);
		if(r==0) return false;
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
    public static void main(String[] args) {
    	getsequence();
    	//sequence="TAGTCAGTCAGTCAGTCAGTCAGTCGGT$";
    	LCP = new int[sequence.length()+1];
    	suffix = new q6(sequence);
    	filter=new Boolean[n];
    	System.out.println("SA数组计算完成");
    	getLCP();
    	System.out.println("LCP数组计算完成");
    	for(int i = 1;i<suffix.length();++i)
    	{
    		int k = Math.abs(suffix.index(i)-suffix.index(i-1));
    		int r = Math.abs((int)LCP[i]/k);
    		p=Math.min(suffix.index(i), suffix.index(i-1));
    		if(isgoodSSR(r,k))
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
    			}
    		}
    		System.out.println("SSR\t\trepest\t\tposition\n"+result);
    	}
    	
    

}