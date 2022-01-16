
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

// package dp;
public class roundset {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] nums = new int[N][2];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            long c = Long.parseLong(st.nextToken());
            while (c % 2 == 0) {
                nums[i][0]++;
                c /= 2;
            }
            while (c % 5 == 0) {
                nums[i][1]++;
                c /= 5;
            }
        }
        int ret = 0;
        int[][] dp = new int[K + 1][30 * K]; //log(10^18)/log(5)
        for (int[] b : dp) {
            Arrays.fill(b, -6969420);
        }
        dp[K][0] = 0;
        for (int i = N - 1; i >= 0; i--) {
            int f = nums[i][1];
            int t = nums[i][0];
            for (int j = 0; j < K; j++) {
                for (int k = dp[j].length - 1; k >= 0; k--) {
                    if (k - f >= 0) {
                        dp[j][k] = Math.max(dp[j][k], dp[j + 1][k - f] + t);
                    }
                    ret = Math.max(ret, Math.min(k, dp[j][k]));
                }
            }
        }
        

        pw.println(ret);
        pw.close();
        br.close();
    }
}
