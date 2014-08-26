import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;



public class B {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader();
		PrintWriter out = OutputWriter();
		
		int n = in.nextInt();
		int k = in.nextInt();
		
		long max = 0;
		String maxlet = "";
		String s = in.next();
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		for(int i=0; i<s.length(); i++){
			String let = "" + s.charAt(i);
			if(map.containsKey(let)){
				map.put(let, map.get(let)+1);
			}
			else{
				map.put(let, 1);
			}
		}

		long card = k;
		long sum = 0;
		while(card>0){
			for(String key : map.keySet()){
				if(max<map.get(key)){
					max = map.get(key);
					maxlet = key;
				}
			}
			if(card>max){
				sum += max * max;
				card -= max;
			}
			else{
				sum += card * card;
				card -= card;
			}
			map.remove(maxlet);
			max = 0;
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

