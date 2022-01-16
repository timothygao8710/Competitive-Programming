
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] nums = new int[N];
        Map<Integer, ArrayList<Integer>> occ = new HashMap<>();
        int max = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
            if(occ.get(nums[i]) == null) occ.put(nums[i], new ArrayList<>());
            occ.get(nums[i]).add(i);
            max = Math.max(max, occ.get(nums[i]).size());
        }
//        System.out.println(max);
        if(max > K){
            pw.println("NO");
        }else{
            pw.println("YES");
            int[] ret = new int[N];
            int idx = 0;
            for(int i : occ.keySet()){
                for(int j =0; j<occ.get(i).size(); j++, idx = (idx+1)%K){
                    ret[occ.get(i).get(j)] = idx+1;
                }
            }
            for(int i : ret){
                pw.print(i + " ");
            }
        }
        pw.close();
        br.close();
    }
}
