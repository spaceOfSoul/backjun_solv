import java.util.*;

class Solution {
    final long INF = 1000000000;
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        long answer = INF;
        
        long[][] dist = new long[n + 1][n + 1];

        // dist table 초기화
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0; // 본인
        }

        // 그래프ㅜ 초기화
        for (int[] fare : fares) {
            int src = fare[0];
            int dst = fare[1];
            int cost = fare[2];
            dist[src][dst] = cost;
            dist[dst][src] = cost;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            answer = Math.min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
        }
        
        return (int)answer;
    }
}