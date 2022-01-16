
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class virtual {

    static long ret;
    static long[] p;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        ret = 0;
        ArrayList<Integer>[] adj = new ArrayList[N];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i<N; i++){
            adj[Integer.parseInt(st.nextToken())-1].add(i);
        }
        st = new StringTokenizer(br.readLine());
        p = new long[N];
        for(int i=  0; i<p.length; i++){
            p[i] = Integer.parseInt(st.nextToken());
        }
        
        dfs(adj, 0);
        pw.println(ret);
        pw.close();
        br.close();
    }
    
    static long[] dfs(ArrayList<Integer>[] adj, int c){
        long[] curr = new long[2];
        for(int n : adj[c]){
            long[] r = dfs(adj, n);
            curr[0] += r[0];
            curr[1] += r[1];
        }
        if(adj[c].isEmpty()) curr[0]++;
        curr[1] += p[c];
        ret = Math.max(ret, (curr[1] + curr[0] - 1)/curr[0]);
        return curr;
    }
}
