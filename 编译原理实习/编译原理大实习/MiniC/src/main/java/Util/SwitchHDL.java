package Util;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class SwitchHDL {
    //switchHandl:switch处理助手，用于处理switchcase语句产生的四元式
    Set<Integer> QTIndex = new HashSet<Integer>();
    Set<Integer> QTOutIndex = new HashSet<Integer>();
    //回填case语句的default出口
    public void SwitchDefaultBackPatch(int defaultout, int out, QTList qtList)
    {
        Iterator<Integer> it = QTIndex.iterator();
        Iterator<Integer> itJ = QTIndex.iterator();
        itJ.next();
        //“先走一步”，让迭代器指向下一个case，因为本case扫描完后，如果不符合要求则要扫描下一个case的位置

        while(itJ.hasNext()){
            //上一个case的假出口是下一个case
            int a = it.next();
            int b = itJ.next()-1;
            qtList.setResultbyIndex(a,b);
            System.out.println(a+"号四元式回填结果段为"+b);
        }
        if(!itJ.hasNext())
        {
            //当itJ遍历完的时候，则下一个语句快应该是default了
            int a = it.next();
            qtList.setResultbyIndex(a,defaultout);
            System.out.println(a+"号四元式回填结果段为"+defaultout);
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
    //将要修改的四元式的序号加入
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
