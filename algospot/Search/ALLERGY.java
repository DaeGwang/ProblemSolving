import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
	public static int food;
	public static int man;
	public static int re[][];
	public static String name[];
	public static int ans;
	public static int check[];
	public static int foodCheck[];
	
	public static void find(int count){
		if(count > ans) return;
		int manNumber = -1;
		for(int i=0; i<man; i++){
			if(check[i]==0){
				manNumber = i;
				break;
			}
		}
		
		if(manNumber==-1){
			if(count < ans) ans = count;
			return;
		}
		
		for(int i=0; i<food; i++){
			if(re[manNumber][i]==1){
				foodCheck[i] = 1;
				for(int j=0; j<man; j++) if(re[j][i]==1) check[j]++;
				find(count+1);
				for(int j=0; j<man; j++) if(re[j][i]==1) check[j]--;
				foodCheck[i] = 0;
			}
		}
		
	}
	
	
	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("input.txt"));
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int idx=0; idx<T; idx++){
			man = sc.nextInt();
			food = sc.nextInt();
			ans = Integer.MAX_VALUE;
			re=new int[man][food];
			name=new String[man];
			check = new int[man];
			foodCheck = new int[food];
			
			for(int i=0; i<man; i++){
				name[i] = sc.next();
			}
			
			for(int i=0; i<food; i++){
				int numberOfMans = sc.nextInt();
				for(int j=0; j<numberOfMans; j++){
					String nowName = sc.next();
					for(int k=0; k<man; k++){
						if(name[k].equals(nowName)){
							re[k][i] = 1;
							break;
						}
					}
				}
			}
			
			find(0);
			
			System.out.println(ans);
		}
	}
}
