#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int visited[100][100];

void clear_visited(int x_size, int y_size){
    for(int i=0; i<x_size; i++){
        for(int j=0; j<y_size; j++){
            visited[i][j] = 0;
        }
    }
}

int solution(vector<string> maps) {
    int answer = 0;
    
    int s_x ,s_y;
    int e_x ,e_y;
    int l_x, l_y;
    
    int x_size = maps.size();
    int y_size = maps[0].length();
    for(int i=0; i<x_size; i++){
        for(int j=0; j<y_size; j++){
            if('S' == maps[i][j]){
                s_x = i;
                s_y = j;
            }else if('E' == maps[i][j]){
                e_x =i;
                e_y = j;
            }else if('L' ==  maps[i][j]){
                l_x = i;
                l_y = j;
            }
        }
    }
    
    queue<pair<int, int>> que;
    
    que.push({s_x, s_y});
    visited[s_x][s_y] = 1; // step 저장용으로 쓸거임.
    
    bool l_flag = false;
    bool e_flag = false;
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        if(x==l_x && y==l_y){
            answer += visited[x][y] - 1;
            l_flag = true;
            break;
        }
        
        for(int i=0; i<4; i++){
            int nx = dx[i] + x;
            int ny = y+ dy[i];
            
            if(nx < 0 || nx >= x_size || ny < 0 || ny >= y_size)
                continue;
            if(maps[nx][ny] == 'X')
                continue;
            if(visited[nx][ny])
                continue;
            
            que.push({nx,ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    
    if(!l_flag){
        return -1;
    }
    
    while(!que.empty())
        que.pop();
    clear_visited(x_size, y_size);
    
    que.push({l_x, l_y});
    visited[l_x][l_y] = 1; // step 저장용으로 쓸거임.
    
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        if(x==e_x && y==e_y){
            answer += visited[x][y] - 1;
            e_flag = true;
            break;
        }
        
        for(int i=0; i<4; i++){
            int nx = dx[i] + x;
            int ny = y+ dy[i];
            
            if(nx < 0 || nx >= x_size || ny < 0 || ny >= y_size)
                continue;
            if(maps[nx][ny] == 'X')
                continue;
            if(visited[nx][ny])
                continue;
            
            que.push({nx,ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    
    if(!e_flag)
        return -1;
    
    return answer;
}