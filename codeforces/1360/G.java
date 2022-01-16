
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class duels {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()); int m = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken()); int b = Integer.parseInt(st.nextToken());
            
            if(n*a != m*b){
                pw.println("NO"); continue;
            }
            pw.println("YES");
            int[][] ret = new int[n][m];
            for(int i = 0; i<n; i++){
                int idx = (i*a)%m;
                for(int j= 0; j<a; j++){
                    ret[i][idx] = 1;
                    idx = (idx+1)%m;
                }
            }
            for(int[] i : ret){
                for(int j : i){
                    pw.print(j);
                }
                pw.println();
            }
        }
        
        pw.close();
        br.close();
    }
}
