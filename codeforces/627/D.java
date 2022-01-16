
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * - Long/int
 * - Draw stuff
 * - Use comments
 * - Drink Water
 * - Reread Problem
 *
 * - package/pw.close
 *
 * @author timothy
 */
public class preorder {
    static int[] vals;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        vals = new int[N];
        ArrayList<Integer>[] adj = new ArrayList[N];
        for(int i =0; i<N; i++) adj[i] = new ArrayList<>();
        
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<N; i++){
            vals[i] = Integer.parseInt(st.nextToken());
        }
        
        for(int i = 0; i<N-1; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            adj[u].add(v);
            adj[v].add(u);
        }
        
        int l = 1;
        int r = 1_000_000;
        while(l < r){
            int mid = (l+r+1)/2;
            if(good(adj, mid, K)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        System.out.println(l);
    }
    
    static int[][] dp;
    static int res;
    static boolean good(ArrayList<Integer>[] adj, int min, int K){
        dp = new int[adj.length][4]; //partial times : fulls : pbest : psecond best
        res = 0;
        dfs(adj, 0, -1, min);
        dfs1(adj, 0, -1, min);
        return res >= K;
    }
    //this is the messiest piece of code ive ever written lmfao
    static void dfs1(ArrayList<Integer>[] adj, int curr, int last, int min){
        if(last != -1 && vals[last] >= min && vals[curr] >= min){
            int up = dp[last][1] + dp[last][2];
            
            if(dp[last][0] == 0 && dp[curr][0] == 0){
                dp[curr][1] += dp[last][1]-dp[curr][1];
            }else if(dp[last][0] == 1 && dp[curr][0] > 0){
                dp[curr][1] += dp[last][1];
            }else if(dp[curr][0] == 0){
                dp[curr][0]++;
                dp[curr][2] = up-dp[curr][1];
            }else{
                dp[curr][0]++;
                if(dp[curr][1] + dp[curr][2] == dp[last][2]){
                    up -= dp[last][2]-dp[last][3];
                }
                
                if(up > dp[curr][2]){
                    dp[curr][3] = dp[curr][2];
                    dp[curr][2] = up;
                }else if(up > dp[curr][3]){
                    dp[curr][3] = up;
                }
            }
        }
        res = Math.max(res, dp[curr][1] + dp[curr][2]);
        for(int n : adj[curr]){
            if(n == last) continue;
            dfs1(adj, n, curr, min);
        }
    }
    
    static void dfs(ArrayList<Integer>[] adj, int curr, int last, int min){
        for(int n : adj[curr]){
            if(n==last) continue;
            dfs(adj, n, curr, min);
            if(dp[n][0] == 0){
                dp[curr][1] += dp[n][1];
            }else{
                int nVal = dp[n][1]+dp[n][2];
                dp[curr][0]++;
                
                if(nVal > dp[curr][2]){
                    dp[curr][3] = dp[curr][2];
                    dp[curr][2] = nVal;
                }else if(nVal > dp[curr][3]){
                    dp[curr][3] = nVal;
                }
            }
        }
        
        if(vals[curr] < min){
            Arrays.fill(dp[curr], -898980);
        }else{
            dp[curr][1]++;
        }
    }
}
