
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B1142 {
    static boolean[] vis;
    static ArrayList<Integer>[] adj;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());
        
        int[] locs = new int[n+1];
        int[] last = new int[n+1];
        int[] ret = new int[m];
        adj = new ArrayList[m];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++){
            int c = Integer.parseInt(st.nextToken());
            locs[c] = i;
            last[i] = -1;
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<m; i++){
            int u = Integer.parseInt(st.nextToken());
            if(u < 0 || u > n){
                ret[i] = -1;
                continue;
            }
            last[locs[u]] = i;
            int bac = last[(locs[u]-1 + n)%n];
            if(bac != -1){
                adj[bac].add(i);
            }
        }
        vis = new boolean[m];
        for(int i = 0; i<m; i++){
            if(!vis[i]){
                dfs(i, new ArrayList(), ret, n);
            }
        }
//        System.out.println(Arrays.toString(ret));
        int[][] qs = new int[q][3];
        for(int i = 0; i<q; i++){
            st = new StringTokenizer(br.readLine());
            qs[i] = new int[]{
                Integer.parseInt(st.nextToken())-1,
                Integer.parseInt(st.nextToken())-1,
                i
            };
        }
        
        Arrays.sort(qs, (int[] a, int[] b) -> a[1] - b[1]);
        boolean[] ans = new boolean[q];
        int max = -1;
        int p = 0;
        for(int i = 0; i<q; i++){
            while(p <= qs[i][1]){
                max = Math.max(max, ret[p]);
                p++;
            }
            ans[qs[i][2]] = qs[i][0] <= max;
        }
        
        for(boolean i : ans){
            pw.print(i ? 1 : 0);
        }
        pw.close();
        br.close();
    }
    
    static void dfs(int u, ArrayList<Integer> pref, int[] ret, int size){
        pref.add(u);
//        System.out.println(u + " " + pref.size());
        if(pref.size() >= size){
            ret[u] = pref.get(pref.size() - size);
        }else{
            ret[u] = -1;
        }
        for(int n : adj[u]){
            if(n != u) dfs(n, pref, ret, size);
        }
        vis[u] = true;
        pref.remove(pref.size()-1);
    }
}
