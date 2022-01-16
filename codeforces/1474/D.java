
import java.io.*;
import java.util.*;

public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            int[] nums = new int[N+2];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 1; i<=N; i++){
                nums[i] = Integer.parseInt(st.nextToken());
            }
            pw.println(solve(nums) ? "YES" : "NO");
        }
        pw.close();
        br.close();
    }
    
    static boolean solve(int[] nums){
        int[] pref = new int[nums.length];
        int[] suf = new int[nums.length];
        Arrays.fill(pref, -1); Arrays.fill(suf, -1);
        pref[0] = suf[suf.length-1] = 0;
        for(int i = 1; i<pref.length-1; i++){
            pref[i] = nums[i] - pref[i-1]; if(pref[i] < 0) break;
        }
        if(pref[pref.length-2] == 0) return true;
        for(int i = suf.length-2; i>=0; i--){
            suf[i] = nums[i] - suf[i+1]; if(suf[i] < 0) break;
        }
        for(int i = 1; i+2 < suf.length; i++){
            if(pref[i-1] <0 || suf[i+2] < 0) continue;
            if(nums[i] - pref[i-1] >= 0 && nums[i+1] - suf[i+2] >= 0 && nums[i] - pref[i-1] == nums[i+1] - suf[i+2]) return true;
            if( 
                    (nums[i+1] - pref[i-1] >= 0 && nums[i] - suf[i+2] >= 0) 
                    && 
                    (nums[i+1] - pref[i-1] == nums[i] - suf[i+2])){
                return true;
            }
        }
        return false;
    }
}
