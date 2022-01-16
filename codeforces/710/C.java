
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        int[][] ret = new int[N][N];
        int[] ps = new int[]{2, 1};
        int s = 0;
        if ((N / 2) % 2 == 0) {
            s = 1;
        }
        for (int i = 0; i < N; i++) {
            ret[N / 2][i] = ps[1];
            ps[1] += 2;
        }
        for (int i = 0; i < N; i++) {
            if (i == N / 2) {
                continue;
            }
            ret[i][N / 2] = ps[1];
            ps[1] += 2;
        }
        bfs(ret, 0, 0, s, ps);
        bfs(ret, N - 1, 0, s, ps);
        bfs(ret, 0, N - 1, s, ps);
        bfs(ret, N - 1, N - 1, s, ps);
        
        for (int[] i : ret) {
            for (int j : i) {
                pw.print(j + " ");
            }
            pw.println();
        }
        pw.close();
        br.close();
    }

    static int[] xDir = new int[]{0, 0, 1, -1, 1, 1, -1, -1};
    static int[] yDir = new int[]{1, -1, 0, 0, -1, 1, -1, 1};

    static void bfs(int[][] ret, int y, int x, int s, int[] ps) {
        Queue<int[]> bfs = new ArrayDeque();
        bfs.add(new int[]{y, x});
        while (!bfs.isEmpty()) {
            Queue<int[]> next = new ArrayDeque();
//            System.out.println(bfs.size());
            while (!bfs.isEmpty()) {
                int[] c = bfs.poll();
                if(ret[c[0]][c[1]] != 0) continue;
                ret[c[0]][c[1]] = ps[s % 2];
                ps[s % 2] += 2;
                
                for (int i = 0; i < 8; i++) {
                    int dY = c[0] + yDir[i];
                    int dX = c[1] + xDir[i];
                    if (dY < ret.length && dX < ret.length && dX >= 0 && dY >= 0 && dY != ret.length / 2 && dX != ret.length / 2) {
                        next.add(new int[]{dY, dX});
                    }
                }
            }
            s++;
            bfs = next;
        }
    }
}
