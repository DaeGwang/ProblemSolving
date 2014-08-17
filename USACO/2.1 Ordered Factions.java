package sec2;
/*
ID: eorhkd1
LANG: JAVA
TASK: frac1
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.TreeMap;

public class frac1 {

	public static int gcd(int a, int b){
		if(b==0) return a;
		else return gcd(b, a%b);
	}
	
	public static boolean check(int up, int down){
		for(int i=2; i<=up; i++){
			if(down % i == 0) return false;
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("frac1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("frac1.out")));

		int n = Integer.parseInt(f.readLine());
		
		TreeMap<Double, String> tr = new TreeMap<Double, String>();
		
		out.println("0/1");
		for(int i=1; i<n; i++){
			for(int j=n; j>i; j--){
				if(gcd(i,j) != 1) continue;
				tr.put(((double)i/(double)j), i + "/" + j);
			}
		}
		for(Double key : tr.keySet()){
			out.println(tr.get(key));
		}
		out.println("1/1");
		out.close();
	}

}
