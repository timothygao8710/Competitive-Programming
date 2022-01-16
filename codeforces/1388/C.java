
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        int T = Integer.parseInt(br.readLine());
        //hap + sad = sz[i]
        //hap - sad = hap[i]
        //2hap = sz[i] + hap[i]
        l:
        for(int t = 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[] sz = new int[N];
            int[] hap = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                sz[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                hap[i] = Integer.parseInt(st.nextToken());
            }
            
            ArrayList<Integer>[] adj = new ArrayList[N];
            for (int i = 0; i < adj.length; i++) {
                adj[i] = new ArrayList<>();
            }
            for(int i = 0; i<N-1; i++){
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken())-1; int v = Integer.parseInt(st.nextToken())-1;
                adj[u].add(v); adj[v].add(u);
            }
            dfs1(adj, 0, -1, sz);
            for(int i = 0; i<N; i++){
                if(Math.abs(hap[i]) > sz[i]){
                    pw.println("NO"); continue l;
                }
                hap[i] += sz[i];
                if(hap[i]%2 != 0){
                    pw.println("NO"); continue l;
                }
                hap[i] /= 2;
            }

            if(dfs(adj, 0, -1, hap)){
                pw.println("YES");
            }else{
                pw.println("NO");
            }
        }
        
        pw.close();
        br.close();
    }
    
    static boolean dfs(ArrayList<Integer>[] adj, int c, int p, int[] hap){
        for(int n : adj[c]){
            if(n == p) continue;
            hap[c] -= hap[n];
            if(!dfs(adj, n, c, hap)) return false;
        }
        return hap[c] >= 0;
    }
    
    static void dfs1(ArrayList<Integer>[] adj, int c, int par, int[] sz){
        for(int n : adj[c]){
            if(n != par){
                dfs1(adj, n, c, sz);
                sz[c] += sz[n];
            }
        }
    }
}
