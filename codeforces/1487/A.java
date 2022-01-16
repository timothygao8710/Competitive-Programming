
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class contest {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int min = Integer.MAX_VALUE;
            int count = 0;
            for(int j = 0; j<N; j++){
                int i = Integer.parseInt(st.nextToken());
                if(i < min){
                    min = i;
                    count = 1;
                }else if(i == min){
                    count++;
                }
            }
            
            
            pw.println(N - count);
        }

        pw.close();
        br.close();
    }
}
/*
1
8 10
5 4 3 4 3 2 4 9
 */
