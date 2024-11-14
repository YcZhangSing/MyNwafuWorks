package Util;

import java.util.HashMap;
import java.util.Iterator;

public class VariableMap {
    private HashMap<String,VariableInfo> map = new HashMap<String, VariableInfo>();

    public void addVariable(String type,String name)
    {
        map.put(name,new VariableInfo(type,name));
    }
    public Boolean Variablecontains(String name)
    {
        if(map.containsKey(name))
        {
            return true;
        }
        return false;
    }
    public Boolean TypeCheck(String v1, String v2)
    {
        if(!(map.containsKey(v1)&&map.containsKey(v2)))
        {
            return false;
            //如果其中一个变量在map中不存在，则检查不通过
        }
        if(!(map.get(v1).getType().equals(map.get(v2).getType())))
        {
            return false;
            //如果两个变量的type不一致则返回false
        }
        return true;
    }

    public void setarr(String key,int dem)
    {
        map.get(key).setArrdemention(dem);
    }

    @Override
    public String toString() {
                String  res="\n";

        for(String key : map.keySet()){
            int dim=map.get(key).getArrdemention();
            if(dim==0) {
                res += "<" + key + " , " + map.get(key).getType() + ">";
            }
            else if(dim==1)
            {
                res += "<" + key + " , " + map.get(key).getType()+" array[]" + ">";
            }
            else
            {
                res += "<" + key + " , " + map.get(key).getType()+" array[][]" + ">";
            }
            res+="\n";
        }

                return res;
    }
}
