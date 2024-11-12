import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] isSubmit = new boolean[30];

        for (int i = 0; i<28; i++) {
            int inputs = Integer.parseInt(br.readLine());
            isSubmit[inputs - 1] = true;
        }
        
        for (int i = 0; i<30; i++) {
            if(!isSubmit[i]){
                System.out.println(i+1);
            }
        }
    }
}