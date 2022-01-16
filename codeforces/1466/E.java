
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class randoms {

    static int mod = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        long[] pows = new long[500];
        pows[0] = 1;
        for(int i = 1; i<pows.length; i++){
            pows[i] = pows[i-1]*2;
            pows[i] %= mod;
        }
        
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            long[] nums = new long[N];
            int[] bits = new int[61];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                nums[j] = Long.parseLong(st.nextToken());
                long t = nums[j];
                for (int k = 0; t > 0; k++, t >>= 1) {
                    bits[k] += (t & 1);
                }
            }
            long ret = 0;
            for (long j : nums) {
                long and = 0;
                long or = 0;
                for (int k = 0; k < bits.length; k++) {
//                    System.out.println(k + " " + bits[k]);
                    if ((j & ((long)1 << k)) != 0) {
                        and += bits[k]*pows[k];
                        or += N*pows[k];
//                        if(i == 5) System.out.println((long)1 << k);
                    } else {
                        or += bits[k]*pows[k];
                    }
           
                    and %= mod;
                    or %= mod;
                }
//                System.out.println(i + " " + and + " " + or + " " +Arrays.toString(bits));
                ret += (and*or)%mod;
                ret %= mod;
            }
            pw.println(ret);

        }

        pw.close();
        br.close();
    }
}
