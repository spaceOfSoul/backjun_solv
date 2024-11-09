import java.io.*;

public class Main{
    public static int N;

    public static Boolean imyunsoo(){
        if(N < 4 || N == 5)
            return false;
        
        String tmp = Integer.toString(N);
        int len = tmp.length();
        int sum = 0;

        for(int i = 0; i<len; i++){
            sum += tmp.charAt(i) -'0';
        }

        return sum%2 != 0;
    }

    public static Boolean checkCompositeAndPrimeFactor(int n){
        if(n==1)
            return false;

        Boolean isPrime = true;

        int i=2;
        int beforeFactor = 0;
        int primeFactorCount = 0;

        // System.out.println("primes");
        while(i<=Math.sqrt(n)){
            if(n%i==0){
                // System.out.println(i);
                n /= i;
                isPrime = false;
                // System.out.println(i);
                if(beforeFactor != i){
                    beforeFactor = i;
                    primeFactorCount++;
                }
            }else{
                i++;
            }
        }

        if (n > 1) {
            if(beforeFactor != n)
                primeFactorCount++;
        }

        // System.out.println("Count of Prime Categorys");
        // System.out.println(primeFactorCount);
        
        return !isPrime && primeFactorCount % 2 == 0;
    }

    public static Boolean imhyunsoo(){
        if(N == 2 || N == 4)
            return true;

        return checkCompositeAndPrimeFactor(N);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        Boolean isImyunsoo = imyunsoo();
        Boolean isImhyunsoo = imhyunsoo();

        if(isImyunsoo && !isImhyunsoo){
            System.out.print(1);
        }else if(!isImyunsoo && isImhyunsoo){
            System.out.print(2);
        }else if(!isImyunsoo && !isImhyunsoo){
            System.out.print(3);
        }else{
            System.out.print(4);
        }
    }
}