
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        int N = Integer.parseInt(br.readLine());
        int[][] temp = new int[N][2];
        for(int i = 0; i<N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            temp[i] = new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
        }
        Arrays.sort(temp, (int[] a, int[] b) -> Math.max(a[0], a[1]) - Math.max(b[0], b[1]));
        int[][][] ps = new int[N+1][2][2];
        for(int i = 1; i<=N; i++){
            ps[i][0][0] = ps[i][1][1] = Integer.MAX_VALUE;
            ps[i][0][1] = ps[i][1][0] = Integer.MIN_VALUE;
        }
        int lev = 1;
        int last = Math.max(temp[0][0], temp[0][1]);
        for(int i = 0; i<N; i++){
            if(last != Math.max(temp[i][0], temp[i][1])) lev++;
            last = Math.max(temp[i][0], temp[i][1]);
            if(temp[i][0] < ps[lev][0][0] || temp[i][1] > ps[lev][0][1]){
                ps[lev][0] = temp[i];
            }
            if(temp[i][1] < ps[lev][1][1] || temp[i][0] > ps[lev][1][0]){
                ps[lev][1] = temp[i];
            }
        }
//        for(int i = 0; i<ps.length; i++){
//            for(int j = 0; j<2; j++){
//                System.out.print(Arrays.toString(ps[i][j]));
//            }
//            System.out.println();
//        }
        long ret = -1;
        long[][] dp = new long[N+1][2];
        for(int i = 1; i<=N; i++){
            if(ps[i][0][0] == Integer.MAX_VALUE) break;
            for(int j = 0; j<2; j++){
                dp[i][j] = Long.MAX_VALUE;
                for(int k = 0; k<2; k++){
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][k] + dist(ps[i-1][k], ps[i][j]) + 2*dist(ps[i][0], ps[i][1]));
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][k] + dist(ps[i-1][k], ps[i][j^1]) + dist(ps[i][0], ps[i][1]));
                }
            }
            ret = Math.min(dp[i][0], dp[i][1]);
        }
        pw.println(ret);
        pw.close();
        br.close();
    }
    
    static long dist(int[] a, int[] b){
        return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
    }
}
