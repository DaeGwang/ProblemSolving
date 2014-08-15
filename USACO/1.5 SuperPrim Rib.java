/*
ID: eorhkd1
LANG: JAVA
TASK: sprime
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;


public class sprime {

	static ArrayList<Integer> ar = new ArrayList<Integer>();
	private static boolean isPrime(int n){
		int t = 2;
		while(t*t<n){
			if(n % t == 0) return false;
			t++;
		}
		return true;
	}
	
	private static void get(int num, int s){
		if(!isPrime(num)) return;
		if(s==1) ar.add(num);
		
		get(num*10+1, s-1);
		get(num*10+3, s-1);
		get(num*10+7, s-1);
		get(num*10+9, s-1);
	}
	public static void main(String[] args) throws IOException {
		
		BufferedReader f = new BufferedReader(new FileReader("sprime.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sprime.out")));
		
		int n = Integer.parseInt(f.readLine());
		
		get(2, n);
		get(3, n);
		get(5, n);
		get(7, n);

		for(int i=0; i<ar.size(); i++){
			out.println(ar.get(i));
		}
		out.close();   
	}

}
