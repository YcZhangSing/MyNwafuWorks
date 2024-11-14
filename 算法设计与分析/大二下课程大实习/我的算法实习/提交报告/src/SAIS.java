import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class SAIS {

	public char[] buildTypeMap(String input){
		char inp[] = input.toCharArray();
		int length = input.length();
		char result[] = new char[length + 1];
		result[length] = 'S';
		result[length - 1] = 'L';
		for(int i=length-2; i>=0; i--){
			if( inp[i] > inp[i+1] ){
				result[i] = 'L';
			}
			else if( inp[i] == inp[i+1] && result[i+1] == 'L'){
				result[i] = 'L';
			}
			else{
				result[i] = 'S';
			}
		}
		return result;
	}

	public boolean isLMSChar(int offset, char[] typemap){

		if(offset == 0){
			return false;
		}
		if(typemap[offset] == 'S' && typemap[offset-1] == 'L'){
			return true;
		}
		return false;
	}

	public boolean lmsSubstringsAreEqual(String string,char[] typemap, int offsetA, int offsetB){
		if(offsetA == string.length() || offsetB == string.length()){
			return false;
		}
		int i =0;
		char[] str = string.toCharArray();
		while(true){
			boolean aIsLMS = isLMSChar(i+offsetA, typemap);
			boolean bIsLMS = isLMSChar(i+offsetB, typemap);
			if(i>0 && aIsLMS && bIsLMS){
				return true;
			}
			if(aIsLMS != bIsLMS){
				return false;
			}
			if(str[i+offsetA] != str[i+offsetB]){
				return false;
			}
			i+=1;
		}
	}

	public int[] findBucketSizes(String string, int alphabetSize){ 
		int[] res = new int[alphabetSize];
		Arrays.fill(res, 0);
		char[] str = string.toCharArray();
		for(char c: str){
			res[c] += 1;
		}
		return res;
	}

	public int[] findBucketHeads(int[] bucketSizes){
		int offset = 1;
		int[] res = new int[bucketSizes.length];
		for(int i=0;i<res.length;i++){
			res[i] = offset;
			offset += bucketSizes[i];
		}
		return res;
	}

	public int[] findBucketTailss(int[] bucketSizes){
		int offset = 1;
		int[] res = new int[bucketSizes.length];
		for(int i=0;i<res.length;i++){
			offset += bucketSizes[i];
			res[i] = offset - 1;
		}
		return res;
	}


	public int[] makeSuffixArrayByInducedSorting(String string, int alphabetSize)
	{
		char[] typemap = buildTypeMap(string);
		int[] bucketSizes = findBucketSizes(string, alphabetSize);
		int[] guessedSuffixArray = guessLMSSort(string, bucketSizes, typemap);
		
		guessedSuffixArray = induceSortL(string, guessedSuffixArray, bucketSizes, typemap);
		guessedSuffixArray = induceSortS(string, guessedSuffixArray, bucketSizes, typemap);
		
		HashMap<Integer,ArrayList<Integer>> res = summariseSuffixArray(string, guessedSuffixArray, typemap);
		ArrayList<Integer> summarySuffixOffsets = res.get(0);
		ArrayList<Integer> summaryString = res.get(1);
		
		int summaryAlphabetSize = res.get(2).get(0);
		int[] summarySuffixOffsetsArray = new int[summarySuffixOffsets.size()];
		int[] summaryStringArray = new int[summaryString.size()];
		
		for (int i=0; i < summarySuffixOffsetsArray.length; i++)
		{
			summarySuffixOffsetsArray[i] = summarySuffixOffsets.get(i).intValue();
			summaryStringArray[i] = summaryString.get(i).intValue();
		}
		
		int[] summarySuffixArray = makeSummarySuffixArray(summaryStringArray, summaryAlphabetSize);
		int[] result = accurateLMSSort(string, bucketSizes, typemap, summarySuffixArray, summarySuffixOffsetsArray);
		
		result = induceSortL(string, result, bucketSizes, typemap);
		result = induceSortS(string, result, bucketSizes, typemap);
		
		return result;
	}

	public int[] accurateLMSSort(String string, int[] bucketSizes, char[] typemap, int[] summarySuffixArray,
			int[] summarySuffixOffsets) {
		int[] suffixOffsets = new int[string.length() + 1];
		Arrays.fill(suffixOffsets, -1);
		int[] bucketTails = findBucketTailss(bucketSizes);
		for(int i=summarySuffixArray.length-1;i>1;i--){
			int stringIndex = summarySuffixOffsets[summarySuffixArray[i]];
			int bucketIndex = string.charAt(stringIndex);
			suffixOffsets[bucketTails[bucketIndex]] = stringIndex;
			bucketTails[bucketIndex] -= 1;
		}
		suffixOffsets[0] = string.length();
		return suffixOffsets;
	}

	public int[] makeSummarySuffixArray(int[] summaryString, int summaryAlphabetSize) {
		int[] summarySuffixArray;
		if(summaryAlphabetSize == summaryString.length){
			summarySuffixArray = new int[summaryString.length + 1];
			summarySuffixArray[0] = summaryString.length;
			for(int i=0;i<summaryString.length;i++){
				int y = summaryString[i];
				summarySuffixArray[y+1] = i;
			}
		}
		else{
			StringBuilder s = new StringBuilder();
			for(int i=0;i<summaryString.length;i++){
				char c = (char) summaryString[i];
				s.append(c);
			}
			summarySuffixArray = makeSuffixArrayByInducedSorting(s.toString(), summaryAlphabetSize);
		}
		return summarySuffixArray;
	}

	public int[] induceSortL(String string, int[] guessedSuffixArray, int[] bucketSizes, char[] typemap) 
	{
		int[] bucketHeads = findBucketHeads(bucketSizes);
		for(int i =0;i<guessedSuffixArray.length;i++){
			if(guessedSuffixArray[i] == -1){
				continue;
			}
			int j = guessedSuffixArray[i] - 1;
			if(j<0){
				continue;
			}
			if(typemap[j] != 'L'){
				continue;
			}
			int bucketIndex = string.charAt(j);
			guessedSuffixArray[bucketHeads[bucketIndex]] = j;
			bucketHeads[bucketIndex] += 1;
		}
		return guessedSuffixArray;
	}

	public int[] induceSortS(String string, int[] guessedSuffixArray, int[] bucketSizes, char[] typemap) {
		int[] bucketTails = findBucketTailss(bucketSizes);
		for(int i = guessedSuffixArray.length-1;i>-1;i--){
			int j = guessedSuffixArray[i] - 1;
			if(j<0){
				continue;
			}
			if(typemap[j] != 'S'){
				continue;
			}
			int bucketIndex = string.charAt(j);
			guessedSuffixArray[bucketTails[bucketIndex]] = j;
			bucketTails[bucketIndex] -= 1;
		}
		return guessedSuffixArray;
	}

	public int[] guessLMSSort(String string, int[] bucketSizes, char[] typemap) {
		int[] guessedSuffixArray = new int[string.length() + 1];
		Arrays.fill(guessedSuffixArray, -1);
		int[] bucketTails = findBucketTailss(bucketSizes);
		for(int i =0;i<string.length();i++){
			if(!isLMSChar(i, typemap)){
				continue;
			}
			int bucketIndex = string.charAt(i);
			guessedSuffixArray[bucketTails[bucketIndex]] = i;
			bucketTails[bucketIndex] -= 1;
		}
		guessedSuffixArray[0] = string.length();

		return guessedSuffixArray;
	}

	public HashMap<Integer, ArrayList<Integer>> summariseSuffixArray(String string, int[] guessedSuffixArray, char[]typemap){
		int[] lmsNames = new int[string.length() +1];
		Arrays.fill(lmsNames, -1);
		int currentName = 0;
		int lastLMSSuffixOffset;
		lmsNames[guessedSuffixArray[0]] = currentName;
		lastLMSSuffixOffset = guessedSuffixArray[0];
		for(int i = 1;i<guessedSuffixArray.length;i++){
			int suffixOffset = guessedSuffixArray[i];
			if(!isLMSChar(suffixOffset, typemap)){
				continue;
			}
			if(!lmsSubstringsAreEqual(string, typemap, lastLMSSuffixOffset, suffixOffset)){
				currentName += 1;
			}
			lastLMSSuffixOffset = suffixOffset;
			lmsNames[suffixOffset] = currentName;
		}
		ArrayList<Integer> summarySuffixOffsets = new ArrayList<>();
		ArrayList<Integer> summaryString = new ArrayList<>();
		for(int i=0;i<lmsNames.length;i++){
			int name = lmsNames[i];
			if(name == -1){
				continue;
			}
			summarySuffixOffsets.add(i);
			summaryString.add(name);
		}
		ArrayList<Integer> summaryAlphabetSize = new ArrayList<>();
		summaryAlphabetSize.add(currentName + 1);

		HashMap<Integer,ArrayList<Integer>> res = new HashMap<>();
		res.put(0,summarySuffixOffsets);
		res.put(1,summaryString);
		res.put(2, summaryAlphabetSize);

		return res;

	}




}
