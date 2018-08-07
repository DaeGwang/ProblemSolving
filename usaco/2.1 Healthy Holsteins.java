/*
ID: eorhkd1
LANG: JAVA
TASK: holstein
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;



public class holstein {
	static int v = 0;
	static int[] vita = new int[30];
	static int[][] feed = new int[30][30];
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("holstein.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("holstein.out")));

		v = Integer.parseInt(f.readLine());
		StringTokenizer st = new StringTokenizer(f.readLine());
		for(int i=0; i<v; i++){
			vita[i] = Integer.parseInt(st.nextToken());
		}
		int g = Integer.parseInt(f.readLine());
		
		for(int i=0; i<g; i++){
			st = new StringTokenizer(f.readLine());
			for(int j=0; j<v; j++){
				feed[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int min = g;
		ArrayList<Integer> minArr = new ArrayList<Integer>();
		for(int i=0; i<(1<<g); i++){
			int curV[] = new int[30];
			ArrayList<Integer> arr = new ArrayList<Integer>();
			for(int j=0; j<g; j++){
				if(((1<<j)&i) != 0){
					for(int k=0; k<v; k++){
						curV[k] += feed[j][k];
					}
					arr.add(j+1);
				}
			}
			int chk = 0;
			for(int k=0; k<v; k++){
				if(curV[k] >= vita[k]) chk++;
			}

			if(chk==v && arr.size() <= min && arr.size() != 0){
				min = arr.size();
				minArr = arr;
			}
		}
		
		out.print(min);
		for(int i=0; i<minArr.size(); i++){
			out.print(" " + minArr.get(i));
		}
		out.println();
		out.close();  
	}

}
