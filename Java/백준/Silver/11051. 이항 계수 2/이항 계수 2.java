import java.io.*;

public class Main{

    static int[][] p = new int[1001][1001];

    public static void pTriangle(int n){
        p[0][0] = 1;
        for (int i=1; i<=n; i++){
            // 어차피 외곽은 1
            p[i][0] = 1;
            p[i][i] = 1;

            for (int j=1; j<i; j++){
                p[i][j] = (p[i-1][j]%10007 + p[i-1][j-1]%10007)%10007;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);

        pTriangle(n); // 이 파스칼 삼각형이 캐시 테이블 역할을 해줄 것임.

        System.out.print(p[n][k]);
    }
}