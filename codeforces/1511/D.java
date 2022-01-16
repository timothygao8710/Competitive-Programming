
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int cyc = K * (K - 1) / 2 + K;
        int idx = 0;
        l:
        while (true) {
            for (int i = 0; i < K; i++) {
                pw.print(toc(i));
                    idx++;
                    if (idx == N) {
                        break l;
                    }
                for (int j = i+1; j < K; j++) {
                    pw.print(toc(i));
                    idx++;
                    if (idx == N) {
                        break l;
                    }
                    pw.print(toc(j));
                    idx++;
                    if (idx == N) {
                        break l;
                    }
                }
            }
        }
//        long ret = K*K*(N/cyc);
//        ret += (N%cyc - 1)*cyc;
//        pw.println(ret);
        pw.close();
        br.close();
    }

    static char toc(int a) {
        return (char) ('a' + a);
    }
}
