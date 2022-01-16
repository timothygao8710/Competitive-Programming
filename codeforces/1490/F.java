
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;


public class virtualB {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++){
            int N = Integer.parseInt(br.readLine());
            HashMap<Integer, Integer> mp = new HashMap();
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                int val = Integer.parseInt(st.nextToken());
                if(mp.get(val) == null) mp.put(val, 0);
                mp.put(val, mp.get(val)+1);
            }
            int ret = Integer.MAX_VALUE;
            List<Integer> a = new ArrayList();
            for(int i : mp.keySet()) a.add(mp.get(i));
            
            int left = N;
            
            Collections.sort(a);
            N = a.size();
            for(int i = N-1; i>=0; i--){
                left -= a.get(i);
                if(i != N-1){
                    left += (N-i-1)*(a.get(i+1) - a.get(i));
                }
                ret = Math.min(ret, left);
            }
            pw.println(ret);
        }
       
        pw.close();
        br.close();
    }
}
