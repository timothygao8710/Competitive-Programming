
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class randoms {

    /*
    Directed component is valid if(and only if) for an arbitrary vertex u, all nodes can reach u and u can reach all nodes
    */
    
    static ArrayList<Integer>[] adj;
    static boolean can;
    static List<int[]> ret;
    public static void main(String[] args) throws IOException {
        can = true;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); int M = Integer.parseInt(st.nextToken());
        adj = new ArrayList[N];
        ret = new ArrayList<>();
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for(int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1; int v = Integer.parseInt(st.nextToken())-1;
            adj[u].add(v); adj[v].add(u);
        }
        
        build(new int[adj.length], new int[adj.length], 0, -1);
        
        if(can){
            for(int[] i : ret) {
                pw.println((1+i[0]) + " " + (1+i[1]));
            }
        }else{
            pw.println(0);
        }
        pw.close();
        br.close();
    }
    
    static void build(int[] dp, int[] vis, int cur, int par){
        vis[cur] = 1;
        for(int n : adj[cur]){
            if(n == par || vis[n] == 2) continue;
            ret.add(new int[]{cur, n});
            if(vis[n] == 1){
                dp[cur]++;
                dp[n]--;
            }else{
                build(dp, vis, n, cur);
                dp[cur] += dp[n]; 
            }
        }
        vis[cur] = 2;
        if(dp[cur] == 0 && cur != 0) can = false; //cur != 0 because each edge is identified by children. change this is 1 is root.
    }
}
