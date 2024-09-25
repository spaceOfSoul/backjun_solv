
import java.io.*;

// don't change 'Main' class name and  'public' accessor. 

public class Main {

    static int combination(int n, int r){
        int result = 1;
        int tmp = 1;

        for(int i=n; i>n-r; i--){
            result*=i;
            result /= tmp++;
        }
        return result;
    }
    public static void main(String[] args) throws IOException { 
        
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(bf.readLine());

        for(int t=0;t<T; t++){
            String[] input = bf.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int m = Integer.parseInt(input[1]);

            System.out.println(combination(m,n));
        }
    }
}