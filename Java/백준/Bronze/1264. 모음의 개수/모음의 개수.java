import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(1==1){
            String input = br.readLine();

            int count = 0;

            for(char i:input.toCharArray()){
                if(i=='#')
                    return;
                if((i=='a' || i== 'e' || i== 'i'||i== 'o'||i== 'u')
                    || (i=='A' || i== 'E' || i== 'I'||i== 'O'||i== 'U'))
                    count++;
            }
            System.out.println(count);
        }
        
    }
}