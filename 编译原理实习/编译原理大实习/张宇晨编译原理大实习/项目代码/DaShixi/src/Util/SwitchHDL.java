package Util;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class SwitchHDL {
	//switchHandl:switch�������֣����ڴ���switchcase����������Ԫʽ
    Set<Integer> QTIndex = new HashSet<Integer>();
    Set<Integer> QTOutIndex = new HashSet<Integer>();
    //����case����default����
     public void SwitchDefaultBackPatch(int defaultout, int out, QTList qtList)
     {
         Iterator<Integer> it = QTIndex.iterator();
    	 Iterator<Integer> itJ = QTIndex.iterator();
    	 itJ.next();
    	 //������һ�������õ�����ָ����һ��case����Ϊ��caseɨ��������������Ҫ����Ҫɨ����һ��case��λ��
    	 
    	 while(itJ.hasNext()){
    		 //��һ��case�ļٳ�������һ��case
    		 int a = it.next();
    		 int b = itJ.next()-1;
    		 qtList.setResultbyIndex(a,b);
    		 System.out.println(a+"����Ԫʽ��������Ϊ"+b);
    	 }
    	 if(!itJ.hasNext())
    	 {
    		 //��itJ�������ʱ������һ������Ӧ����default��
    		 int a = it.next();
    		 qtList.setResultbyIndex(a,defaultout);
    		 System.out.println(a+"����Ԫʽ��������Ϊ"+defaultout);
    	 }
    	 
         Iterator<Integer> it0 = QTOutIndex.iterator();
//         System.out.println("this is it0 "+it0);
         while(it0.hasNext())
         {
//             System.out.println("it0LOOP");
             qtList.setResultbyIndex(it0.next(),out);
//             System.out.println(it0+" "+out);
         }
     }
     //��Ҫ�޸ĵ���Ԫʽ����ż���
     public void addIndex(int index)
     {
         QTIndex.add(index);
     }

    public void addOutIndex(int index)
    {
        QTOutIndex.add(index);
    }

     public void clean()
     {
         this.QTIndex.clear();
         this.QTOutIndex.clear();
     }

}
