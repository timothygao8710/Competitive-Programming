import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class randoms {
    static int ret;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        StringTokenizer st = new StringTokenizer(br.readLine());
        //there must exist a spanning tree for each component...
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        DSU d = new DSU(N+1);
        ret = 0;
        for(int i =0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            d.union(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        pw.println(ret);
        pw.close();
        br.close();
    }
    static class DSU {

        public int[] parent;
        public int[] size;
        
        public DSU(int n) {
            parent = new int[n];
            size = new int[n];
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
                ret++;
                return;
            }
            if (size[rv] > size[ru]) {
                int t = ru;
                ru = rv;
                rv = t;
            }
            parent[rv] = ru;
            size[ru] += size[rv];
        }
    }
}