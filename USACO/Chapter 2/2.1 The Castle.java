/*
ID: eorhkd1
LANG: JAVA
TASK: castle
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class castle {

	static int[][] castle = new int[100][100];
	static int[][] flood = new int[100][100];
	static int[][] ij = new int[100][100];
	static int max[] = new int[10000];
	static int num = 1;
	static int m, n;
	
	public static int fl(int x, int y){
		if(flood[x][y]!=0){
			return 0;
		}
		else{
			flood[x][y] = num;
			max[num]++;
		}

		if((castle[x][y]&1) == 0){
			if(y-1>0) fl(x, y-1);
		}
		if((castle[x][y]&2) == 0){
			if(x-1>0) fl(x-1, y);
		}
		if((castle[x][y]&4) == 0){
			if(y<m) fl(x, y+1);
		}
		if((castle[x][y]&8) == 0){
			if(x<n) fl(x+1, y);
		}
		return 1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("castle.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("castle.out")));

		StringTokenizer st = new StringTokenizer(f.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		
		for(int i=1; i<=n; i++){
			st = new StringTokenizer(f.readLine());
			for(int j=1; j<=m; j++){
				castle[i][j] = Integer.parseInt(st.nextToken());
				flood[i][j] = 0;
			}
		}
		for(int i=0; i<10000; i++){
			max[i] = 0;
		}
		
		
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(fl(i, j)!=0) num++;
			}
		}
		
		int maxNum = 0;
		int maxX = 0;
		int maxY = 0;
		char maxDir = ' ';

		for(int j=1; j<=m; j++){
			for(int i=n; i>=1; i--){
				int x = i, y = j;
				
				if((castle[x][y]&1) != 0){
					if(y-1>0){
						if(flood[x][y-1] != flood[x][y]){
							if(maxNum < max[flood[x][y-1]] + max[flood[x][y]]){
								maxNum = max[flood[x][y-1]] + max[flood[x][y]];
								maxX = i;
								maxY = j;
								maxDir = 'W';
							}
						}
					}
				}
				if((castle[x][y]&2) != 0){
					if(x-1>0){
						if(flood[x-1][y] != flood[x][y]){
							if(maxNum < max[flood[x-1][y]] + max[flood[x][y]]){
								maxNum = max[flood[x-1][y]] + max[flood[x][y]];
								maxX = i;
								maxY = j;
								maxDir = 'N';
							}
						}
					}
				}
				if((castle[x][y]&4) != 0){
					if(y<m){
						if(flood[x][y+1] != flood[x][y]){
							if(maxNum < max[flood[x][y+1]] + max[flood[x][y]]){
								maxNum = max[flood[x][y+1]] + max[flood[x][y]];
								maxX = i;
								maxY = j;
								maxDir = 'E';
							}
						}
					}
				}
				if((castle[x][y]&8) != 0){
					if(x<n){
						if(flood[x+1][y] != flood[x][y]){
							if(maxNum < max[flood[x+1][y]] + max[flood[x][y]]){
								maxNum = max[flood[x+1][y]] + max[flood[x][y]];
								maxX = i;
								maxY = j;
								maxDir = 'S';
							}
						}
					}
				}
			}
		}
		
		out.println(num-1);
		int maxRoom = 0;
		for(int i=1; i<num; i++){
			if(maxRoom < max[i]) maxRoom = max[i];
		}
		out.println(maxRoom);
		out.println(maxNum);
		out.println(maxX + " " + maxY + " " + maxDir);
		out.close();
	}

}
