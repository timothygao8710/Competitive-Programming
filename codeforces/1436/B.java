
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class virtual {

    static int mod = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        HashSet<Integer> primes = new HashSet();
        c:
        for(int i = 2; i<100_000; i++){
            for(int j : primes){
                if(i%j == 0) continue c;
            }
            primes.add(i);
        }
        
        primes.add(1);
        int T = Integer.parseInt(br.readLine());

        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[][] ret = new int[N][N];
            for(int[] i : ret) Arrays.fill(i, 1);
            int comp = -1;
                for(int j : primes){
                    if(j > N && !primes.contains(j - (N-1))){
                        comp = j - (N-1);
                        break;
                    }
                }
            for(int j = 0; j<N; j++){
                ret[j][j] = comp;
            }
            for(int[] i : ret){
                for(int j : i) pw.print(j + " ");
                pw.println();
            }
        }

        pw.close();
        br.close();
    }
}
