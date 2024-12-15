import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    List<String>[] list = new ArrayList[201];

    for (int i = 1; i <= 200; i++) {
      list[i] = new ArrayList<>();
    }

    for (int i = 0; i < n; i++) {
      String[] input = br.readLine().split(" ");
      int age = Integer.parseInt(input[0]);
      String name = input[1];
      list[age].add(name);
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 1; i <= 200; i++) {
      for (String name : list[i]) {
        sb.append(i).append(" ").append(name).append("\n");
      }
    }

    System.out.print(sb.toString());
  }
}
