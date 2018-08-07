/*
ID: eorhkd1
PROG: combo
LANG: JAVA
*/
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class combo {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("combo.in");
		PrintWriter out = OutputWriter("combo.out");
		
		int n = in.nextInt();
		
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		int e = in.nextInt();
		int f = in.nextInt();
		
		int res = 0;
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){// if(i!=j){
				for(int k=1; k<=n; k++){// if(k!=i && k!=j){
					int flag = 0;
					if(Math.abs(i-a) <= 2 || Math.abs(i-a) >= n-2){
						if(Math.abs(j-b) <= 2 || Math.abs(j-b) >= n-2){
							if(Math.abs(k-c) <= 2 || Math.abs(k-c) >= n-2){
								res++;
								flag = 1;
							}
						}
					}
					if(Math.abs(i-d) <= 2 || Math.abs(i-d) >= n-2){
						if(Math.abs(j-e) <= 2 || Math.abs(j-e) >= n-2){
							if(Math.abs(k-f) <= 2 || Math.abs(k-f) >= n-2){
								if(flag != 1) res++;
							}
						}
					}
				}
			}
		}
		
		out.println(res);
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

