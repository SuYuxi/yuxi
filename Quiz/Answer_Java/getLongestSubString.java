import java.io.*;
import java.util.*;

//Main program that call "getLongestSubString" function to get the Longest Sub String with expected mode
public class getLongestSubString {
	public static void main(String[] args) throws IOException {
		String inputData;
		String mode;
		TreeSet<String> longestSubStr;
		System.out.println("Please input process mode from \"Ascend\", \"Descend\" or \"Equal\" (without quotation mark)");
		BufferedReader modeBuffer =  new BufferedReader(new InputStreamReader(System.in));
		mode = modeBuffer.readLine();
		System.out.println("Please input a string to retrieve the longest substring");
		BufferedReader inputDataBuffer = new BufferedReader(new InputStreamReader(System.in));
		inputData = modeBuffer.readLine();
		try {
			longestSubStr = getLongestSubString(inputData, mode);
			System.out.println("The longest " + mode + " Value Part String show as below:");
			for (String subStr: longestSubStr) {
				System.out.println(subStr);	
			}
		}
		catch(Exception e) {
			System.out.println(e.getMessage());
		}	
	}
	//Define method that getting the longest substring that meets mode requirement
	private static TreeSet<String> getLongestSubString(String inputStr, String mode) throws Exception {
		final String modeType[] = {"Ascend", "Descend", "Equal"}; 
		//Validate if the inputs are legal, otherwise throw an input error
		if(!Arrays.asList(modeType).contains(mode)) {
			throw new Exception("Mode error! Mode can only be \"Ascend\", \"Descend\" or \"Equal\"!");
		}
	 	//Validate if the inputs only include digits or only include alphabets, otherwise throw an input error
		boolean[] flag = {false, false};
		for (int inx = 0; inx < inputStr.length(); inx += 1) {
			char c = inputStr.charAt(inx);
			if(c >= '0' && c <= '9') { 
				flag[0] = true;
			}
			else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				flag[1] = true;
			}
			else {
				flag[0] = true;
				flag[1] = true;
			}
			if(flag[0] && flag[1]) {
				throw new Exception("Input error! Input string can only include digits or only include alphabets!");
			}
		}
		//Use Lambda expression and interface to dynamically bind compare function with the corresponding comparison method
		CompareOperation comparison = (char a, char b) -> { return a - b > 0; };
		if(mode.equals("Descend")) {
			comparison = (char a, char b) -> { return a - b < 0; };
		}
		else if(mode.equals("Equal")) {
			comparison = (char a, char b) -> { return a - b == 0; };
		}
		//Use Two Pointer algorithm to get the longest substring that meets mode requirement
		int inputLength = inputStr.length();
		TreeSet<String> longestSubStr = new TreeSet<String>();
		if(inputLength <= 1) {
			longestSubStr.add(inputStr);
			return longestSubStr;
		}
		int left = 0, right = 0;
		int maxLen = 0, subStrLen;
		ArrayList<Integer> positions = new ArrayList<Integer>();
		while(left < inputLength) {
			right += 1;
			while(right < inputLength) {
				if(comparison.compare(inputStr.charAt(right), inputStr.charAt(right-1))) {
					right += 1;
				}
				else {
					break;
				}
			}
			subStrLen = right - left;
			if(subStrLen > maxLen) {
				maxLen = subStrLen;
				positions.clear();
				positions.add(left);
			}
			else if(subStrLen == maxLen) {
				positions.add(left);
			}
			left = right;
		}
		for(int pos: positions) {
			longestSubStr.add(inputStr.substring(pos, pos+maxLen));
		}
		return longestSubStr;
	}
	//Define interface for compare method
	interface CompareOperation {
		boolean compare(char a, char b);
	}
}
