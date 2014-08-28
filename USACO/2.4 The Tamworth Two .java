/*
ID: eorhkd1
LANG: JAVA
TASK: ttwo
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;



public class ttwo {

	public static XY man = new XY();
	public static XY cow = new XY();
	public static void main(String[] args) throws IOException {

		InputReader in = new InputReader("ttwo.in");
		PrintWriter out = OutputWriter("ttwo.out");
		
		boolean chk[][] = new boolean[12][12];
		for(int i=1; i<11; i++){
			String line = in.nextLine();
			for(int j=1; j<11; j++){
				if(line.charAt(j-1) == 'F'){
					man.x = i;
					man.y = j;
					man.dir = 0;
					chk[i][j] = true;
				}
				if(line.charAt(j-1) == 'C'){
					cow.x = i;
					cow.y = j;
					cow.dir = 0;
					chk[i][j] = true;
				}
				if(line.charAt(j-1) == '.') chk[i][j] = true;
			}
		}
		
		int dx[] = {-1, 0, 1, 0};
		int dy[] = {0, 1, 0, -1};
		boolean flag = false;
		int result = 0;
		for(int i=1; i<=160000; i++){
			if(chk[man.x+dx[man.dir]][man.y+dy[man.dir]]){
				man.x += dx[man.dir];
				man.y += dy[man.dir];
			}
			else{
				man.rotate();
			}
			if(chk[cow.x+dx[cow.dir]][cow.y+dy[cow.dir]]){
				cow.x += dx[cow.dir];
				cow.y += dy[cow.dir];
			}
			else{
				cow.rotate();
			}
			if(man.x == cow.x && man.y == cow.y){
				result = i;
				break;
			}
		}
		if(result != 0) out.println(result);
		else out.println(0);
		out.close();
		
	}
	static class XY{
		int x;
		int y;
		int dir;
		XY(){
			
		}
		void rotate(){
			dir = (dir+1) % 4;
		}
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
	    public String nextLine() throws IOException{
	    	return reader.readLine();
	    }
	    public int nextInt() {
	        return Integer.parseInt(next());
	    }

	}
}


