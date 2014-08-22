import java.util.Scanner;


public class main {

	public static void main(String[] args) {

		String in;
		String line = null;
		
		Scanner scan = new Scanner(System.in);
		in = scan.nextLine();
		int n = Integer.parseInt(in);
		int t = -1;
		int flag = 0;
		for(int i=0; i<n; i++){
			if (t == n) flag = 1;
				if(flag == 1){
					t -= 2;
				}
				else{
					t += 2;
				}
				
				int star = (n-t)/2;
				line = "";
				for(int k=0; k<star; k++){
					line += '*';
				}
				for(int k=0; k<t; k++){
					line += 'D';
				}
				for(int k=0; k<star; k++){
					line += '*';
				}
				System.out.println(line);
		}
	}

}