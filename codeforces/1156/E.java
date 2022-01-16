
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;


/*
This problem falls under the same idea as small to large merging. In fact, it could be viewed as reverse small-to-large
merging. The idea of the proof is ingenious: Consider each single element instead of all the operations overall. 
It will only merge/be split when the other segment is >= in size compared to it.
*/

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        int N = Integer.parseInt(br.readLine());
        int[] nums = new int[N];
        List<Integer> sorted = new ArrayList<>();
        int[] locs = new int[N+1];
        TreeSet<Integer> bars = new TreeSet();
        int ret = 0;
        bars.add(-1); bars.add(N);
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
            sorted.add(nums[i]);
            locs[nums[i]] = i;
        }
        Collections.sort(sorted, Collections.reverseOrder());
        for(int i = 0; i<N; i++){
            int idx = locs[sorted.get(i)];
            int l = bars.floor(idx); int r = bars.ceiling(idx);
            if(r - idx < idx - l){
                for(int j = idx+1; j<r; j++){
                    int dest = locs[sorted.get(i) - nums[j]];
                    if(l < dest && dest < idx) ret++;
                }
            }else{
                for(int j = idx-1; j>l; j--){
                    int dest = locs[sorted.get(i) - nums[j]];
                    if(idx < dest && dest < r) ret++;
                }
            }
            bars.add(idx);
        }
        pw.println(ret);
        pw.close();
        br.close();
    }
}
