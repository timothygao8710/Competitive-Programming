
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        int[] prime = new int[100001];
        int[] back = new int[N + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            int num = Integer.parseInt(st.nextToken());
            int cop = 0;
            for (int j = 2; j * j <= num; j++) {
                if (num % j != 0) {
                    continue;
                }
                while (num % j == 0) {
                    num /= j;
                }
                cop = Math.max(cop, prime[j]);
                prime[j] = i;
            }
            if(num != 1){
                cop = Math.max(cop, prime[num]);
                prime[num] = i;
            }
            back[i] = Math.max(back[i - 1], cop);
        }
        //could use dfs but binlift cleaner
        int[][] binlift = new int[22][N + 1];
        binlift[0] = back;
        for(int i = 1; i<22; i++){
            for(int j=1; j<=N; j++){
                binlift[i][j] = binlift[i-1][binlift[i-1][j]];
            }
        }
        for (int q = 0; q < Q; q++) {
            st = new StringTokenizer(br.readLine());
            int ret = 0;
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            //next iteration cant have a higher power than current
            while (a <= back[b]) {
                int i = 0;
                int dist = 1;
                for (; binlift[i+1][b] > a; i++) {
                    dist *= 2;
                }
                ret += dist;
                b=binlift[i][b];
            }
            pw.println(ret+1);
        }
        pw.close();
        br.close();
    }
}
