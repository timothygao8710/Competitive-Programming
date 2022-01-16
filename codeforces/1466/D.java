
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i<T; i++){
            int N = Integer.parseInt(br.readLine());
            long step = 0;
            int[] weight = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                weight[j] = Integer.parseInt(st.nextToken());
                step += weight[j];
            }
            List<Integer> ad = new ArrayList<>();
            Set<Integer> vis = new HashSet<>();
            for(int j = 0; j<N-1; j++){
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken())-1;
                int v = Integer.parseInt(st.nextToken())-1;
                if(vis.contains(u)){
                    ad.add(weight[u]);
                }
                if(vis.contains(v)){
                    ad.add(weight[v]);
                }
                vis.add(u);
                vis.add(v);
            }
            System.out.print(step + " ");
            Collections.sort(ad, Collections.reverseOrder());
            for(int a : ad){
                step += a;
                System.out.print(step + " ");
            }
            System.out.println();
        }
        
        
        pw.close();
        br.close();
    }
}