import java.io.*;
import java.util.*;

class Node {
    int edgeSize;
    List<Integer> edge;

    public Node() {
        edge = new ArrayList<>();
        edgeSize = 0;
    }
}

public class Main {
    static void tsortPrint(Node[] graph, int[] indegree, int n) {
        Queue<Integer> que = new LinkedList<>();
        int[] result = new int[n];
        int idx = 0;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                que.add(i);
            }
        }

        boolean possible = true;
        for (int i = 0; i < n; i++) {
            if (que.isEmpty()) {
                possible = false;
                break;
            }

            int now = que.poll();
            result[idx++] = now;

            for (int j = 0; j < graph[now].edgeSize; j++) {
                int dest = graph[now].edge.get(j);
                indegree[dest]--;
                if (indegree[dest] == 0) {
                    que.add(dest);
                }
            }
        }

        if (!possible || idx < n) {
            System.out.println("IMPOSSIBLE");
        } else {
            for (int i = 0; i < n; i++) {
                System.out.print(result[i] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int change;
            int a, b;
            int[] beforeRank = new int[n + 1];
            int[] indegree = new int[n + 1];
            Node[] rankGraph = new Node[n + 1];

            // Node 배열의 각 요소를 초기화
            for (int i = 1; i <= n; i++) {
                rankGraph[i] = new Node();
            }

            // 순위를 입력받고 간선 관계를 설정
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                beforeRank[i] = Integer.parseInt(st.nextToken());
            }

            // 순위 간선 설정
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    int u = beforeRank[i];
                    int v = beforeRank[j];
                    rankGraph[u].edge.add(v);
                    rankGraph[u].edgeSize++;
                    indegree[v]++;
                }
            }

            // 순위 변경을 처리
            change = Integer.parseInt(br.readLine());
            while (change-- > 0) {
                st = new StringTokenizer(br.readLine());
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());

                // 간선 방향 변경
                boolean changed = false;

                // a -> b를 b -> a로 변경
                for (int i = 0; i < rankGraph[a].edgeSize; i++) {
                    if (rankGraph[a].edge.get(i) == b) {
                        rankGraph[a].edge.remove(i);  // a -> b 간선 삭제
                        rankGraph[a].edgeSize--;
                        rankGraph[b].edge.add(a);  // b -> a 간선 추가
                        rankGraph[b].edgeSize++;
                        indegree[b]--;
                        indegree[a]++;
                        changed = true;
                        break;
                    }
                }

                // b -> a를 a -> b로 변경
                if (!changed) {
                    for (int i = 0; i < rankGraph[b].edgeSize; i++) {
                        if (rankGraph[b].edge.get(i) == a) {
                            rankGraph[b].edge.remove(i);  // b -> a 간선 삭제
                            rankGraph[b].edgeSize--;
                            rankGraph[a].edge.add(b);  // a -> b 간선 추가
                            rankGraph[a].edgeSize++;
                            indegree[a]--;
                            indegree[b]++;
                            break;
                        }
                    }
                }
            }

            // 위상 정렬 수행
            tsortPrint(rankGraph, indegree, n);
        }

    }
}
