
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class random {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        
        List<Integer> nums = new ArrayList();
        st = new StringTokenizer(br.readLine());
        for(int i= 0; i<N; i++){
            nums.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(nums);
        boolean[] dp = new boolean[N];
        List<Integer> closest = new ArrayList();
        int p = 0;
        closest.add(N);
        for(int i = N-K;i>=0;i--){
            if(p + 1 < closest.size() && closest.get(p+1) - i >= K) p++;
            if(nums.get(i+K-1) - nums.get(i) <= D && nums.get(closest.get(p)-1) - nums.get(i) <= D){
                dp[i] = true;
                closest.add(i);
            }
        }
        
        pw.println(dp[0] ? "YES" : "NO");
        pw.close();
        br.close();
    }
}
