package Util;
//用于产生不同的T1,T2,T3...
//不同名字生成器
public class VariableNameGenerator {
    static final String VAR_PREFIX_STRING = "T";
    static int sequenceId = 0;

    public static String genVariableName() {
        ++sequenceId;
        return VAR_PREFIX_STRING + sequenceId;
    }

    public void clear() {
        sequenceId = 0;
    }
}
