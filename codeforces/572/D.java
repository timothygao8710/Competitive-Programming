
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); int K = Integer.parseInt(st.nextToken());
        int[] nums = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i =0; i<N; i++) nums[i] = Integer.parseInt(st.nextToken());
        
        Arrays.sort(nums);
        int len = N/K;
        int leftover = N%K;
        long[][] dp = new long[K+1][leftover+1];
        for(long[] i : dp) Arrays.fill(i, (long)(1e15));
        dp[0][0] = 0;
        for(int i = 1; i<=K; i++){
            int idx = i*len-1;
            for(int j = 0; j<=leftover; j++){
                dp[i][j] = dp[i-1][j] + nums[idx+j] - nums[idx+j-len+1];
                if(j != 0){
//                    System.out.println(idx);
                    dp[i][j] = Math.min(dp[i][j],
                            dp[i-1][j-1] + nums[idx+j] - nums[idx+j-len]
                            );
                }
            }
        }
        pw.println(dp[K][leftover]);
        pw.close();
        br.close();
    }
}
