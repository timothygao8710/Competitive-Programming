
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class contest {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            int add = 0;
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                int c = Integer.parseInt(st.nextToken());
                add += Math.min(c, K);
                int n = c;
                c -= Math.min(c, K);
                K -= Math.min(n, K);
                pw.print((i == N-1 ? c + add : c)+ " ");
            }
            pw.println();
        }

        pw.close();
        br.close();
    }
}

