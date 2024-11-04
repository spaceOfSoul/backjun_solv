import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        
        Arrays.sort(jobs, (a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        int currentTime = 0;
        int totalWaitTime = 0;
        boolean[] completed = new boolean[jobs.length];

        for (int i = 0; i < jobs.length; i++) {
            int minIndex = -1;
            int minProcessTime = Integer.MAX_VALUE;

            for (int j = 0; j < jobs.length; j++) {
                if (!completed[j] && jobs[j][0] <= currentTime && jobs[j][1] < minProcessTime) {
                    minProcessTime = jobs[j][1];
                    minIndex = j;
                }
            }

            if (minIndex == -1) {
                currentTime = jobs[i][0];
                i--;
            } else {
                currentTime += jobs[minIndex][1];
                totalWaitTime += (currentTime - jobs[minIndex][0]);
                completed[minIndex] = true;
            }
        }
        
        answer = totalWaitTime / jobs.length;
        
        return answer;
    }
}