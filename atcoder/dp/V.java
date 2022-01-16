import java.io.*;
import java.util.*;

public class Main {
    static long[][] suffix; 
    static long[] dp;
    static ArrayList<Integer>[] adj;
    static int mod;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        mod = Integer.parseInt(st.nextToken());
        
        suffix = new long[N][];
        
        adj = new ArrayList[N];
        for(int i = 0; i<N; i++) adj[i] = new ArrayList();
        for(int i = 0; i<N-1; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            adj[u].add(v);
            adj[v].add(u);
        }
        dp = new long[N];
        dfs(0,-1);
        dfs1(0,-1,0);
        
        for(long i : dp){
            System.out.println(i);
        }
    }
    
    static long dfs(int curr, int last){        
        suffix[curr] = new long[adj[curr].size()+1];
        long right = 1;
        suffix[curr][adj[curr].size()] = 1; //idx out of bounds
        
        for(int i = adj[curr].size()-1; i>=0; i--){
            int n = adj[curr].get(i);
            if(n == last){
                suffix[curr][i] = suffix[curr][i+1];
                continue;
            }
            right *= (dfs(n, curr)+1);
            right %= mod;
            suffix[curr][i] = right;
        }
        dp[curr] = right;
        return dp[curr];
    }
    
    static void dfs1(int curr, int last, long above){
        long left = above+1;
        dp[curr] *= left;
        dp[curr] %= mod;
        
        for(int i = 0; i<adj[curr].size(); i++){
            int n = adj[curr].get(i);
            if(n == last) continue;
            
            long temp = dp[n]+1;
            
            dfs1(n, curr, (left*suffix[curr][i+1])%mod);
                        
            left *= temp;
            left %= mod;
        }
    }
}
