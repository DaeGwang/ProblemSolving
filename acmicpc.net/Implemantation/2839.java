
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static int dp[] = new int[5001];
	public static int solve(int n){
		if(n < 0) return 10000;
		if(dp[n]!=-1) return dp[n];
		if(n == 0) return 0;
		return dp[n] = Math.min(solve(n - 5) + 1, solve(n - 3) + 1);
	}
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Arrays.fill(dp, -1);
		int res = solve(n);
		res = res >= 10000 ? -1 : res;
		System.out.println(res);
		sc.close();
	}

}
