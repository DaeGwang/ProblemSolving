/*
ID: eorhkd1
LANG: JAVA
TASK: lamps
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



public class lamps {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("lamps.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lamps.out")));
		
		int n = Integer.parseInt(f.readLine());
		int c = Integer.parseInt(f.readLine());
		StringTokenizer st = new StringTokenizer(f.readLine());
		ArrayList<String> onArr = new ArrayList<String>();
		while(true){
			if(st.hasMoreTokens()){
				String on = st.nextToken();
				onArr.add(on);
			}
			else{
				break;
			}
		}
		st = new StringTokenizer(f.readLine());
		ArrayList<String> offArr = new ArrayList<String>();
		while(true){
			if(st.hasMoreTokens()){
				String off = st.nextToken();
				offArr.add(off);
			}
			else{
				break;
			}
		}
		
		ArrayList<String> resultArr = new ArrayList<String>();
		String s = "";
		
		for(int i=0; i<n; i++){
			s+="1";
		}
		for(int i=0; i<(1<<4); i++){
			String result = "";
			int press = 0;
			if((i&(1<<0))!=0) press++;
			if((i&(1<<1))!=0) press++;
			if((i&(1<<2))!=0) press++;
			if((i&(1<<3))!=0) press++;
			
			for(int j=0; j<s.length(); j++){
				int current = s.charAt(j) - '0';
				if((i&(1<<0))!=0) current = (current+1)&1;
				if((i&(1<<1))!=0 && j % 2 == 1) current = (current+1)&1;
				if((i&(1<<2))!=0 && j % 2 == 0) current = (current+1)&1;
				if((i&(1<<3))!=0 && j % 3 == 0) current = (current+1)&1;
				result += current;
			}
			boolean flag = true;
			for(int k=0; k<onArr.size()-1; k++){
				if(result.charAt(Integer.parseInt(onArr.get(k))-1)!='1') flag = false;
			}
			for(int k=0; k<offArr.size()-1; k++){
				if(result.charAt(Integer.parseInt(offArr.get(k))-1)!='0') flag = false;
			}
			if(flag && i%2 == c%2 && press <= c){
				resultArr.add(result);
			}
		}
		Collections.sort(resultArr);
		if(resultArr.size()==0){
			out.println("IMPOSSIBLE");
		}
		else{
			for(int i=0; i<resultArr.size(); i++){
				out.println(resultArr.get(i));
			}
		}
		out.close();  
	}

}
