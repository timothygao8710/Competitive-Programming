import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;
 
public class randoms {
    static int ret;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
 
        int T = Integer.parseInt(br.readLine());
        t:
        for(int t = 0; t<T; t++){
            int N = 2*Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<int[]> l = new ArrayList();
            l.add(new int[]{Integer.parseInt(st.nextToken()), 1});
            for(int i = 1; i<N; i++){
                int c = Integer.parseInt(st.nextToken());
                if(l.get(l.size()-1)[0] < c) l.add(new int[]{c, 0});
                l.get(l.size()-1)[1]++;
            }
            Set<Integer> dp = new HashSet();
            dp.add(0);
            for(int[] i : l){
                List<Integer> n = new ArrayList();
                for(int j : dp){
                    if(j + i[1] <= N/2){
                        n.add(j + i[1]);
                    }
                }
                for(int j : n) dp.add(j);
                if(dp.contains(N/2)){
                    pw.println("YES");
                    continue t;
                }
            }
            pw.println("NO");
        }
        
        pw.close();
        br.close();
    }
}