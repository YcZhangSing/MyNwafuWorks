package Util;

import java.util.ArrayList;
import java.util.Iterator;
/*真假条件值，属性里面有 真链和假链条(TrueChain,FalseChain)*/
public class ConditionValue {
    private ArrayList<QTInfo> trueChain = new ArrayList<QTInfo>();
    private ArrayList<QTInfo> falseChain = new ArrayList<QTInfo>();

    public void setTrueChain(ConditionValue cValue) {
        trueChain = cValue.trueChain;
    }

    public void setFalseChain(ConditionValue cValue) {
        falseChain = cValue.falseChain;
    }

    public void mergeTrue(QTInfo qtTrue) {
        trueChain.add(qtTrue);

    }

    public void FEImerge(ConditionValue cValue)
    {
        trueChain.addAll(cValue.falseChain);
        falseChain.addAll(cValue.trueChain);
    }

    public void mergeTrue(ConditionValue cValue) {
        trueChain.addAll(cValue.trueChain);
    }


    public void mergeFalse(QTInfo qtFalse) {
        falseChain.add(qtFalse);
    }

    public void mergeFalse(ConditionValue cValue) {
        falseChain.addAll(cValue.falseChain);
    }

    public void backpatchTrueChain(int result) {
        Iterator<QTInfo> itr = trueChain.iterator();
        while(itr.hasNext()) {
            itr.next().setResult(result);
        }
    }

    public void backpatchFalseChain(int result) {
        Iterator<QTInfo> itr = falseChain.iterator();
        while(itr.hasNext()) {
            itr.next().setResult(result);
        }
    }
}
