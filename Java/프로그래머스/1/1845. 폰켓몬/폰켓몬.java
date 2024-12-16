import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        
        Set<Integer> types = new HashSet<>();
        for (int num : nums) {
            types.add(num);
        }
        
        int selected = nums.length / 2;
        
        answer = Math.min(types.size(), selected);
        return answer;
    }
}