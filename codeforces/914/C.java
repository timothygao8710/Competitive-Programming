
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.TreeSet;

public class duels {

    static int mod = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        char[] nums = br.readLine().toCharArray();
        int K = Integer.parseInt(br.readLine());
        int[] costs = new int[1001];
        costs[1] = 1;
        for (int i = 2; i < costs.length; i++) {
            int tot = 0;
            for (int j = 0; j < 31; j++) {
                if ((1 & (i >> j)) != 0) {
                    tot++;
                }
            }
            costs[i] = costs[tot]+1;
        }

        long[][][] dp = new long[nums.length + 1][1001][2];
        //0: less
        dp[0][0][1] = 1;
        for (int i = 1; i <= nums.length; i++) {
            int c = nums[i - 1] - '0';
            for (int j = 0; j <= 1000; j++) {
                dp[i][j][0] = dp[i - 1][j][0];
                if (j - 1 >= 0) {
                    dp[i][j][0] += dp[i - 1][j - 1][0];
                }
                if (c == 1) {
                    dp[i][j][0] += dp[i - 1][j][1];
                    if (j - 1 >= 0) {
                        dp[i][j][1] += dp[i - 1][j - 1][1];
                    }
                } else {
                    dp[i][j][1] += dp[i - 1][j][1];
                }
                dp[i][j][0] %= mod;
                dp[i][j][1] %= mod;
            }
        }
        
            dp[nums.length][1][0]--;
        
        long ret = 0;
        for (int i = 1; i <= 1000; i++) {

            if (costs[i] == K) {
//                System.out.println(i);
                for (int k = 0; k < 2; k++) {
                    ret += dp[nums.length][i][k];
//                    if(i == 2) System.out.println(dp[nums.length][i][k]);
                    ret %= mod;
                }
            }

        }
        pw.println(K == 0 ? 1 : ret);
        pw.close();
        br.close();
    }
}
