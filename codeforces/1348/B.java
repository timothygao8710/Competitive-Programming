
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class phoenixand {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            List<Integer> cyc = new ArrayList();
            int[] nums = new int[N];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                nums[i] = Integer.parseInt(st.nextToken());
                if(!cyc.contains(nums[i])) cyc.add(nums[i]);
            }
            if(cyc.size() > K){
                pw.println(-1);continue;
            }
            for(int i = 1; cyc.size() < K && i<=N; i++){
                if(!cyc.contains(i)) cyc.add(i);
            }
            List<Integer> ret = new ArrayList();
            int idx = 0;
            for(int i = 0; i<N; i++, idx=(idx+1)%cyc.size()){
                ret.add(cyc.get(idx));
                while(cyc.get(idx) != nums[i]){
                    idx=(idx+1)%cyc.size();
                    ret.add(cyc.get(idx));
                }
            }
            pw.println(ret.size());
            for(int i : ret) pw.print(i +" ");
            pw.println();
        }
        
        pw.close();
        br.close();
    }

}
