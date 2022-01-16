import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
            //why is this contest so easy... can be O(TN log(N)) easily but no need to...
            
        int T = Integer.parseInt(br.readLine());
        
        for(int t = 0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] nums = new int[N];
            for(int i = 0; i<N; i++){
                nums[i] = Integer.parseInt(st.nextToken());
            }
            
            int[] ret = new int[N];
            dfs(nums, 0, N-1, 0, ret);
            for(int i : ret){
                pw.print(i + " ");
            }
            pw.println();
        }
        
        
        pw.close();
        br.close();
    }
    
    static void dfs(int[] nums, int l, int r, int d, int[] ret){
        if(l > r) return;
        
        int max = -1;
        int idx = l;
        for(int i = l; i<=r; i++){
            if(nums[i] > max){
                max = nums[i];
                idx = i;
            }
        }
        
        ret[idx] = d;
        dfs(nums, l, idx-1, d+1, ret);
        dfs(nums, idx+1, r, d+1, ret);
    }
}
