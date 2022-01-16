
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class duels {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()); int K = Integer.parseInt(st.nextToken());
        Map<Integer, Integer> occ = new HashMap();
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<N; i++){
            int c = Integer.parseInt(st.nextToken());
            if(occ.get(c) == null) occ.put(c, 0);
            occ.put(c, occ.get(c)+1);
        }
        
        List<int[]> all = new ArrayList<>();
        for(int i : occ.keySet()) all.add(new int[]{i, occ.get(i)});
        Collections.sort(all, (int[] a, int[] b) -> b[1] - a[1]);
        int l = 1;
        int r = N;
        while(l < r){
            int mid = (l+r+1)/2;
            ArrayList<int[]> temp = new ArrayList<>();
            for(int[] i : all) temp.add(i.clone());
            if(good(mid, temp).size() >= K){
                l = mid;
            }else{
                r = mid-1;
            }
        }
//        System.out.println(l + " " + all.size());
        List<Integer> ret = good(l, all);
        for(int i = 0; i<K; i++) pw.print(ret.get(i) +" ");
        pw.close();
        br.close();
    }
    
    static List<Integer> good(int dup, List<int[]> nums){
        List<Integer> ret = new ArrayList<>();
        for(int[] i : nums){
            while(i[1] >= dup){
                ret.add(i[0]);
                i[1] -= dup;
            }
        }
        return ret;
    }
}
