
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st;
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            int[][] coords = new int[N][2];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                coords[i][1] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                coords[i][0] = Integer.parseInt(st.nextToken());
            }
            
            Arrays.sort(coords, (int[] a, int[] b) -> a[1] - b[1]);
            long ret =0;
            int[] cur = new int[]{1,1};
            for(int i = 0; i<N; i++){
                if((cur[0] + cur[1])%2 == 0){
                    if(coords[i][1] - cur[1] == coords[i][0] - cur[0]){
                        ret += coords[i][1] - cur[1];
                        cur = coords[i]; continue;
                    }
                    cur[1]++;
                }
                ret += (coords[i][1] - cur[1] + cur[0]  - coords[i][0] + 1)/2;
                cur = coords[i];
            }
            pw.println(ret);
        }
        pw.close();
        br.close();
    }
}
