
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class randoms {

    static int mod = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            long[] len = new long[N];
            long[] mid = new long[N+1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j =0; j<N; j++){
                len[j] = Integer.parseInt(st.nextToken())-1;
            }
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                mid[j] = -Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                mid[j] = Math.abs(mid[j] + Integer.parseInt(st.nextToken()));
            }
            pw.println(best(len, mid));
        }

        pw.close();
        br.close();
    }
    
    static long best(long[] len, long[] mid){
        long ret = 0;
        long curr = mid[1] + 2;
        for(int i = 1; i<len.length; i++, curr += 2){
            ret = Math.max(ret, curr + len[i]);
//            System.out.println(curr + " " + len[i]);
            curr += len[i] - mid[i+1];
            if(mid[i+1] == 0) curr = 0; //then you hvae to start it
            curr = Math.max(curr, mid[i+1]);
        }
        return ret;
    }
}
