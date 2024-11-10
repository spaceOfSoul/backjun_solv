import java.io.*;
import java.util.*;

public class Main{

    private static final int DUMMY = -999999999;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] numbers = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int result = DUMMY;

        for(int a = -200; a < 200; a++){
            for(int b = -200000; b <= 200000; b++){
                Boolean flag = true;

                for(int i=1; i<N; i++){
                    if(numbers[i-1]*a + b != numbers[i]){
                        flag = false;
                        break;
                    }
                }

                if (flag && result == DUMMY){
                    result = numbers[N-1]*a+b;
                }else if(flag && result != DUMMY){
                    if(result == numbers[N-1]*a+b)
                        continue;
                    System.out.print("A");
                    return;
                }
            }
        }

        if(result == DUMMY){
            System.out.println("B");
        }else{
            System.out.println(result);
        }
    }
}