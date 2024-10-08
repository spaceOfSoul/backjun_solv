import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        long result = 0;
        Integer[] arr = new Integer[n];

        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        Arrays.sort(arr);

        // test print
        for(int i =1; i<=n; i++){
            result += Math.abs(i-arr[i-1]);
        }

        System.out.print(result);
    }
}
