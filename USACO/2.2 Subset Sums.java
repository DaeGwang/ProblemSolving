/*
ID: eorhkd1
LANG: JAVA
TASK: subset
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;



public class subset {
	
	public static int num(int target, int num){
		int total = 0;
		return total;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("subset.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("subset.out")));

		int n = Integer.parseInt(f.readLine());
		
		int sum = (n*(n+1))/2;
		if(sum%2==1){
			out.println("0");
			out.close();
			return;
		}
		else{
			sum/=2;
		}
		int dp[][] = new int[50][2000];

	    dp[1][0]=1;
	    dp[1][1]=1;
	    for(int i=2;i<=n;i++)
	    {
	    	for(int j=0;j<=sum;j++)
	        {
	            if(j-i>0) dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
	            else dp[i][j]=dp[i-1][j];
	        }
	    }
		out.println(dp[n][sum]);
		out.close();  
	}

}
