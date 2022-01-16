
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
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
        int N = Integer.parseInt(br.readLine());
        //the graph is directed, BUT we don't care because
        //Two types of CCs: cycle, no cycle
        //cycle:
        //edges = nodes
        //contribution: 2
        //doesnt matter edge type
        
        //no cycle:
        //edges +1 = nodes (the last edge connects to a non-occupied)
        //tree, doesnt matter edge type because there is exactly 1 root location where everything pulls to
        DSU dsu = new DSU(2*N);
        List<Integer> occs = new ArrayList();
        int times = 0;
        /*
        we cant completely ignore self loops if something else links to it
        */
        for(int i = 0; i<N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            occs.add(u);
            
            int v = Integer.parseInt(st.nextToken())-1;
            occs.add(v);
            if(u == v)times++;
            dsu.union(u, v);
        }
        long ret = 1;
        Set<Integer> ccs = new HashSet();
        for(int i : occs){
            int v = dsu.find(i);
            if(ccs.contains(v)) continue;
            
            if(dsu.cycle[v]){
                if(times == 0){
                    ret *= 2;
                }else{
                    times--;
                }
            }else{
                ret *= dsu.size[v];
            }
            ret %= mod;
            ccs.add(v);
        }
        System.out.println(ret);
    }
    static int mod = 1_000_000_007;
    static class DSU {

        public int[] parent;
        public int[] size;
        public boolean[] cycle;
        
        public DSU(int n) {
            parent = new int[n];
            size = new int[n];
            cycle = new boolean[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        public int find(int u) {
            if (u != parent[u]) {
                parent[u] = find(parent[u]);
            }
            return parent[u];
        }
        
        public void union(int u, int v) {
            int ru = find(u);
            int rv = find(v);
            
            if (ru == rv) {
                cycle[ru] = true;
                return;
            }
            
            if (size[ru] > size[rv]) {
                parent[rv] = ru;
                size[ru] += size[rv];
                cycle[ru] = cycle[ru] || cycle[rv];
            } else {
                parent[ru] = rv;
                size[rv] += size[ru];
                cycle[rv] = cycle[ru] || cycle[rv];
            }
        }
    }
}

