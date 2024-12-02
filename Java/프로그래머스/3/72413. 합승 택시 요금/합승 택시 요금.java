// import java.util.*;

// /*
// S에서 시작해서 A와 B 모두 가야함. 이때 비용은 최소가 되어야함.
// 어느 길로 갈지는 모르겠는데, 비용은 "최소 비용으로"
// => 각 운임을 c로 두고 최단거리를 구하는 문제.

// */

// class Solution {
//     final long INF = 1000000000;
    
//     public int solution(int n, int s, int a, int b, int[][] fares) {
//         long answer = INF;
        
//         long[][] dist = new long[n + 1][n + 1];

//         // dist table 초기화
//         for (int i = 1; i <= n; i++) {
//             Arrays.fill(dist[i], INF);
//             dist[i][i] = 0; // 본인
//         }

//         // 그래프ㅜ 초기화
//         for (int[] fare : fares) {
//             int src = fare[0];
//             int dst = fare[1];
//             int cost = fare[2];
//             dist[src][dst] = cost;
//             dist[dst][src] = cost;
//         }

//         for (int k = 1; k <= n; k++) {
//             for (int i = 1; i <= n; i++) {
//                 for (int j = 1; j <= n; j++) {
//                     if (dist[i][k] + dist[k][j] < dist[i][j]) {
//                         dist[i][j] = dist[i][k] + dist[k][j];
//                     }
//                 }
//             }
//         }

//         for (int i = 1; i <= n; i++) {
//             answer = Math.min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
//         }
        
//         return (int)answer;
//     }
// }

import java.util.*;

class Solution {
    static final long INF = 1000000000;
    static List<int[]>[] graph;

    public int solution(int n, int s, int a, int b, int[][] fares) {
        graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] fare : fares) {
            int src = fare[0];
            int dst = fare[1];
            int cost = fare[2];
            graph[src].add(new int[]{dst, cost});
            graph[dst].add(new int[]{src, cost});
        }

        long answer = INF;

        // i를 경유하는 비용 계산
        for (int i = 1; i <= n; i++) {
            long cost = dijkstra(s, i) + dijkstra(i, a) + dijkstra(i, b);
            answer = Math.min(answer, cost);
        }

        return (int) answer;
    }

    private long dijkstra(int start, int target) {
        long[] dist = new long[graph.length];
        Arrays.fill(dist, INF);
        dist[start] = 0;

        PriorityQueue<long[]> pq 
            = new PriorityQueue<>(Comparator.comparingLong(o -> o[0]));
        pq.offer(new long[]{0, start});

        while (!pq.isEmpty()) {
            long[] current = pq.poll();
            long cost = current[0];
            int now = (int) current[1];

            if (now == target) // 도착
                return cost; 
            
            if (cost > dist[now]) 
                continue;

            for (int[] next : graph[now]) {
                int nextNode = next[0];
                long nextCost = cost + next[1];
                if (nextCost < dist[nextNode]) {
                    dist[nextNode] = nextCost;
                    pq.offer(new long[]{nextCost, nextNode});
                }
            }
        }

        return INF;
    }
}

/*
다익스트라
테스트 1 〉	통과 (31.88ms, 56.9MB)
테스트 2 〉	통과 (88.52ms, 63.4MB)
테스트 3 〉	통과 (45.10ms, 60.7MB)
테스트 4 〉	통과 (42.35ms, 60MB)
테스트 5 〉	통과 (46.95ms, 60.9MB)
테스트 6 〉	통과 (80.46ms, 79MB)
테스트 7 〉	통과 (165.35ms, 77.1MB)
테스트 8 〉	통과 (184.09ms, 79.2MB)
테스트 9 〉	통과 (161.05ms, 76.9MB)
테스트 10 〉	통과 (148.26ms, 76.1MB)
테스트 11 〉	통과 (182.44ms, 77.7MB)
테스트 12 〉	통과 (139.71ms, 75.9MB)
테스트 13 〉	통과 (140.74ms, 75.7MB)
테스트 14 〉	통과 (156.46ms, 78MB)
테스트 15 〉	통과 (171.79ms, 77.2MB)
테스트 16 〉	통과 (55.87ms, 61.5MB)
테스트 17 〉	통과 (49.60ms, 61.6MB)
테스트 18 〉	통과 (51.83ms, 61.5MB)
테스트 19 〉	통과 (81.94ms, 66.1MB)
테스트 20 〉	통과 (89.40ms, 68.8MB)
테스트 21 〉	통과 (115.62ms, 72MB)
테스트 22 〉	통과 (167.69ms, 80MB)
테스트 23 〉	통과 (172.20ms, 77.9MB)
테스트 24 〉	통과 (152.76ms, 78.7MB)
테스트 25 〉	통과 (38.80ms, 60MB)
테스트 26 〉	통과 (37.86ms, 60.6MB)
테스트 27 〉	통과 (101.87ms, 69.3MB)
테스트 28 〉	통과 (94.94ms, 68.5MB)
테스트 29 〉	통과 (27.58ms, 56.6MB)
테스트 30 〉	통과 (24.22ms, 56MB)

평균 : 101.58ms

플로이드 워셜
테스트 1 〉   통과 (11.73ms, 53.8MB)
테스트 2 〉   통과 (20.75ms, 55.4MB)
테스트 3 〉   통과 (29.38ms, 55MB)
테스트 4 〉   통과 (28.28ms, 55.2MB)
테스트 5 〉   통과 (30.34ms, 54.9MB)
테스트 6 〉   통과 (27.48ms, 54.3MB)
테스트 7 〉   통과 (50.53ms, 66.5MB)
테스트 8 〉   통과 (40.05ms, 67.1MB)
테스트 9 〉   통과 (53.64ms, 67MB)
테스트 10 〉   통과 (60.16ms, 67.2MB)
테스트 11 〉   통과 (56.46ms, 67.3MB)
테스트 12 〉   통과 (43.20ms, 62.2MB)
테스트 13 〉   통과 (46.62ms, 63MB)
테스트 14 〉   통과 (66.00ms, 61.1MB)
테스트 15 〉   통과 (68.23ms, 62.7MB)
테스트 16 〉   통과 (36.84ms, 54.4MB)
테스트 17 〉   통과 (28.62ms, 53.8MB)
테스트 18 〉   통과 (29.36ms, 54.5MB)
테스트 19 〉   통과 (29.57ms, 54.8MB)
테스트 20 〉   통과 (30.03ms, 55.1MB)
테스트 21 〉   통과 (30.17ms, 57.6MB)
테스트 22 〉   통과 (83.95ms, 78MB)
테스트 23 〉   통과 (51.44ms, 61.6MB)
테스트 24 〉   통과 (80.97ms, 65.1MB)
테스트 25 〉   통과 (34.41ms, 55.6MB)
테스트 26 〉   통과 (28.70ms, 55MB)
테스트 27 〉   통과 (32.17ms, 57.1MB)
테스트 28 〉   통과 (29.26ms, 55.8MB)
테스트 29 〉   통과 (10.41ms, 54.5MB)
테스트 30 〉   통과 (11.22ms, 53.9MB)

평균 : 39.33ms
*/
