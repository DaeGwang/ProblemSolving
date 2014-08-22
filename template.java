

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class template {

	public static void main(String[] args) {

		InputReader in = new InputReader();
		PrintWriter out = OutputWriter();
		
		out.println();
		out.close();
		
	}
	
	public static PrintWriter OutputWriter(){
		return new PrintWriter(System.out);
	}
	
	public static PrintWriter OutputWriter(String filename) throws IOException {
		return new PrintWriter(new BufferedWriter(new FileWriter(filename)));
	}

}


class InputReader {
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

