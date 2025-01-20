class Solution {
    public static int solution(String name) {
        int length = name.length();
        
        // 각 문자를 넘기는(위,아래) 횟수
        int upDownMoves = 0;
        for (int i = 0; i < length; i++) {
            char c = name.charAt(i);
            // 'A'에서 c로
            int diff = c - 'A';
            int reverseDiff = 26 - diff; // 아래로 움직였을 경우
            upDownMoves += Math.min(diff, reverseDiff);
        }
        

        // 단순히 오른쪽으로만 이동한다고 가정하면 length - 1이 디폴트
        int leftRightMoves = length - 1;

        // A 스킵 가능성 보기
        for (int i = 0; i < length; i++) {
            int nextIndex = i + 1;
            
            // i 다음부터 연속된 'A'를 모두 건너뛴 위치 nextIndex 찾기
            while (nextIndex < length && name.charAt(nextIndex) == 'A') {
                nextIndex++;
            }
            
            // 오른쪽으로 i번 이동 후 다시 왼쪽으로 돌아가는 경우
            int moveCase1 = 2 * i + (length - nextIndex);
            
            // 왼쪽이 더 빠름
            int moveCase2 = (length - nextIndex) * 2 + i;
            
            // 젤 작은거
            leftRightMoves = Math.min(leftRightMoves, Math.min(moveCase1, moveCase2));
        }
        
        return upDownMoves + leftRightMoves;
    }
}