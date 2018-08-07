/*
ID: eorhkd1
LANG: JAVA
TASK: prefix
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



public class prefix {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("prefix.in");
		PrintWriter out = OutputWriter("prefix.out");
		
		ArrayList<String> arr = new ArrayList<String>();
		while(true){
			String s = in.next();
			if(s.equals(".")) break;
			else arr.add(s);
		}
				
		StringBuilder sb = new StringBuilder();
		while (true) {
			String line = in.next();
			if(line != null) sb.append(line);
			else break;
		}
		String str = sb.toString();
		
		int chk[] = new int[200001];
		int result = 0;
		for(int i=0; i<arr.size(); i++){
			String key = arr.get(i);
			if(key.equals(str.substring(0,key.length()))){
				chk[key.length()] = 1;
			}
		}
		for(int i=1; i<=str.length(); i++){
			if(chk[i]!=0){
				for(int j=0; j<arr.size(); j++){
					String key = arr.get(j);
						if(i+key.length() <= str.length() && key.equals(str.substring(i, i+key.length()))){
							chk[i+key.length()] = 1; 
						}
				}
			}
		}
		for(int i=0; i<=str.length(); i++){
			if(chk[i]!=0) result = i;
		}
		out.println(result);
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
	            	String line = reader.readLine();
	            	if(line==null) return null;
	            	else tokenizer = new StringTokenizer(line);
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


