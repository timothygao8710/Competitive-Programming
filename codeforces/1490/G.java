
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
        
        StringTokenizer st;
        for(int t = 0; t < T; t++){
            st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int Q = Integer.parseInt(st.nextToken());
            
            List<long[]> inc = new ArrayList();
            inc.add(new long[]{0L, -1});
            
            long sum = 0;
            
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                sum += Integer.parseInt(st.nextToken());
                if(inc.get(inc.size()-1)[0] < sum){
                    inc.add(new long[]{sum, i});
                }
            }
            
            st = new StringTokenizer(br.readLine());
//            System.out.println("YES");
            for(int i = 0; i<Q; i++){
                int x = Integer.parseInt(st.nextToken());
                if(x > inc.get(inc.size()-1)[0]){
                    if(sum <= 0){
                        pw.print(-1);
                    }else{
                        long div = Math.max(0,(x-inc.get(inc.size()-1)[0]+sum-1)/sum);
                        pw.print(div*N + 
                                bs(inc, (int)(x - div*sum))
                                );
                    }
                }else{
                    pw.print(Math.max(0,bs(inc, x)));
                }
                pw.print(" ");
            }
            
            pw.println();
        }
       
        pw.close();
        br.close();
    }
    
    static long bs(List<long[]> inc, int val){
        int l = 0;
        int r = inc.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(inc.get(mid)[0] >= val){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return inc.get(r)[1];
    }
}
/*
1
2 2
1 2
2 1

*/