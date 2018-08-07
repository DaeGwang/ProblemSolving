/*
ID: eorhkd1
LANG: JAVA
TASK: milk3
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class milk3 {
	static int A, B, C;
	static boolean[] arr = new boolean[21];
	static int[][][] chk = new int[21][21][21];
	public static void pour(int a, int b, int c){
		if(chk[a][b][c] == 1) return;
		chk[a][b][c] = 1;
		
		if(a+b<B) pour(0, a+b, c);
		else pour((a+b)-B, B, c);
		
		if(a+c<C) pour(0, b, a+c);
		else pour((a+c)-C, b, C);
		
		if(b+a<A) pour(b+a, 0, c);
		else pour(A, (b+a)-A, c);
		
		if(b+c<C) pour(a, 0, b+c);
		else pour(a, (b+c)-C, C);

		if(c+a<A) pour(c+a, b, 0);
		else pour(A, b, (c+a)-A);
		
		if(c+b<B) pour(a, c+b, 0);
		else pour(a, B, (c+b)-B);
		
		if(a == 0) arr[c] = true;
		
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("milk3.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk3.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		A = Integer.parseInt(st.nextToken());  
		B = Integer.parseInt(st.nextToken());  
		C = Integer.parseInt(st.nextToken());  
		
		pour(0,0,C);
		
		String s = "";
		for(int i=0; i<arr.length; i++){
			if(arr[i]) s += i + " ";
		}
		s = s.substring(0, s.length()-1);
		out.println(s);
		out.close();    
	}

}
