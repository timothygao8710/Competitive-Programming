
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

/**
 * - Long/int - Draw stuff - Use comments - Drink Water - Reread Problem
 *
 * - package/pw.close
 *
 * @author timothy
 */
public class randoms {

    //x, y, z are the number of elements in each
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            int[] nums = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                nums[j] = Integer.parseInt(st.nextToken());
            }
            solve(nums);
        }
    }

    static void solve(int[] nums){
        int[] suf = new int[nums.length+1];
        suf[nums.length] = Integer.MIN_VALUE;
        for(int i = nums.length-1; i>=0; i--){
            suf[i] = Math.max(suf[i+1], nums[i]);
        }
        
        sparse table = new sparse(nums);
        int max = Integer.MIN_VALUE;
        for(int i = 0; i<nums.length-2; i++){
            max = Math.max(max, nums[i]);
            int l = i+2;
            int r = nums.length-1;
            
            while(l <= r){ //range inclusive
                int mid = (l+r)/2;
                int y = table.get(i+1, mid-1); 
                if(y == suf[mid] && y == max){
                    System.out.println("YES");
                    System.out.println((i+1) + " " + (mid-i-1) + " " + (nums.length-mid));
                    return;
                }
                if(y >= max && suf[mid] >= max){
                    l = mid+1;
                }else if(y <= max && suf[mid] <= max){
                    r = mid-1;
                }else{
                    break;
                }
            }
        }
        System.out.println("NO"); //you
    }
    
    static class sparse {

        public int[][] table;

        public sparse(int[] nums) {
            int maxFit = maxPow(nums.length);
            table = new int[maxFit][nums.length];

            table[0] = nums;

            for (int i = 1; i < maxFit; i++) {
                for (int j = 0; j + (1 << i) - 1 < nums.length; j++) {
                    table[i][j] = Math.min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
                }
            }
        }

        public int get(int l, int r) {
            int max = maxPow(r - l + 1)-1;
            return Math.min(table[max][l], table[max][r - (1 << max) + 1]);
        }

        //returns the power not the number
        private int maxPow(int num) {
            int ret = 0;
            while (num > 0) {
                num >>= 1;
                ret++;
            }
            return ret;
        }
    }
}
