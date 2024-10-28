import java.util.*;


class Solution {
    public int solution(String[][] clothes) {
        // 종류별로 옷 개수를 세기
        Map<String, Integer> closet = new HashMap<>();
        for (String[] cloth : clothes) {
            closet.put(cloth[1], closet.getOrDefault(cloth[1], 0) + 1);
        }

        int answer = closet.values().stream()
                           .map(count -> count + 1) 
                           .reduce(1, (a, b) -> a * b); // 모든 경우의 수를 곱함

        return answer - 1; // 아무것도 선택하지 않는 경우 제거
    }
}