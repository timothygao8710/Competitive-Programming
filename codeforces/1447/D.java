
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        //define dp(i, j) as number of all-substrings ending at i and j
        long[][] dp = new long[N][M];
        String a = br.readLine();
        String b = br.readLine();
        long best = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {

                if (a.charAt(i) == b.charAt(j)) {
                    dp[i][j] = 2;
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                } else {
                    if (i - 1 >= 0) {
                        dp[i][j] = dp[i - 1][j];
                    }
                    if (j - 1 >= 0) {
                        dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
                    }
                    dp[i][j]--;
                }
                dp[i][j] = Math.max(dp[i][j], 0);
                best = Math.max(best, dp[i][j]);
            }
        }

        pw.println(best);
        pw.close();
        br.close();
    }
}
