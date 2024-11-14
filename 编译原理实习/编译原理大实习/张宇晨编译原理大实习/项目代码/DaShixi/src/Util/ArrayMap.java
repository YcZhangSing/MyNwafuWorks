package Util;

import java.util.HashMap;

public class ArrayMap {
    private HashMap<String, ArrayInfo> map = new HashMap<>();

    public boolean createArray(String name,String raw, String col)
    {
        if(map.containsKey(name))
        {
            return false;
        }
        ArrayInfo aif = new ArrayInfo(raw,col);
        map.put(name,aif);
        return true;
    }
    public boolean containsKey(String key)
    {
    	return map.containsKey(key);
    }
    public String getcol(String name)
    {
        return map.get(name).getCol();
    }

    public String getraw(String name)
    {
        return map.get(name).getRaw();
    }
    public boolean Check(String name, String col, String raw)
    {
    	if((!map.containsKey(name)) || 
    			(Integer.parseInt(raw)>Integer.parseInt(this.getraw(name))) ||
    				(Integer.parseInt(col)>Integer.parseInt(this.getcol(name))))
    	{
    		return false;
    	}
    	return true;
    }
    
}