
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
            for(int j =0; j<N; j++){
                nums[j] = Integer.parseInt(st.nextToken());
            }
            Set<Integer> has = new HashSet();
            for(int j = N-1; j>=0; j--){
                if(!has.contains(nums[j]+1)){
                    has.add(nums[j]+1);
                }else if(!has.contains(nums[j])){
                    has.add(nums[j]);
                }
            }
            pw.println(has.size());
        }
        
        
        pw.close();
        br.close();
    }
}
