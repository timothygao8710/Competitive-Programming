
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); int M = Integer.parseInt(st.nextToken());
        int[][] edges = new int[M][2];
        for(int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            edges[i] = new int[]{Integer.parseInt(st.nextToken())-1, Integer.parseInt(st.nextToken())-1};
        }
        
        int l = 1; int r = M+1;
        
        while(l < r){
            int mid = (l+r)/2;
            if(good(edges, mid, N)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        pw.println(r == M+1 ? -1 : r);
        pw.close();
        br.close();
    }

    
    static boolean good(int[][] edges, int end, int N){
        ArrayList<Integer>[] adj = new ArrayList[N];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        
        int[] inDeg = new int[N];
        
        for(int i = 0; i<end; i++){
            adj[edges[i][0]].add(edges[i][1]);
            inDeg[edges[i][1]]++;
        }
        int cur = -1;
        for(int i= 0; i<N; i++){
            if(inDeg[i] == 0){
                if(cur != -1) return false;
                cur = i;
            }
        }
        
        for(int i= 0; i<N; i++){
            if(cur == -1) return false;
            int next = -1;
            for(int n : adj[cur]){
                inDeg[n]--;
                if(inDeg[n] == 0){
                    if(next != -1) return false;
                    next = n;
                }
            }
            cur = next;
        }
        return true;
    }
}
