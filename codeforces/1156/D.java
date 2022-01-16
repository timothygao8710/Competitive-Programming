
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class virtual {

    static long ret = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        DSU one = new DSU(N);
        DSU zero = new DSU(N);
        
        long ret = 0;
        
        for(int i = 0; i<N-1; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            int c = Integer.parseInt(st.nextToken());
            
            if(c == 0){
                zero.union(u, v);
            }else{
                one.union(u, v);
            }
        }
        
        for(int i = 0; i<N; i++){
            if(one.parent[i] == i){
                ret += ((long)one.size[i]*((long)one.size[i]-1));
            }
            if(zero.parent[i] == i){
                ret += ((long)zero.size[i]*((long)zero.size[i]-1));
            }
            ret += ((long)one.size[one.find(i)]-1)*((long)zero.size[zero.find(i)]-1);
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
                return;
            }
            if (size[ru] > size[rv]) {
                parent[rv] = ru;
                size[ru] += size[rv];
            } else {
                parent[ru] = rv;
                size[rv] += size[ru];
            }
        }
    }
}
