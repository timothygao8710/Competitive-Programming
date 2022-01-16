import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
 
public class randoms {
    static int ret;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
 
        int T = Integer.parseInt(br.readLine());
        t:
        for(int i = 0; i<T; i++){
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                if(Integer.parseInt(st.nextToken()) == 1) continue;
                pw.println((j%2 == 1) ? "Second" : "First");
                continue t;
            }
            pw.println((N%2 == 0) ? "Second" : "First");
        }
        
        pw.close();
        br.close();
    }
}