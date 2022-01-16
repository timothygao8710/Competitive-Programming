
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        
        for(int t = 0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            int[] ret = new int[N];
            long[] par = new long[2];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                ret[i] = Integer.parseInt(st.nextToken());
                par[i%2] += ret[i];
            }
            int sup = 0;
            if(par[1] > par[0]) sup = 1;
            for(int i = 0;i<N; i++){
                if(i%2 != sup) ret[i] = 1;
                pw.print(ret[i] +" ");
            }
            pw.println();
        }
        
        br.close();
        pw.close();
    }
}
