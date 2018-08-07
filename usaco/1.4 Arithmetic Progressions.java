/*
ID: eorhkd1
LANG: JAVA
TASK: ariprog
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.TreeMap;


public class ariprog {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("ariprog.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));

		int n = Integer.parseInt(f.readLine());
		int m = Integer.parseInt(f.readLine());
		
		TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int test[] = new int[200000];
		for(int i=0; i<=m; i++){
			for(int j=0; j<=m; j++){
				if(test[i*i+j*j] != 1) arr.add(i*i+j*j);
				test[i*i+j*j] = 1;
			}
		}
		
		int num = 0;
		Collections.sort(arr);
		for(int i=1; i<=(2*m*m)/(n-1); i++){
			for(int k=0; k<arr.size(); k++){
				for(int j=0; j<n; j++){
					if(test[arr.get(k)+i*j] != 1) break;
					if(j==n-1){
						out.println(arr.get(k) + " " + i);
						num++;
					}
				}
			}
		}
		if(num == 0) out.println("NONE");
		out.close();                                
	}

}
