import java.io.*;
import java.util.*;

public class Main{
    public static Map<Integer, int[]> numberMap;
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        numberMap = new HashMap<>();

        numberMap.put(0, new int[]{10});
        numberMap.put(1, new int[]{1});
        numberMap.put(2, new int[]{2,4,8,6});
        numberMap.put(3, new int[]{3,9,7,1});
        numberMap.put(4, new int[]{4,6});
        numberMap.put(5, new int[]{5});
        numberMap.put(6, new int[]{6});
        numberMap.put(7, new int[]{7,9,3,1});
        numberMap.put(8, new int[]{8,4,2,6});
        numberMap.put(9, new int[]{9,1});

        int T = Integer.parseInt(br.readLine());

        String[] input;
        while (T-->0) { 
            input = br.readLine().split(" ");

            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            a %= 10;

            int[] pattern = numberMap.get(a);

            System.out.println(pattern[(b-1) % pattern.length]);
        }
    }
}