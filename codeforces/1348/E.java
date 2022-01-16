
import java.io.*;
import java.util.*;

public class randoms {
//just spam uniquely determines LOL. can basically say its 1-D
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] nums = new int[n][2];
        for(int i=  0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            nums[i][0] = Integer.parseInt(st.nextToken());
            nums[i][1] = Integer.parseInt(st.nextToken());
        }
        long sum = 0;
        boolean[][] dp = new boolean[n+1][k];
        //a rem uniquely determines brem by overcounting
        //extras accounted for by combinatorics
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            sum += nums[i-1][0] + nums[i-1][1];
            for(int j = 0; j<k; j++){
                //might be tempted to use int here, but uniquely determined from rem
                int rem = nums[i-1][0]%k;
                dp[i][j] = dp[i-1][(j - rem + k)%k];
                for(int back = 0; back <= Math.min(k-1, nums[i-1][0]); back++){
                    if(nums[i-1][1] + (nums[i-1][0] - back)%k >= k){
                        dp[i][j] = dp[i][j] || dp[i-1][(j - back + k)%k];
                    }
                }
            }
        }
//        System.out.println(Arrays.toString(dp[n]));
        long ret = 0;
        for(int i = 0; i<k; i++){
            if(dp[n][i]){
                ret = (sum - i)/k;
                break;
            }
        }
        pw.println(ret);
        pw.close();
        br.close();
    }
}
