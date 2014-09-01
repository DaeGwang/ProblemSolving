/*
ID: eorhkd1
LANG: JAVA
TASK: preface
*/


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;



public class preface {
	static HashMap<String, Integer> map = new HashMap<String, Integer>();
	public static void setNumber(String num){
		int single;
		int len = num.length();
		int flag = 0;
		if(len>=4){
			for(int i=0; i<((int)num.charAt(0)-'0'); i++){
				map.put("M", map.get("M")+1);
			}
			flag++;
		}
		if(len>=3){
			single = (int)num.charAt(flag)-'0';
			if(single == 9){
				map.put("M", map.get("M")+1);
				map.put("C", map.get("C")+1);
			}
			else if(single==4 || single==6){
				map.put("D", map.get("D")+1);
				map.put("C", map.get("C")+1);	
			}
			else{
				if(single>=5){
					map.put("D", map.get("D")+1);
					single-=5;
				}
				for(int i=0; i<single; i++){
					map.put("C", map.get("C")+1);
				}
			}
			flag++;
		}
		if(len>=2){
			single = (int)num.charAt(flag)-'0';
			if(single == 9){
				map.put("C", map.get("C")+1);
				map.put("X", map.get("X")+1);
			}
			else if(single==4 || single==6){
				map.put("L", map.get("L")+1);
				map.put("X", map.get("X")+1);	
			}
			else{
				if(single>=5){
					map.put("L", map.get("L")+1);
					single-=5;
				}
				for(int i=0; i<single; i++){
					map.put("X", map.get("X")+1);
				}
			}
			flag++;
		}
		if(len>=1){
			single = (int)num.charAt(flag)-'0';
			if(single == 9){
				map.put("X", map.get("X")+1);
				map.put("I", map.get("I")+1);
			}
			else if(single==4 || single==6){
				map.put("V", map.get("V")+1);
				map.put("I", map.get("I")+1);	
			}
			else{
				if(single>=5){
					map.put("V", map.get("V")+1);
					single-=5;
				}
				for(int i=0; i<single; i++){
					map.put("I", map.get("I")+1);
				}
			}
			flag++;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("preface.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("preface.out")));

		int n = Integer.parseInt(f.readLine());
		
		map.put("I",0);
		map.put("V",0);
		map.put("X",0);
		map.put("L",0);
		map.put("C",0);
		map.put("D",0);
		map.put("M",0);
		
		for(int i=1; i<=n; i++){
			setNumber(Integer.toString(i));
		}
		String[] seq = {"I","V","X","L","C","D","M"};
		for(int i=0; i<seq.length; i++){
			String key = seq[i];
			if(map.get(key) != 0){
				out.println(key + " " + map.get(key));
			}
		}
		out.close();  
	}

}
