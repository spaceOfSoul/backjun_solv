import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        int[] values = new int[n];
        int[] dp = new int[k+1];
        dp[0] = 1; // 0원

        for(int i=0; i<n; i++)
            values[i] = Integer.parseInt(br.readLine());

        // 동전 유형임. 먼저 values를 순회
        for(int i=0; i<n; i++){
            for(int j=values[i]; j<=k; j++){ // i번째 동전을 사용해서 j원을 만드는 경우의 수를 dp에 기재할거임. j가 k가 될때까지 ㄱㄱ.
                dp[j] += dp[j-values[i]]; // j원 만드는 경우의 수에 values[i]를 보태어 만드는 경우의 수를 추가.
            }
        }

        System.out.print(dp[k]);
    }
}
