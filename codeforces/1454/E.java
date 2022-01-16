
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * - Long/int - Draw stuff - Use comments - Drink Water - Reread Problem
 *
 * - package/pw.close
 *
 * @author timothy
 */
public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i<T; i++){
            int N = Integer.parseInt(br.readLine());
            ArrayList<Integer>[] adj = new ArrayList[N];
            for(int j =0; j<adj.length; j++) adj[j] = new ArrayList();
            for(int j=0; j<N ;j++){
                StringTokenizer st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken())-1;
                int v = Integer.parseInt(st.nextToken())-1;
                adj[u].add(v);
                adj[v].add(u);
            }
            System.out.println(solve(adj));
        }
    }
    
    static boolean[] inCyc;
    static long ret;
    static int cutoff;
    
    //we can cut the cycle into disjoint trees
    static long solve(ArrayList<Integer>[] adj){
        inCyc = new boolean[adj.length];
        int tot = 0;
        ret = 0;
        List<Long> sizes = new ArrayList();
        cutoff = -1;
        find(adj, 0, -1);
        for(int i = 0; i<inCyc.length; i++){
            if(inCyc[i]){
                sizes.add(dfs(adj, i, -1));
                tot += sizes.get(sizes.size()-1);
            }
        }
        for(long i : sizes){
            ret += i*(tot-i);
        }
        return ret;
    }
    
    static long dfs(ArrayList<Integer>[] adj, int curr, int last){
        long ans = 0;
        long sum = 0;
        List<Long> subs = new ArrayList();
        
        for(int n : adj[curr]){
            if(inCyc[n] || n == last) continue;
            subs.add(dfs(adj,n, curr));
            sum += subs.get(subs.size()-1);
        }
        for(long i : subs){
            ans += i*(sum-i);
        }
        ans/=2; //every path counted twice
        ret += ans+sum; //start/end at root
        return sum+1;
    }
    
    static void find(ArrayList<Integer>[] adj, int curr, int last){
        inCyc[curr] = true;
        boolean ret = false;
        for(int n : adj[curr]){
            if(n == last) continue;
            if(inCyc[n]){
                if(cutoff == -1) cutoff = n;
                ret = true;
            }else{
                find(adj, n, curr);
                if(n != cutoff){
                    ret = ret || inCyc[n];
                }
            }
        }
        inCyc[curr] = ret;
    }
}

