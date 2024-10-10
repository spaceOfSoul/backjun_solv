import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] heights = new int[N];
        Stack<int[]> stack = new Stack<>(); 

        long count = 0; 

        for (int i = 0; i < N; i++) {
            heights[i] = Integer.parseInt(br.readLine());
        }

        for(int i : heights){

            int sameCount = 1;
            // 스택 꼭대기에 있는 키가 현재의 키보다 작을 경우
            while(!stack.isEmpty() && stack.peek()[0] < i){
                count += stack.pop()[1]; // 본인 앞에 스택에 들어와있던 애들은 모두 보임.
                // 그거 빼고 다음거도 보일지 넘어감.
                // 다음거도 본인보다 작아서 보이면 pop될거고, 아니면 다음절차로 넘어감.
            }

            if(!stack.isEmpty() && stack.peek()[0] == i){ // 키가 같으면
                int[] top = stack.pop();
                sameCount = top[1]+1; // 같은 키인 사람이 스택 꼭대기 있는 같은 키 (즉, 이전까지 같은 키 묶음 사람들) + 본인1
                count += top[1]; // 마찬가지로 스택 꼭대기에 있던 애들은 다 보이는 애들이니까 더해줌.
            }
            
            // 스택이 비지 않았다면 앞에 사람이 있긴 하다는거
            // 무조건 본인 앞에 한명은 볼 수 있으므로 count 증가
            if(!stack.isEmpty())
                count++;

            stack.push(new int[]{i, sameCount}); // 스택에는 현재 키와, 본인과 같은 사람의 수를 모두 push 함.
        }

        System.out.print(count);
    }
}
