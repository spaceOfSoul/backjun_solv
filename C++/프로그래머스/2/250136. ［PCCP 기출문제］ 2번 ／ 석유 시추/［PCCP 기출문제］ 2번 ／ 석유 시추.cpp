#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set> // 중복이 안됨
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int dfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, set<int>& ys){
    int result = 1;
    
    int n = land[0].size();
    int m = land.size();
    
    ys.insert(y);

    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx>=m || nx <0 || ny>=n || ny <0)
            continue;
        
        if(!land[nx][ny])
            continue;
        if(visited[nx][ny])
            continue;
        
        visited[nx][ny] = true;
        result += dfs(land, visited, nx, ny, ys);
    }
    
    return result;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int n = land[0].size();
    int m = land.size();
    
    // cout << n << m << "\n";
    
    // for(int i=0; i<n; i++){ // land 길이 만큼
    //     for(int j = 0; j<m; j++){
    //         cout << land[j][i];
    //     }
    //     cout << "\n";
    // }
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    map<int, int> amount_map;
    for(int i=0; i<n; i++){ // 세로로 보기
        for(int j = 0; j<m; j++){ // 가로로 보기
            if(!land[j][i] || visited[j][i])
                continue;
            
            visited[j][i] = true;
            
            set<int> ys;
            int area = dfs(land, visited, j, i, ys);
            
            for(int k : ys){
                if(amount_map.find(k) == amount_map.end())
                    amount_map.insert({k, area});
                else
                    amount_map[k] += area;
            }  
        }
    }
    
    for(auto& pair : amount_map){
        if(pair.second > answer)
            answer = pair.second;
    }
    
    return answer;
}