
import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class randoms {

    static int[] neat = new int[]{1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        long a = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            a += Integer.parseInt(st.nextToken()) * neat[i % 2];
        }
        TreeSet<Long> all = new TreeSet<>();
        Deque<Integer> dq = new ArrayDeque();
        long b = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            int c = Integer.parseInt(st.nextToken()) * neat[i % 2];
            dq.addLast(c);
            b += c;
            if (dq.size() == N + 1) {
                b -= dq.pollFirst();
            }
            if (dq.size() == N) {
                all.add(b * neat[(i - N + 1) % 2]);
            }
        }
//        System.out.println(all.size());
//        System.out.println(a);
//        for(long i : all) System.out.println(i);
        pw.println(find(all, a));
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            if ((r - l) % 2 == 0) {
                l %= 2;
                l ^= 1;
                a += neat[l] * Integer.parseInt(st.nextToken());
            }
            pw.println(find(all, a));
        }
        pw.close();
        br.close();
    }

    static long find(TreeSet<Long> set, long val) {
        Long up = set.ceiling(val);
        Long down = set.floor(val);
        if (up == null) {
            return val - down;
        }
        if (down == null) {
            return up - val;
        }
        return Math.min(val - down, up - val);
    }
}
