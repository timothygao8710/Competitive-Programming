
import java.io.*;
import java.util.*;

public class randoms {

    static List<Integer> ret;
    static ArrayList<Integer>[] compnonchain;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[] inDeg = new int[n];
        int[] outDeg = new int[n];
        DSU group = new DSU(n);
        boolean[] comp = new boolean[n];
        boolean can = true;
        ArrayList<Integer>[] adj = new ArrayList[n];
        compnonchain = new ArrayList[n];
        int[] par = new int[n];
        int root = 0;
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
            compnonchain[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int c = Integer.parseInt(st.nextToken()) - 1;
            par[i] = c;
        }

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            if (inDeg[v] != 0 || outDeg[u] != 0 || group.find(v) == group.find(u)) {
                can = false;
            }
            inDeg[v]++;
            outDeg[u]++;
            comp[u] = comp[v] = true;
            group.union(u, v);
            adj[u].add(v);
        }
        for(int i = 0; i<n; i++){
            if(par[i] == -1){
                root = i; continue;
            }
            if(group.find(i) != group.find(par[i])){
                adj[par[i]].add(i);
                group.inDeg[group.find(i)]++;
            }else{
                compnonchain[par[i]].add(i);
            }
        }
        if (!can || !solve(adj, group, comp, root) || ret.size() != n) { //
            pw.println(0);
        } else {
            for (int i : ret) {
                pw.print((i + 1) + " ");
            }
            pw.println();
        }

        pw.close();
        br.close();
    }

    static boolean solve(ArrayList<Integer>[] adj, DSU chain, boolean[] comp, int root) {
        Deque<Integer> bfs = new ArrayDeque();
        boolean[] vis = new boolean[adj.length];
        ret = new ArrayList();
        bfs.add(root);
        while (!bfs.isEmpty()) {
            List<Integer> specials = new ArrayList<>();
            while (!bfs.isEmpty()) {
                int c = bfs.poll();
                if (vis[c]) {
                    return false;
                }
                vis[c] = true;

                if (comp[c]) {
                    int r = chain.find(c);
                    chain.inDeg[r]--;
                    if (chain.inDeg[r] <= 0) {
                        specials.add(r);
                    }
                    continue;
                }
                ret.add(c);
                for (int n : adj[c]) {
                    bfs.add(n);
                }
            }

            for (int i : specials) {
                int c = i;
                while (c != -1) {
                    int nxt = -1;
                    vis[c] = true;
                    ret.add(c);
                    for (int n : adj[c]) {
                        if (chain.find(n) == i) {
                            nxt = n;
                        } else {
                            bfs.add(n);
                        }
                    }
                    for(int n : compnonchain[c]){
                        if(vis[n]){
                            return false;
                        }
                    }
                    c = nxt;
                }
            }
        }
        return true;
    }

    static class DSU {

        public int[] parent;
        public int[] inDeg;

        public DSU(int n) {
            inDeg = new int[n];
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
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
                return;
            }
            parent[rv] = ru;
            inDeg[ru] += inDeg[rv];
        }
    }
}
