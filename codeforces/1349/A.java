
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// package divisibility;

public class ocralcm {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] nums = new int[N];
        long[] pre = new long[N];
        long[] suf = new long[N];
        
        for(int i=0; i<N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }
        pre[0] = nums[0];
        suf[N-1] = nums[N-1];
        for(int i = 1; i<N; i++){
            pre[i] = gcd(nums[i], pre[i-1]);
            suf[N-1-i] = gcd(nums[N-1-i], suf[N-i]);
        }
        long ret = lcm(nums[0], suf[1]);
        ret = gcd(ret, lcm(nums[N-1], pre[N-2]));
        for(int i = 1; i<N-1; i++){
            long l = pre[i-1];
            long r = suf[i+1];
            ret = gcd(ret, lcm(nums[i], gcd(l,r)));
        }
        System.out.println(ret);
    }
    
    static long lcm(long a, long b){
        return a/gcd(a,b) * b;
    }      
    
    //log(a) + log(b)
    static long gcd(long a, long b) {
        if (b == 0 || a == 0) {
            return a + b;
        }
        long min = Math.min(a, b);
        return gcd(min, Math.max(a, b) % min);
    }
}
