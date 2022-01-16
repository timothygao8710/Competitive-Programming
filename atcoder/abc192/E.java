// package atcoder;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int X = Integer.parseInt(st.nextToken())-1;
        int Y = Integer.parseInt(st.nextToken())-1;
        
        ArrayList<int[]>[] adj = new ArrayList[N];
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for(int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken())-1;
            int v = Integer.parseInt(st.nextToken())-1;
            int w = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            
            adj[u].add(new int[]{v, w, k});
            adj[v].add(new int[]{u, w, k});
        }
        
        long[] dist = new long[adj.length];
        Arrays.fill(dist, -1L);
        Queue<long[]> pq = new PriorityQueue<>((long[] a, long[] b) -> Long.compare(a[1], b[1]));
        pq.add(new long[]{X, 0L});
        while(!pq.isEmpty()){
            long[] cur = pq.poll();
            if(dist[(int)cur[0]] != -1) continue;
            dist[(int)cur[0]] = cur[1];
            for(int[] n : adj[(int)(cur[0])]){
                pq.add(new long[]{n[0], n[1] + cur[1] + (cur[1]%n[2] == 0 ? 0 : (n[2] - cur[1]%n[2]))});
            }
        }
        pw.println(dist[Y]);
        pw.close();
        br.close();
   }
}
