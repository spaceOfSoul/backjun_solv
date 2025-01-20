import java.util.*;

class Solution {
        public static String solution(String number, int k) {
        StringBuilder answer = new StringBuilder();

        for (int i = 0; i < number.length(); i++) {
            char current = number.charAt(i);

            // 제거 횟수가 남아있고 스택 맨 위보다 현재 문자가 크면 계속 pop
            while (k > 0 && answer.length() > 0 
                   && answer.charAt(answer.length() - 1) < current) {
                answer.deleteCharAt(answer.length() - 1);
                k--;
            }
            answer.append(current);
        }

        // 아직 k가 남아있다면 뒤에서부터 k개 제거
        // 최종 길이는 길이 - k만큼
        return answer.substring(0, answer.length() - k);
    }
}