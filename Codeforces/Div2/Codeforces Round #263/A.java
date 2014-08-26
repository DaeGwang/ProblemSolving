import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class A {

	
	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader();
		
		int n = in.nextInt();
		int c[][] = new int[101][101];
		for(int i=0; i<n; i++){
			String a = in.next();
			for(int j=0; j<a.length(); j++){
				c[i][j] = a.charAt(j);
			}
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				int num = 0;
				if(i-1>=0 && c[i-1][j] == 'o') num++;
				if(j-1>=0 && c[i][j-1] == 'o') num++;
				if(i+1<n && c[i+1][j] == 'o') num++;
				if(j+1<n && c[i][j+1] == 'o') num++;
				if(num % 2 == 1){
					System.out.println("NO");
					return;
				}
			}
		}
		System.out.println("YES");
		
	}
	
	public static PrintWriter OutputWriter(){
		return new PrintWriter(System.out);
	}
	
	public static class InputReader {
	    public BufferedReader reader;
	    public StringTokenizer tokenizer;
	
	    public InputReader() {
	        reader = new BufferedReader(new InputStreamReader(System.in), 32768);
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

