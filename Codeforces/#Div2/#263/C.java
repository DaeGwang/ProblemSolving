import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;



public class C {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader();
		PrintWriter out = OutputWriter();
		
		int n = in.nextInt();
		ArrayList<Integer> arr = new ArrayList<Integer>();
		long total = 0;
		for(int i=0; i<n; i++){
			int num = in.nextInt();
			arr.add(num);
			total += num;
		}
		
		long now = total;
		long sum = total;
		Collections.sort(arr);
		for(int i=0; i<arr.size()-1; i++){
			sum += now;
			now -= arr.get(i);
		}
		
		out.println(sum);
		out.close();
		
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

