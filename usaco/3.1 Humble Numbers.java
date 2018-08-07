package sec3;
/*
ID: eorhkd1
LANG: JAVA
TASK: inflate
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class inflate {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("inflate.in");
		PrintWriter out = OutputWriter("inflate.out");
		
		int m = in.nextInt();
		int n = in.nextInt();
		int res[] = new int[100000];
		for(int i=0; i<n; i++){
			int p = in.nextInt();
			int s = in.nextInt();
			for(int j=s; j<=m; j++){
			res[j] = Math.max(res[j], res[j-s]+p);
			}
		}
		out.println(res[m]);
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


