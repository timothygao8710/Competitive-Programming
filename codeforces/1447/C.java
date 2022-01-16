
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
        c:
        for(int t= 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            long W = Long.parseLong(st.nextToken());
            long l = (W+1)/2;
            List<int[]> candidates = new ArrayList();
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                int a = Integer.parseInt(st.nextToken());
                if(a > W){
                    continue;
                }
                if(a >= l){
                    pw.println(1); pw.println(i+1); continue c;
                }
                candidates.add(new int[]{a, i+1});
            }
            long sum = 0;
            int i = 0;
            for(; i<candidates.size(); i++){
                sum += candidates.get(i)[0];
                if(sum >= l){
                    break;
                }
            }
            if(sum < l){
                pw.println(-1);
            }else{
                pw.println(i + 1);
                for(; i>=0; i--){
                    pw.print(candidates.get(i)[1] + " ");
                }
                pw.println();
            }
        }
        pw.close();
        br.close();
    }
}
/*

*/