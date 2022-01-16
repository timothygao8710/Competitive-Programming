
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
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
public class treequeries {
    static int[] in;
    static int[] out;
    static int[] parents;
    static int idx;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        ArrayList<Integer>[] adj = new ArrayList[N];
        for(int i =0 ; i<N; i++) adj[i] = new ArrayList();
        
        in = new int[N];
        out = new int[N];
        parents = new int[N];
        idx = 0;
        
        for(int i = 0; i<N-1; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            adj[u].add(v);
            adj[v].add(u);
        }
        
        euler(adj, 0, 0);
        qs:
        for(int i = 0; i<K; i++){
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int[][] locs = new int[2*v][3];
            
            for(int j = 0; j<v; j++){
                int u = Integer.parseInt(st.nextToken())-1;
                u = parents[u]; //greedy
                locs[j] = new int[]{u, in[u], 0};
                locs[v+j] = new int[]{u, out[u], 1};
            }
            Arrays.sort(locs, (int[] a, int[] b) -> a[2] == b[2] ? a[1] - b[1] : a[2] - b[2]);

//            System.out.println(Arrays.deepToString(locs));
            for(int j = 0; j<v; j++){
                if(locs[j][0] != locs[2*v-1-j][0]){
                    System.out.println("NO");
                    continue qs;
                }
            }
            System.out.println("YES");
        }
    }
    
    
    static void euler(ArrayList<Integer>[] adj, int curr, int par){
        in[curr] = idx;
        parents[curr] = par;
        idx++;
        
        for(int n : adj[curr]){
            if(n == par) continue;
            euler(adj, n, curr);
        }
        
        out[curr] = idx;
        idx++;
    }
}
