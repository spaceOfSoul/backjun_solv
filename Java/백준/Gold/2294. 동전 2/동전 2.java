import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        int[] values = new int[n];
        int[] dp = new int[k+1];
        Arrays.fill(dp, 9999999);// 대충 큰값
        dp[0] = 0;

        for(int i=0; i<n; i++)
            values[i] = Integer.parseInt(br.readLine());

        // 동전 유형임. 먼저 values를 순회
        for(int i=0; i<n; i++){
            for(int j=values[i]; j<=k; j++){ // i번째 동전을 사용해서 j원을 만드는 경우의 수를 dp에 기재할거임. j가 k가 될때까지 ㄱㄱ.
                // 'j원 - i번째 동전 가치'에 i번 동전 한개 더 쓰면 j원 만들기 가능.
                // 'j원 - i번째 동전 가치'를 만드는 개수와 기존에 j원을 구성하던 개수를 비교
                dp[j] = Math.min(dp[j], dp[j-values[i]] + 1); 
            }
        }

        if(dp[k] == 9999999)
            System.out.print(-1);
        else
            System.out.print(dp[k]);
    }
}
