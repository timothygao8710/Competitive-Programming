
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class duels {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); int M = Integer.parseInt(st.nextToken()); int K = Integer.parseInt(st.nextToken());
        int[] dp = new int[K+1];
        int can = 0;
        for(int i = 0; i<N; i++){
            int[] dp1 = new int[K+1];
            List<Integer> diffs = new ArrayList<>();
            int len = 0;
            char[] d = br.readLine().toCharArray();
            int run = 0;
            for(int j = 0; j<M; j++){
                if(d[j]=='1'){
                    if(run != 0) {
                        diffs.add(run); len += run;
                    }
                    run = 1;
                }else{
                    if(run != 0) run++;
                }
            }
            if(run == 0) continue;
            int n = diffs.size(); len++;
            int[] sub = new int[n+2];
            //can be changed to sliding window -> harmonic series mlog(m)
            int lsum = 0;
            for(int j =0; j<n; j++){
                int sum = lsum;
                sub[j] = Math.max(sub[j], sum);
                for(int k = n-1; k>=j; k--){
                    sum += diffs.get(k);
                    sub[n-k+j] = Math.max(sub[n-k+j], sum);
                }
                lsum += diffs.get(j);
            }
//            System.out.println("s" + Arrays.toString(sub));
                
            sub[n+1] = sub[n]+1;
            for(int j = 0; j<=K; j++){
                dp1[j] = dp[j];
                for(int k = 1; k<=n+1; k++){
                    if(k+j < dp.length) dp1[j] = Math.min(dp1[j], dp[j+k] - sub[k]);
                }
                dp1[j] += len;
            }
            dp = dp1;
//            System.out.println(Arrays.toString(dp));
        }
        int ret = dp[0];
        for(int i : dp) ret = Math.min(ret, i);
        pw.println(ret);
        pw.close();
        br.close();
    }
}
/*

*/