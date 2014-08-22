import java.util.Scanner;

public class main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);
		int a = Integer.parseInt(scan.next());
		int[] b = new int[a];
		
		for(int i=0; i<a; i++){
			b[i] = Integer.parseInt(scan.next());
		}
		
		System.out.println(check(b));
				
	}
	public static int check(int[] arr){
		int flag = 0, flagNum = 0;
		int flagStart = 0;
		int first = 0, next = 0;
		int len = arr.length;
		
		while(true){
			first = next;
			if(first == len-1){
				next = 0;
			}
			else{
				next= first+1;
			}
			if(arr[first] <= arr[next]){
				flagNum ++;
				if(flagNum == len - 1){
					if(flag == 1) return len - flagStart;
					if(flag == 0) return flagStart;
				}
			}
			else{
				flagStart = next;
				flagNum = 0;
				if(flag < 2){
					flag++;
				}
				else{
					return -1;
				}
			}
		}

	}
	
}