
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i<T; i++){
            int N = Integer.parseInt(br.readLine());
            int[] nums = new int[N];
            StringTokenizer st = new StringTokenizer(br.readLine());
            Set<Integer> has = new HashSet();
            for(int j =0; j<N; j++){
                nums[j] = Integer.parseInt(st.nextToken());
                for(int k = j-1; k>=0; k--){
                    has.add(nums[j] - nums[k]);
                }
            }
            
            pw.println(has.size());
        }
        
        
        pw.close();
        br.close();
    }
}
