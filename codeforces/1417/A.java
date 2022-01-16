
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
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); int K = Integer.parseInt(st.nextToken());
            int[] nums = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int i=0; i<N; i++){
                nums[i] = Integer.parseInt(st.nextToken());
            }
            long ret =0;
            Arrays.sort(nums);
            for(int i = 1; i<N ;i++){
                ret += (K-nums[i])/nums[0];
            }
            pw.println(ret);
        }
        
        pw.close();
        br.close();
    }
}
