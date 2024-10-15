
import java.io.*;

// don't change 'Main' class name and  'public' accessor. 

public class Main {
    public static void main(String[] args) throws IOException { 
        
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int tmp = Integer.parseInt(bf.readLine());

        for(int i=0; i<tmp; i++){
            System.out.print("LoveisKoreaUniversity");
            System.out.print(" ");
        }
    }
}