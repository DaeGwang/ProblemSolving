package sec3;
/*
ID: eorhkd1
LANG: JAVA
TASK: humble
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class humble {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("humble.in");
		PrintWriter out = OutputWriter("humble.out");
		
		int k = in.nextInt();
		int n = in.nextInt();
		
		int h[] = new int[1000001];
		int prime[] = new int[101];
		int index[] = new int[101];
		for(int i=0; i<k; i++){
			prime[i] = in.nextInt();
		}
		h[0] = 1;
		for(int i=1; i<=n; i++){
			int min = Integer.MAX_VALUE;
			for(int j=0; j<k; j++){
				if(prime[j] * h[index[j]] <= h[i-1]) index[j]++;
				if(prime[j] * h[index[j]] < min){
					min = prime[j] * h[index[j]];
				}
			}
			h[i] = min;
		}
		out.println(h[n]);
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


