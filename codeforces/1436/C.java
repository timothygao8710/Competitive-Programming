
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class virtual {

    static int mod = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        
//        long[] perm = new long[5000];
//        perm[0] = 1;
//        for(int i = 1; i<perm.length; i++){perm[i] = perm[i-1]*i; perm[i] %= mod;} never mind you need inv mod LOL
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken());
        int pos = Integer.parseInt(st.nextToken());
        
        int[] temp = new int[N];
        for(int i = 0; i<N; i++) temp[i] = i;
        int[] ret = bs(temp, pos);
//        System.out.println(Arrays.toString(ret));
        if(X -1 < ret[0] || N-X < ret[1]){
            pw.println(0);
        }else{
//            long smol = perm[ret[0]]/(perm[X-1-ret[0]]);
//            long large = perm[ret[1]]/perm[N-X-ret[1]];
            long smol = 1;
            for(int i = 0; i<ret[0]; i++){
                smol *= (X-1-i);
                smol %= mod;
            }
            long large = 1;
            for(int i = 0; i<ret[1]; i++){
                large *= (N-X-i);
                large %= mod;
            }
            
            long a = smol*large;
            a %= mod;
            for(int i = 1; i<=N - ret[0] - ret[1] -1; i++){
                a *= i;
                a %= mod;
            }
            pw.println(a);
        }
           
        pw.close();
        br.close();
    }
    
    static int[] bs(int[] a, int x){
        int[] ret = new int[2];
        int left = 0;
        int right = a.length;
        while(left < right){
            int mid = (left + right)/2;
            if(a[mid] <= x){
                left = mid+1;
                ret[0]++;
            }else{
                right = mid;
                ret[1]++;
            }
        }
        ret[0]--;
        return ret;
    }
}
