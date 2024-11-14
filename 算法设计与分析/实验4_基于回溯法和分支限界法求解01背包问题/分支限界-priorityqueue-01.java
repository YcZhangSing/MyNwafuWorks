package ss;
//优先级队列版
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;

class Qnode{
	public int cw;
	public int cp;
	public int up;
	public int level;
	public Vector<Boolean> path;
	public Qnode() {};
	public Qnode(int w,int p,int u,Vector<Boolean> pv,Boolean isleft,int le)
	{
		path=new Vector<>();
		for(int i=0;i<pv.size();++i)
		{
			path.add(pv.get(i));
		}
		path.add(isleft);
		cw=w;
		cp =p;
		up = u;
		level=le;
	}
}
public class q_backpack01 {
	public static int n;
	public static int W;
	public static int[] w;
	public static int[] p;
	public static int[] nu;//正确顺序
	public static Queue<Qnode> queue = new PriorityQueue<>((a,b)->
	{
		return a.up-b.up;
	});
	
	static void sort()
	{
		nu = new int[n+1];
		for(int i=1;i<=n;++i)
		{
			nu[i]=i;
		}
		for(int i=1;i<=n;++i)
		{
			double x = (double) w[i]/p[i];
			for(int j=i;j<=n;++j)
			{
				double y = (double) w[j]/p[j];
				if(x>y)
				{
					int t=nu[i];
					nu[i]=nu[j];
					nu[j]=t;
					
					t=p[i];
					p[i]=p[j];
					p[j]=t;
					
					t=w[i];
					w[i]=w[j];
					w[j]=t;
					
				}
			}
		}
		
	}
	static int bound(int lev,int cw)//lev表示当前所在的求解树的层数，所以是从第lev个物品开始
	{
		int rp=0;
		
		for(int i=lev;i<=n;++i)
		{
			if(w[i]+cw<=W)
			{
				rp+=p[i];
				cw+=w[i];
			}
			else
			{
				rp+=(W-cw)*(p[i]/w[i]);
				break;
			}
		}
		return rp;
	}
	static void output(Vector<Boolean> path)
	{
		for(int i=1;i<=path.size();++i)
		{
			if(path.get(i-1)==true)
			System.out.println("物品"+nu[i]+"在包中");
		}
	}
	static void cal()
	{
		int cw=0;
		int cp=0;
		int up=0;
		int lev=1;
		int bestp=0;
		Qnode cnode = new Qnode();
		Vector<Boolean> s_path = new Vector<>();
		while(true)
		{
		//System.out.println("lev"+lev);
		if(w[lev]+cw<=W)
		{
			queue.add(new Qnode(cw+w[lev], cp+p[lev], up, s_path, true,lev+1));
			bestp = bestp>cp+p[lev]? bestp:cp+p[lev];
//			System.out.println("bestp"+bestp);
//			System.out.println("cp"+cp);
//			System.out.println("p[lev]"+p[lev]);
		}
		up=cp+bound(lev, cw);
		//System.out.println("up"+up);
		if(up>bestp)
		{
			queue.add(new Qnode(cw, cp, up, s_path, false,lev+1));
		}
		if(queue.isEmpty()) break;
		else
		{
			cnode = queue.remove();
			 cw=cnode.cw;
			 cp=cnode.cp;
			 up=cnode.up;
			 lev=cnode.level;
			 s_path = cnode.path;
			 if(lev==n+1)
			 {
				 break;
			 }
		}
		}
		 output(cnode.path);
		 System.out.println("此路最大价值为"+cp+"为此情况下的最大价值");

	}
	
	public static void main(String[] args) {
		n=4;
		W=7;
		w=new int[5];
		p = new int[5];
		w[1]=3;
		w[2]=5;
		w[3]=2;
		w[4]=1;
		p[1]=9;
		p[2]=10;
		p[3]=7;
		p[4]=4;
//		Scanner scan = new Scanner(System.in);
//		System.out.println("count:");
//		 n = scan.nextInt();//物品数量
//		System.out.println("max capacity:");
//		 W=scan.nextInt();//背包容量
//		 w= new int[n+1];
//		 p = new int[n+1];
//		System.out.println("weight:");
//		for(int i=1;i<=n;++i)
//		{
//			w[i]=scan.nextInt();
//		}
//		System.out.println("price:");
//		for(int i=1;i<=n;++i)
//		{
//			p[i]=scan.nextInt();
//		}
//		scan.close();
		sort();
		cal();
		
		
	}
}
