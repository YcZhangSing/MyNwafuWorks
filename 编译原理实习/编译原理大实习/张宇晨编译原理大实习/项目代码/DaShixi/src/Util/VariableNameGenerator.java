package Util;
//���ڲ�����ͬ��T1,T2,T3...
//��ͬ����������
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
