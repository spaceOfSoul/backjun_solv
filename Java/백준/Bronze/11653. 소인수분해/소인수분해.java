import java.io.*;

public class Main{
    public static void main(String arg[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        
        int i=2;
        while(i<=Math.sqrt(n)){
            if(n%i==0){
                System.out.println(i);
                n /= i;
            }else{
                i++;
            }
        }

        if(n != 1)
            System.out.println(n);
    }
}