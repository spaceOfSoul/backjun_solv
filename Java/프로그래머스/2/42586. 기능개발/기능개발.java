import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int n = progresses.length;
        
        int[] daysToFinish = new int[n];
        
        for (int i = 0; i < n; i++) {
            int remain = 100 - progresses[i];// 남은 작업량
            int day = remain / speeds[i];// 필요한 최소 일수(몫)
            
            // 나머지가 있으면 하루 더 필요
            if (remain % speeds[i] != 0) {
                day++;
            }
            
            daysToFinish[i] = day;
        }
        
        List<Integer> result = new ArrayList<>();
        
        int standard = daysToFinish[0];
        int count = 1; // 현재 배포에 포함될 기능 개수
        
        for (int i = 1; i < n; i++) {
            if (daysToFinish[i] <= standard) {
                count++;
            } 
            else {// 기준일보다 더 걸린다면 새 배포일
                result.add(count);
                count = 1;
                standard = daysToFinish[i];
            }
        }
        
        result.add(count);
        
        int[] answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}
