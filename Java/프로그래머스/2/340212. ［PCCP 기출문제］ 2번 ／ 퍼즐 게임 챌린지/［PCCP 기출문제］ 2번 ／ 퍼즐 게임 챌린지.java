import java.io.*;
import java.util.*;

class Solution {
    private long getSolvingTime(List<int[]> table, int level){
        long time = 0;
        
        long time_cur = 0;
        long time_prev = 0;
        int length = table.size();
        
        for (int i = 0; i < length; i++) {
            time_cur = table.get(i)[1];
            if (i != 0)
                time_prev = table.get(i - 1)[1];
            
            if (table.get(i)[0] <= level) {
                time += time_cur;
            } else {
                time += (table.get(i)[0] - level) * (time_cur + time_prev) + time_cur;
            }
        }
        
        return time;
    }
    
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        
        List<int[]> list = new ArrayList<>();
        
        for (int i = 0; i < diffs.length; i++) {
            list.add(new int[] {diffs[i], times[i]});
        }
        
        int start = 1;
        int end = 100000;
        long solvingTime = 0;
        
        // answer is mid
        while(start <= end){
            answer = (start+end)/2;
            
            solvingTime = getSolvingTime(list, answer);
            if(solvingTime <= limit){
                end = answer-1;
            }else{
                start = answer+1;
            }
        }
        
        if(solvingTime > limit)
            return answer+1;
        return answer;
    }
}