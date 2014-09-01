/*
ID: eorhkd1
LANG: JAVA
TASK: numtri
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class numtri {

	public static void main(String[] args) throws IOException {
		
		BufferedReader f = new BufferedReader(new FileReader("numtri.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("numtri.out")));
		
		int n = Integer.parseInt(f.readLine());
		int [][] data = new int[1001][1001];
		for(int i=0; i<n; i++){
			StringTokenizer st = new StringTokenizer(f.readLine());
			for(int j=0; j<i+1; j++){
				data[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=n-2; i>=0; i--){
			for(int j=0; j<n; j++){
				data[i][j] += (data[i+1][j] > data[i+1][j+1] ? data[i+1][j] : data[i+1][j+1]);
			}
		}
		out.println(data[0][0]);
		out.close();   
	}

}
