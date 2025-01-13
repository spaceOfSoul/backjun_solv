class Solution {
    private int maxDungeons = 0; // 최대 탐험 가능한 던전 수

    public int solution(int k, int[][] dungeons) {
        // 던전 방문 여부를 추적할 배열
        boolean[] visited = new boolean[dungeons.length];
        // DFS 탐색 시작
        explore(k, dungeons, visited, 0);
        return maxDungeons;
    }

    private void explore(int k, int[][] dungeons, boolean[] visited, int count) {
        // 현재 탐험한 던전 수로 최대값 갱신
        maxDungeons = Math.max(maxDungeons, count);

        // 모든 던전에 대해 탐색
        for (int i = 0; i < dungeons.length; i++) {
            if (visited[i]) continue; // 이미 방문한 던전은 스킵

            // 현재 피로도가 해당 던전의 최소 필요 피로도 이상인 경우만 탐험 가능
            if (k >= dungeons[i][0]) {
                visited[i] = true; // 방문 체크
                explore(k - dungeons[i][1], dungeons, visited, count + 1); // 소모 피로도 적용 후 재귀
                visited[i] = false; // 탐험 종료 후 방문 체크 해제
            }
        }
    }
}