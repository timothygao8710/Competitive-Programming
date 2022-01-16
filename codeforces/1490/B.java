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
            int[] rem = new int[3];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                rem[Integer.parseInt(st.nextToken())%3]++;
            }
            int ret = Math.max(0, rem[0] - N/3);
            rem[1] += ret;
            if(rem[1] > N/3){
                ret += rem[1] - N/3;
                rem[2] += rem[1] - N/3;
            }else{
                ret += N/3 - rem[1];
            }
            pw.println(
            
            ret + Math.max(0, rem[2] - N/3)
            
            );
        }
        
        
        pw.close();
        br.close();
    }
}
