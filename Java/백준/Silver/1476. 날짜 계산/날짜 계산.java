import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] inputs = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int e = 0; // 15
        int s = 0; // 28
        int m = 0; // 19

        int result = 0;

        for (int i = 1; i<=Integer.MAX_VALUE; i++) {
            result++;
            e++;s++;m++;

            if(e >15){
                e=1;
            }
            if(s >28){
                s=1;
            }
            if(m >19){
                m=1;
            }

            if(e==inputs[0] && s==inputs[1] && m==inputs[2])
                break;
        }

        System.out.println(result);
    }
}