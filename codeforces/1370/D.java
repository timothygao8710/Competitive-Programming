
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
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        int[] nums = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i= 0; i<N; i++) nums[i] = Integer.parseInt(st.nextToken());
        int l = 1;
        int r = (int)(1e9+7);
        while(l < r){
            int mid = (l+r)/2;
            if(Math.max(good(nums, mid, 0), good(nums, mid, 1)) >= K){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        System.out.println(r);
    }
    
    static int good(int[] nums, int max, int curr){
        int ret = 0;
        for(int i=0; i<nums.length; i++){
            if(curr == 1){
                ret++;
                curr ^= 1;
            }else{
                if(nums[i] <= max){
                    ret++;
                    curr ^= 1;
                }
            }
        }
        return ret;
    }
}

