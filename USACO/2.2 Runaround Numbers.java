/*
ID: eorhkd1
LANG: JAVA
TASK: runround
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;



public class runround {

	public static boolean round(int n){
		String s = Integer.toString(n);
		int len = s.length();
		boolean chk[] = new boolean[10];
		int p = 0;
		int num = 0;
		int flag = 0;
		while(true)
		{
			//check zero
			num = s.charAt(p)-'0';
			if(num == 0) return true;
			//check unique digits
			if(chk[num]){
				break;
			}
			else chk[num] = true;
			//check Runaround 
			p = (p+num) % len;
			flag++;
		}
		if(p != 0) return true;
		for(int i=0; i<len; i++){
			if(!chk[s.charAt(i)-'0']) return true;
		}
		return (flag != len);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("runround.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("runround.out")));

		int m = Integer.parseInt(f.readLine());
		
		while(round(++m));
		out.println(m);
		out.close();  
	}

}
