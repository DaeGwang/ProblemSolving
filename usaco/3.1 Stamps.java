/*
ID: eorhkd1
PROB: stamps
LANG: JAVA
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

public class stamps {
	
	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("stamps.in");
		PrintWriter out = OutputWriter("stamps.out");
		
		int k = in.nextInt();
		int n = in.nextInt();
		int s[] = new int[n];
		for(int i=0; i<n; i++){
			s[i] = in.nextInt();
		}
		
		int[] m = new int[k*10000+2];
		Arrays.fill(m,1000000);
		m[0] = 0;
		int ans = 0;
		for(int j=0; j<m.length;j++)
		{
			for(int i=0; i<n;i++)
			{
				if(j-s[i] >= 0)
					m[j] = Math.min(m[j],m[j-s[i]]+1);
			}
			if(m[j] > k)
			{
				ans = j;
				break;
			}
		}
		out.println(ans-1);
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

