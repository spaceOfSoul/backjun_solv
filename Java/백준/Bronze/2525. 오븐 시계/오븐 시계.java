import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int h = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        int minuteTime = h*60 + m;

        minuteTime += Integer.parseInt(br.readLine());
        minuteTime %= 1440;

        System.out.printf("%d %d", minuteTime/60, minuteTime%60);
    }
}
