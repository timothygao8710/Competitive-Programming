
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); int M = Integer.parseInt(st.nextToken()); int K = Integer.parseInt(st.nextToken());
        Map<Integer, Integer> big = new HashMap();
        st = new StringTokenizer(br.readLine());
        int[] nums = new int[N];
        for(int i = 0; i<N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
            
        }
        long sum = 0;
        int[] temp = nums.clone();
        Arrays.sort(temp);
        for(int i = N-1; i>=N-M*K; i--){
            if(big.get(temp[i]) == null) big.put(temp[i], 0);
            big.put(temp[i], big.get(temp[i])+1);
            sum += temp[i];
        }
        pw.println(sum);
        int i = 0;
        int bef = 0;
        for(int j = 0; j<K-1; j++){
            int need = M;
            int sz = 0;
            for(; need > 0; i++, sz++){
                if(big.containsKey(nums[i])){
                    big.put(nums[i], big.get(nums[i])-1);
                    if(big.get(nums[i]) == 0) big.remove(nums[i]);
                    need--;
                }
            }
            bef += sz;
            pw.print(bef + " ");    
        }
        
        pw.close();
        br.close();
    }
}
