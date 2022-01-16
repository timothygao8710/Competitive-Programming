
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int mod = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[][] dp = new int[N+1][N+1];
        dp[0][0] = 1;
        for(int i = 1; i<=N; i++){
            for(int j = N; j>=1; j--){
                dp[i][j] = dp[i-1][j-1];
                if(2*j <= N) dp[i][j] += dp[i][j+j];
                dp[i][j] %= mod;
            }
        }
        pw.println(dp[N][K]);
        pw.close();
        br.close();
    }
}
