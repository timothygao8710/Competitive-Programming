import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class virtual {

    static long ret = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
                
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            int ret = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cur = Integer.parseInt(st.nextToken());
            
            for(int i = 1; i<N; i++){
                int next = Integer.parseInt(st.nextToken());
                while(cur*2 < next){
                    cur *= 2;
                    ret++;
                }
                int te = next;
                while(te*2 < cur){
                    te *= 2;
                    ret++;
                }
                cur = next;
            }
            
            pw.println(ret);
        }
        
        
        pw.close();
        br.close();
    }
}
