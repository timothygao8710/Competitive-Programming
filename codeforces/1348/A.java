
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class phoenixand {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            long ret = 1<<N;
            for(int i = 1; i<N; i++){
                if(i < N/2){
                    ret += 1<<i;
                }else{
                    ret -= 1<<i;
                }
            }
            pw.println(ret);
        }
        
        pw.close();
        br.close();
    }

}
