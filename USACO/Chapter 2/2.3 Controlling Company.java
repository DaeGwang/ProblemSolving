/*
ID: eorhkd1
LANG: JAVA
TASK: concom
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class concom {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("concom.in");
		PrintWriter out = OutputWriter("concom.out");
		
		int n = in.nextInt();
		int v[][] = new int[101][101];
		int t[][] = new int[101][101];
		boolean c[][] = new boolean[101][101];
		for(int i=0; i<n; i++){
			int a = in.nextInt();
			int b = in.nextInt();
			int val = in.nextInt();
			v[a][b] = val;
			t[a][b] = val;
		}
		int f = 1;
		for(int a=0; a<1; a++){
			for(int i=1; i<=100; i++){
				for(int j=1; j<=100; j++){
					if(t[i][j] >= 50 && !c[i][j]){
						c[i][j] = true;
						for(int k=1; k<=100; k++){
							if(v[j][k]!=0){
								t[i][k] += v[j][k];
								a--;
							}
						}
					}
				}
			}
		}
		
		for(int i=1; i<=100; i++){
			for(int j=1; j<=100; j++){
				if(t[i][j]>=50 && i!=j) out.println(i + " " + j);
			}
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


