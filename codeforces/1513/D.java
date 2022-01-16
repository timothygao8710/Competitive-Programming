
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        
        for(int t = 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); long P = Integer.parseInt(st.nextToken());
            int[] nums = new int[N];
            int[][] locs = new int[N][2];
            DSU dsu = new DSU(N);st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                nums[i] = Integer.parseInt(st.nextToken()); locs[i] = new int[]{nums[i], i};
            }
            Arrays.sort(locs, (int[] a, int[] b) -> a[0] - b[0]);
            long ret = 0;
            for(int[] i : locs){
                if(i[0] > P) break;
                for(int j = i[1]-1; j>=0 && dsu.find(j) != dsu.find(i[1]) && nums[j]%nums[i[1]] == 0; j--){
                    N--; dsu.union(j, i[1]); ret += i[0];
                }
                for(int j = i[1]+1; j<nums.length && dsu.find(j) != dsu.find(i[1])&& nums[j]%nums[i[1]] == 0; j++){
                    N--; dsu.union(j, i[1]); ret += i[0];
                }
            }
            ret += (N-1)*P; //shEEEEEsh
            pw.println(ret);
        }
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
