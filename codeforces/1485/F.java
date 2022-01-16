
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;


public class copyofprefsum {
    static long mod = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i<T; i++){
            int N = Integer.parseInt(br.readLine());
            int[] nums = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                nums[j] = Integer.parseInt(st.nextToken());
            }
            pw.println(solve(nums));
        }
        
        pw.close();
        br.close();
    }
    
    static long solve(int[] nums){
        long dpsum = 1;
        long sum = 0;
        Map<Long, Long> prefs = new HashMap<>();
        prefs.put(0L, 1L);
        for(int i : nums){
            long curr = dpsum;
            if(prefs.get(sum) != null){
                curr = (mod + curr - prefs.get(sum))%mod;
            }
            if(prefs.get(sum) == null) prefs.put(sum, 0L);
            prefs.put(sum, (prefs.get(sum) + curr)%mod);
            dpsum += curr;
            dpsum %= mod;
            sum += i;
        }
        return dpsum;
    }
}