// import java.util.*;

// class Solution {
//     boolean solution(String s) {
//         Stack<Character> stack = new Stack<>();

//         for (int i = 0; i < s.length(); i++) {
//             char c = s.charAt(i);

//             // '('라면 스택에 push
//             if (c == '(') {
//                 stack.push(c);
//             } 
//             else {
//                 if (stack.isEmpty()) {
//                     return false;
//                 }
//                 stack.pop();
//             }
//         }

//         return stack.isEmpty();
//     }
// }

// 테스트 1 〉	통과 (17.08ms, 54.6MB)
// 테스트 2 〉	통과 (19.70ms, 72.4MB)


class Solution {
    public boolean solution(String s) {
        return checkParentheses(s, 0, 0);
    }
    
    private boolean checkParentheses(String s, int index, int openCount) {
        // 문자열 끝까지 검사했을 때,
        // openCount가 0이면 맞는거임
        if (index == s.length()) {
            return openCount == 0;
        }

        char c = s.charAt(index);

        if (c == '(') {
            return checkParentheses(s, index + 1, openCount + 1);
        }
        else {
            // 아직 열린 괄호가 없는데 닫아버리면 안됨.
            if (openCount <= 0) {
                return false;
            }
            return checkParentheses(s, index + 1, openCount - 1);
        }
    }
}
