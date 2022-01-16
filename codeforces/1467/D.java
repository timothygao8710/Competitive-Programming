
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

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        
        int[] nums = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }
        
        long[][] dp = new long[K+1][N];
        Arrays.fill(dp[0],1);
        for(int i = 1; i<=K; i++){
            for(int j = 0; j<N; j++){
                if(j-1 >=0) dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= mod;
                if(j+1 <N) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= mod;
            }
        }
        
        long ret = 0;
        long[] each = new long[N];
        //number of times ecah elemtn shows up
        //takes advantage of the fact that each path is reversable
        //calculuates how many times each element appears at each step of the total path
        for(int i = 0; i<N; i++){
            for(int j = 0; j<=K; j++){
                each[i] += dp[j][i]*dp[K-j][i];
                each[i] %= mod;
            }
            ret += each[i]*nums[i];
            ret %= mod;
        }
        
        for(int i = 0; i<Q; i++){
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken())-1;
            int val = Integer.parseInt(st.nextToken());
            ret += ((val - nums[idx])*each[idx])%mod;
            nums[idx] = val;
            ret = (ret+mod)%mod;
            pw.println(ret);
        }
        
        pw.close();
        br.close();
    }
}
