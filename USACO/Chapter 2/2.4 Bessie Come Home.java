/*
ID: eorhkd1
LANG: JAVA
TASK: comehome
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



public class comehome {

	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("comehome.in");
		PrintWriter out = OutputWriter("comehome.out");
		
		int n = in.nextInt();
		int m[][] = new int[200][200];
		for(int i=0; i<n; i++){
			int a = in.next().toString().charAt(0);
			int b = in.next().toString().charAt(0);
			int val = in.nextInt();

			if(m[a][b] == 0 || m[a][b] > val){
				m[a][b] = val;
				m[b][a] = val;
			}
		}
		int flag = 1;
		while(flag==1){
			flag = 2;
			for(int i=0; i<200; i++){
				for(int j=0; j<200; j++){
					for(int k=0; k<200; k++){
						if(m[i][j] != 0 && m[j][k] != 0){
							if(m[i][k] == 0){
								m[i][k] = m[i][j] + m[j][k];
								flag=1;
							}
							else if(m[i][j] + m[j][k] < m[i][k]){
								m[i][k] = m[i][j] + m[j][k];
								flag=1;
							}
						}
					}
				}
			}
		}
		int max = Integer.MAX_VALUE;
		char maxc = ' ';
		for(int i=0; i<200; i++){
			if(i >= 'A' && i<'Z'){
				if(m['Z'][i] != 0 && m['Z'][i] < max){
					max = m['Z'][i];
					maxc = (char)i;
				}
			}
		}
		out.println(maxc + " " + max);
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


