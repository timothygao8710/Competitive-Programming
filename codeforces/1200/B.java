
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * - Long/int - Draw stuff - Use comments - Drink Water - Reread Problem
 *
 * - package/pw.close
 *
 * @author timothy
 */
public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            
            int[] nums = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                nums[j] = Integer.parseInt(st.nextToken());
            }
            System.out.println(solve(nums, M, K) ? "YES" : "NO");
        }
    }
    
    static boolean solve(int[] nums, int start, int range){
        for(int i = 0; i<nums.length-1; i++){
            int down = Math.max(0, nums[i+1]-range);
            if(nums[i] < down){
                start -= down-nums[i];
                if(start < 0) return false;
            }else{
                start += nums[i] - down;
            }
        }
        return true;
    }
}
