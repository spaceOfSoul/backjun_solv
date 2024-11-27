import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<Integer> result = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        int a;
        
        String[] inputs = br.readLine().split(" ");

        for(int i=0; i<n; i++){
            a = Integer.parseInt(inputs[i]);

            if(result.isEmpty() || result.get(result.size()-1) < a){
                result.add(a);
            }else{
                int ptr = lowerBound(result, a);
                result.set(ptr, a);
            }
        }

        System.out.print(result.size());
    }

    public static int lowerBound(ArrayList<Integer> list, int key){
        int left = 0, right = list.size();
        while (left < right) { 
            int mid = left + (right - left) / 2;

            if(list.get(mid) < key){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return left;
    }
}