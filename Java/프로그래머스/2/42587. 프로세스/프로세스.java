import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        Queue<Process> queue = new LinkedList<>();
        for (int i = 0; i < priorities.length; i++) {
            queue.add(new Process(i, priorities[i]));
        }
        
        int order = 0;
        
        while (!queue.isEmpty()) {
            Process current = queue.poll();
            
            if (hasHigherPriority(queue, current.priority)) {
                queue.add(current);
            } else {
                order++; // 실행 횟수 증가
                // 원하는 프로세스면 종료
                if (current.index == location) {
                    return order;
                }
            }
        }
        
        return order;
    }
    
    private boolean hasHigherPriority(Queue<Process> queue, int currentPriority) {
        for (Process p : queue) {
            if (p.priority > currentPriority) {
                return true;
            }
        }
        return false;
    }
}

// 인덱스와 우선순위를 함께 저장할 클래스
class Process {
    int index;// 원래 위치
    int priority; // 우선순위
    
    Process(int index, int priority) {
        this.index = index;
        this.priority = priority;
    }
}
