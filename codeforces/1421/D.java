
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class virtual {

    static int[][] dirs = new int[][]{
        {1, 0}, {1,1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,-1}, {0, -1}, {1, -1}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            
            int[] costs = new int[8];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i < 8; i++) {
                if (i == 3 || i == 7) {
                    continue;
                }
                costs[i] = Integer.parseInt(st.nextToken());
            }
            costs[0] = Integer.parseInt(st.nextToken());       
            costs[1] = Math.min(costs[1], costs[0] + costs[2]);
            costs[5] = Math.min(costs[4] + costs[6], costs[5]);
            costs[0] = Math.min(costs[0], costs[1] + costs[6]);
            costs[2] = Math.min(costs[2], costs[1] + costs[4]);
            costs[4] = Math.min(costs[4], costs[5] + costs[2]);
            costs[6] = Math.min(costs[6], costs[5] + costs[0]);
            costs[7] = costs[0] + costs[6];
            costs[3] = costs[2] + costs[4];
//            System.out.println(Arrays.toString(costs));
            long ret = 0;
            
            for (int j = 0; j < 2; j++) {
                int[] cur = new int[]{y == 0 ? 0 : y / Math.abs(y), x == 0 ? 0 : x / Math.abs(x)};
//                System.out.println(Arrays.toString(cur));
                int min = Math.min(Math.abs(x), Math.abs(y));
                if(x == 0 || y == 0) min = Math.max(Math.abs(x), Math.abs(y));
                for (int i = 0; i < 8; i++) {
                    if (cur[1] == dirs[i][1] && cur[0] == dirs[i][0]) {
                        ret += (long)costs[i]*min;
//                        System.out.println(i);
                        if(x != 0) x -= dirs[i][1]*min;
                        if(y != 0) y -= dirs[i][0]*min;
                        break;
                    }
                }
//                System.out.println(x +" " +y);
//                System.out.println(ret + " " + min);
            }
            pw.println(ret);
        }
        pw.close();
        br.close();
    }
}