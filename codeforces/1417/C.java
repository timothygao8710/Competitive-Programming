
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[] ret = new int[N+1];
            Arrays.fill(ret, N+1);
            ArrayList<Integer>[] locs = new ArrayList[N+1];
            for (int i = 1; i < locs.length; i++) {
                locs[i] = new ArrayList<>();
                locs[i].add(-1);
            }
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                locs[Integer.parseInt(st.nextToken())].add(i);
            }
            for(int i = 1; i<=N; i++){
                if(locs[i].size() == 1) continue;
                locs[i].add(N);
                int maxdist = 0;
                for(int j = 1; j<locs[i].size(); j++){
                    maxdist = Math.max(maxdist, locs[i].get(j) - locs[i].get(j-1) - 1);
                }
                ret[maxdist+1] = Math.min(ret[maxdist+1], i);
            }
            int run = N+1;
            for(int i = 1; i<=N; i++){
                run = Math.min(run, ret[i]);
                pw.print((run == N+1 ? -1 : run) + " ");
            }
            pw.println();
        }
        
        pw.close();
        br.close();
    }
}
