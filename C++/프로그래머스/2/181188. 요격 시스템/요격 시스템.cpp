#include <string>
#include <vector>
#include <algorithm>
// #include <iostream>

using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), compare);
    
    int end_point = 0;
    
    // 끝점을 요격지점으로 잡음
    // 요격지점이 있을 시, 현재 범위와 겹치는지 확임
    // 겹치면 넘겨
    // 아니면 안겹치면 지금 친구 끝점이 요격지점임.
    // 어차피 끝점 기준으로 정렬했으니, 잡아놓으면 그게 다른거랑 겹칠 수 있음.
    // 이 뒤에 끝점은 같거나 더 뒤에니까.
    
    for(vector<int> i : targets){
        // cout << i[0] << " " << i[1] << "\n";
        if(!end_point){
            end_point = i[1];
            // cout << i[0] << " " << i[1] << "에서 end 설정" << "\n";
            // cout << end_point << "\n";
            answer++;
            continue;
        }
        if(end_point){
            if(i[0] < end_point && end_point <= i[1])
                continue;
            // cout << i[0] << " " << i[1] << "에서 end 설정" << "\n";
            end_point = i[1];
            answer++;
        }
    }
    
    
    return answer;
}