import java.util.*;


class Solution {
    public int solution(int[][] maps) {
        int answer = 0;
        
        int[] dx = new int[]{0,0,1,-1};
        int[] dy = new int[]{1,-1,0,0};

        int n = maps.length;
        int m = maps[0].length;
        Queue<int[]> que = new LinkedList<>();
        int[][] visited = new int[100][100];
        
        que.offer(new int[]{0,0});
        visited[0][0] = 1;
        
        while(!que.isEmpty())
        {
            int[] cur = que.poll();
            
            int x = cur[0];
            int y = cur[1];
            
            for(int i=0; i<4; i++){
                int nx = x+dx[i];
                int ny = y+dy[i];
                
                if(nx < 0 || ny < 0 || nx >=n || ny >= m)
                    continue;
                if(maps[nx][ny] == 0 || visited[nx][ny] != 0)
                    continue;
                
                visited[nx][ny] = visited[x][y] +1;
                que.offer(new int[]{nx, ny});
            }
        }
        
        if(visited[n-1][m-1] == 0){
            answer = -1;
        }else{
            answer = visited[n-1][m-1];
        }
        
        return answer;
    }
}