
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class minremovetobipartite {

    static int[] vis;
    static int[][] dp; //0 - all. 1 - bad
    static List<Integer> ret;
    static int[] mark;
    static int totbad;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        ArrayList<int[]>[] adj = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            adj[i] = new ArrayList();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            adj[u].add(new int[]{v, i});
            adj[v].add(new int[]{u, i});
        }
        vis = new int[N];
        ret = new ArrayList();
        dp = new int[N][2];
        mark = new int[N];
        int key = -1;
        for(int i = 0; i<N; i++){
            if(vis[i] == 0){
                if(!bipart(adj, i, -1)){
                    if(key != -1){
                        key = -2;
                    }else{
                        key = i;
                    }
                }
            }
        }
        vis = new int[N];
        for (int i = 0; i < N; i++) {
            if (vis[i] == 0 && (key == -1 || key == i)) {
                totbad = 0;
                dfs(adj, i, -1);
                dfs1(adj, i, -1);
            }
        }
//        System.out.println(Arrays.deepToString(dp));
        Collections.sort(ret);
        pw.println(ret.size());
        for (int i : ret) {
            pw.print((i+1) + " ");
        }
        pw.close();
        br.close();
    }

    static boolean bipart(ArrayList<int[]>[] adj, int cur, int p){
        vis[cur] = 1;
        boolean r = true;
        for(int[] n : adj[cur]){
            if(vis[n[0]] == 2 || n[0] == p) continue;
            if(vis[n[0]] == 1){
                if(mark[cur] == mark[n[0]]) r = false;
            }else{
                mark[n[0]] = mark[cur] ^ 1;
                if(!bipart(adj, n[0], cur)){
                    r = false;
                }
            }
        }
        vis[cur] = 2;
        return r;
    }
    
    static void dfs1(ArrayList<int[]>[] adj, int cur, int par) {
        vis[cur] = 0;
        for (int[] n : adj[cur]) {
            if (n[0] == par || vis[n[0]] == 1) {
                continue;
            }
            if (vis[n[0]] == 0) { //is anc
                if (totbad == 0 || (totbad == 1 && mark[n[0]] == mark[cur])) {
                    ret.add(n[1]);
                }
            } else {
                if(totbad == 0 || (dp[n[0]][0] == totbad && totbad == dp[n[0]][1])){
                    ret.add(n[1]);
                }
                dfs1(adj, n[0], cur);
            }
        }
        vis[cur] = 1;
    }

    static void dfs(ArrayList<int[]>[] adj, int cur, int par) {
        vis[cur] = 1;
        for (int[] n : adj[cur]) {
            if (n[0] == par || vis[n[0]] == 2) {
                continue;
            }
            if (vis[n[0]] == 1) {
                if (mark[cur] == mark[n[0]]) {
                    totbad++;
                    dp[cur][1]++;
                    dp[n[0]][1]--;
                }
                dp[cur][0]++;
                dp[n[0]][0]--;
            } else {
                mark[n[0]] = mark[cur] ^ 1;
                dfs(adj, n[0], cur);
                for (int i = 0; i < 2; i++) {
                    dp[cur][i] += dp[n[0]][i];
                }
            }
        }
        vis[cur] = 2;
    }
}
