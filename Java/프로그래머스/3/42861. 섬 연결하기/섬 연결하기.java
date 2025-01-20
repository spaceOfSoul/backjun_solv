import java.util.*;

class Solution {
    private static int[] parent;

    public static int solution(int n, int[][] costs) {
        Arrays.sort(costs, (a, b) -> a[2] - b[2]);

        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int totalCost = 0;
        int edgesUsed = 0;

        for (int[] edge : costs) {
            int islandA = edge[0];
            int islandB = edge[1];
            int cost = edge[2];

            // 연결 없으면 연결 ㄱ
            if (!(find(islandA) == find(islandB))) {
                union(islandA, islandB);
                totalCost += cost;
                edgesUsed++;

                if (edgesUsed == n - 1) {
                    break;
                }
            }
        }

        return totalCost;
    }
    
     private static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;  
        }
    }

    private static boolean isConnected(int a, int b) {
        return find(a) == find(b);
    }

    private static int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }
}