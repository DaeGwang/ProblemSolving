/*
ID: eorhkd1
LANG: JAVA
TASK: money
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



public class money {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("money.in");
		PrintWriter out = OutputWriter("money.out");
		
		int v = in.nextInt();
		int n = in.nextInt();
		ArrayList<Integer> coin = new ArrayList<Integer>();
		long dp[] = new long[10001];
		for(int i=0; i<v; i++){
			coin.add(in.nextInt());
		}
		
		dp[0] = 1;
		for(int i=0; i<v; i++){
			for(int j=1; j<=n; j++){
				if(j-coin.get(i)>=0){
					dp[j] += dp[j-coin.get(i)];
				}
			}
		}
		
		out.println(dp[n]);
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


