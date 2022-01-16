
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class duels {
    static long ret;
    static long[] gains;
    static ArrayList<int[]>[] adj;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        ret = 0;
        int N = Integer.parseInt(br.readLine());
        adj = new ArrayList[N];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        gains = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i= 0; i<N; i++) gains[i] = Integer.parseInt(st.nextToken());
        
        for(int i = 0; i<N-1; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1; int v = Integer.parseInt(st.nextToken())-1; int w = Integer.parseInt(st.nextToken());
            adj[u].add(new int[]{v, w});
            adj[v].add(new int[]{u, w});
        }
        
        dfs(0, -1);
        pw.println(ret);
        pw.close();
    }
    
    static long dfs(int u, int p){
        long best = 0;
        long secbest = 0;
        for(int[] n : adj[u]){
            if(n[0] == p) continue;
            long cur = dfs(n[0], u) - n[1];
            if(cur > best){
                secbest = best;
                best = cur;
            }else if(cur > secbest){
                secbest = cur;
            }
        }
        best += gains[u];
        ret = Math.max(ret, best + secbest);
        return best;
    }
}
