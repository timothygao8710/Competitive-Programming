
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class virtual {

    static long ret = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int max = (int)(1e9);
        
        //a^2 - (2b + 1)
        //(a^2 - 1) /2 
        List<Long> cs = new ArrayList<>();
        
        for(long i = 1; i*i -  (i*i - 1)/2<= max; i+=2){
            long a = i;
            long b = (i*i - 1)/2;
            long c = i*i -  (i*i - 1)/2;
//            System.out.println(a + " " +b + " " + c);
            if(a <= b && b <= c){
                cs.add(c);
            }
        }
//        System.out.println(cs.size());
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            int l = -1;
            int r = cs.size()-1;
            while(l < r){
                int mid = (l+r+1)/2;
                if(cs.get(mid) <= N){
                    l = mid;
                }else{
                    r = mid-1;
                }        
            }
            pw.println(l+1);
        }
        pw.close();
        br.close();
    }
}
