/*
ID: eorhkd1
LANG: JAVA
TASK: hamming
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;



public class hamming {

	static int distance(int a, int b){
		int diff = 0;
		for(int j=0; j<8; j++){
			if((a&(1<<j)) != ((b)&(1<<j))){
				diff++;
			}
		}
		return diff;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("hamming.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("hamming.out")));

		StringTokenizer st = new StringTokenizer(f.readLine());
		int n = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		
		ArrayList <Integer> arr = new ArrayList<Integer>();
		arr.add(0);
		for(int i=0; i<(2<<b); i++){
			boolean chk = true;
			for(int j=0; j<arr.size(); j++){
				if(distance(arr.get(j), i)<d) chk = false;
			}
			if(chk && arr.size()<n) arr.add(i);
		}
		
		for(int i=0; i<arr.size(); i++){
			if(i%10 != 9){
				if(i==arr.size()-1) out.println(arr.get(i));
				else out.print(arr.get(i) + " ");
			}
			else{
				out.println(arr.get(i));	
			}
		}
		out.close();  
	}

}
