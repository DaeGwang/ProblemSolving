/*
ID: eorhkd1
LANG: JAVA
TASK: sort3
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class sort3 {

	static ArrayList<Integer> s = new ArrayList<Integer>();
	static ArrayList<Integer> sorted = new ArrayList<Integer>();
	static int max = 0;
	static int m = 0;
	
	public static void swap(int a, int b){
		int temp = s.get(a);
		s.set(a, s.get(b));
		s.set(b, temp);
	}
	
	public static void checkA(){
		for(int i=0; i<m; i++){
			for(int j=i+1; j<m; j++){
				if(s.get(i) != sorted.get(i) && s.get(j) != sorted.get(j)){
					if(s.get(j) == sorted.get(i) && s.get(i) == sorted.get(j)){
						swap(i, j);
						max++;
					}
				}
			}
		}
	}
	public static void checkB(){
		for(int i=0; i<m; i++){
			for(int j=i+1; j<m; j++){
				if(s.get(i) != sorted.get(i) && s.get(j) != sorted.get(j)){
					if(s.get(j) == sorted.get(i)){
						swap(i, j);
						max++;
					}
				}
			}
		}
	}
	public static boolean test(){
		for(int i=0; i<m; i++){
			if(s.get(i) != sorted.get(i)) return false;
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("sort3.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sort3.out")));

		m = Integer.parseInt(f.readLine());
		for(int i=0; i<m; i++){
			int n = Integer.parseInt(f.readLine());
			s.add(n);
			sorted.add(n);
		}
		
		Collections.sort(sorted);
		while(!test()){
			checkA();
			checkB();
		}
		
		out.println(max);
		out.close();
	}

}
