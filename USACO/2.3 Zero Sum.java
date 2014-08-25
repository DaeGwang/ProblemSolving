/*
ID: eorhkd1
LANG: JAVA
TASK: zerosum
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;



public class zerosum {
	public static int n = 0;
	public static ArrayList<String> arr = new ArrayList<String>();
	public static void dfs(int flag, int sum, int num, int sign, String result){
		if(flag == n){
			if(sum + sign * num == 0){
				arr.add(result);
			}
			return;
		}
		dfs(flag+1, sum, num*10+(flag+1), sign, result + " " + Integer.toString(flag+1));
		dfs(flag+1, sum+sign*num, (flag+1), 1, result + "+" + Integer.toString(flag+1));
		dfs(flag+1, sum+sign*num, (flag+1), -1, result + "-" + Integer.toString(flag+1));
	}
	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("zerosum.in");
		PrintWriter out = OutputWriter("zerosum.out");
		
		n = in.nextInt();
		dfs(1, 0, 1, 1, "1");
		
		for(int i=0; i<arr.size(); i++){
			out.println(arr.get(i));
		}
		out.close();
		
	}
	
	public static PrintWriter OutputWriter(){
		return new PrintWriter(System.out);
	}
	
	public static PrintWriter OutputWriter(String filename) throws IOException {
		return new PrintWriter(new BufferedWriter(new FileWriter(filename)));
	}

	public static class InputReader {
	    public BufferedReader reader;
	    public StringTokenizer tokenizer;

	    public InputReader() {
	        reader = new BufferedReader(new InputStreamReader(System.in), 32768);
	        tokenizer = null;
	    }
	    public InputReader(String filename) throws IOException {
	        reader = new BufferedReader(new FileReader(filename));
	        tokenizer = null;
	    }
	    public String next() {
	        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                tokenizer = new StringTokenizer(reader.readLine());
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }
	        return tokenizer.nextToken();
	    }

	    public int nextInt() {
	        return Integer.parseInt(next());
	    }

	}
}


