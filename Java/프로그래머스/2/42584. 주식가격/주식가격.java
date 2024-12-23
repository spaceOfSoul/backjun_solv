import java.util.*;


// 가격이 내려가기 전까지는 스택에 인덱스 push.
// 새로운 가격이나을 확인할 때 이전 가격보다 하락한 순간, 스택에서 해당 인덱스를 꺼내가며 시간을 계산
class Solution {
    public int[] solution(int[] prices) {
        int n = prices.length;
        int[] answer = new int[n];
        
        Stack<Integer> stack = new Stack<>();
        
        // prices 배열 순회
        for (int i = 0; i < n; i++) {
            // 현재 가격이 스택의 top에 해당하는 가격보다 낮으면
            // 가격이 하락한 것
            while (!stack.isEmpty() && prices[stack.peek()] > prices[i]) {
                int topIndex = stack.pop();
                answer[topIndex] = i - topIndex; 
            }
            // 현재 인덱스
            stack.push(i);
        }
        
        while (!stack.isEmpty()) {
            int topIndex = stack.pop();
            answer[topIndex] = n - 1 - topIndex;
        }
        
        return answer;
    }
}
