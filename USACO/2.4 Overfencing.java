/*
ID: eorhkd1
LANG: JAVA
TASK: maze1
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;



public class maze1 {

	static int m[][] = new int[500][500];
	static int f[][] = new int[500][500];
	static int dh[] = {-1, 0, 1, 0};
	static int dw[] = {0, 1, 0, -1};
	
	public static void flood(int x, int y, int n){
		if(m[x][y] == 1 && f[x][y] > n){
			f[x][y] = n;
			for(int i=0; i<4; i++){
				flood(x+dw[i], y+dh[i], n+1);
			}
		}
	}
	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("maze1.in");
		PrintWriter out = OutputWriter("maze1.out");
		

		int w = in.nextInt();
		int h = in.nextInt();
		
		w = 2 * w + 1;
		h = 2 * h + 1;
	
		for(int i=1; i<=h; i++){
			String line = in.nextLine();
			for(int j=1; j<=w; j++){
				if(line.charAt(j-1)==' ') m[i][j] = 1;
			}
		}
		
		for(int i=0; i<=h+1; i++)
			Arrays.fill(f[i], Integer.MAX_VALUE);
		
		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++){
				if(i==1 || j==1 || i==h || j==w)
					if(m[i][j] == 1){
						flood(i,j,1);
					}
			}
		}
		
		int max = 0;
		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++){
				if(f[i][j] != Integer.MAX_VALUE && f[i][j] > max)
					max = f[i][j];
			}
		}
		
		out.println(max/2);
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
	    public String nextLine(){
	    	try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
	    }
	    public int nextInt() {
	        return Integer.parseInt(next());
	    }

	}
}


