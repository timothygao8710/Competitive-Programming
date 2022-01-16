import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static Long[][] dp;
    static int mod = (int)(1e9+7);
    static ArrayList<Integer>[] adj;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        adj = new ArrayList[N];
        for(int i = 0; i<N; i++) adj[i] = new ArrayList();
        for(int i = 0; i<N-1; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());    
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            adj[u].add(v);
            adj[v].add(u);
        }
        dp = new Long[N][2];
        System.out.println(memo(0, 0, -1)%mod);
    }
    //0: can
    //1: cannot
    static long memo(int node, int mark,  int last){
        if(dp[node][mark] != null) return dp[node][mark];
        dp[node][0] = dp[node][1] = 1L;
        long black = 1;
        for(int n : adj[node]){
            if(n == last) continue;
            black *= memo(n, 1, node);
            black %= mod;
            dp[node][1] *= memo(n, 0, node);
            dp[node][1] %= mod;
        }
        dp[node][0] = (black + dp[node][1])%mod;
        return dp[node][mark];
    }
}
