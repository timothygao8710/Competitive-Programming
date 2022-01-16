
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        int[] nums = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        int Q = Integer.parseInt(br.readLine());

        segtree gcd = new segtree(nums, 0, N - 1, true);
        segtree min = new segtree(nums, 0, N - 1, false);

        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(br.readLine());
            int l = Integer.parseInt(st.nextToken())-1;
            int r = Integer.parseInt(st.nextToken())-1;
            int sub = 0;
            
            if (min.get(l, r, 0, N - 1)[0] == gcd.get(l, r, 0, N - 1)[0]) {
                sub = min.get(l, r, 0, N - 1)[1];
            }
            pw.println(r - l + 1 - sub);
        }

        pw.close();
        br.close();
    }

    static class segtree {

        public boolean gcd;
        public segtree left;
        public segtree right;
        public int[] val;

        public segtree(int[] nums, int l, int r, boolean gc) {
            if (l == r) {
                val = new int[]{nums[l], 1};
                return;
            }
            gcd = gc;
            left = new segtree(nums, l, (l + r) / 2, gc);
            right = new segtree(nums, (l + r) / 2 + 1, r, gc);
            val = comb(left.val, right.val);
        }

        public int[] get(int l, int r, int gL, int gR) {

            if (gL == l && gR == r) {
                return val;
            }
            int mid = (gL + gR)/2;
            int[] ret = new int[]{};
            if(l <= mid){
                ret = left.get(l, Math.min(r, mid), gL, mid);
            }
            if(r >= mid+1){
                int[] rr = right.get(Math.max(l, mid+1), r, mid+1, gR);
                ret = ret.length == 0 ? rr : comb(rr, ret);
            }
            return ret;
        }

        private int[] comb(int[] a, int[] b) { //associative
            if (gcd) {
                return new int[]{gcd(a[0], b[0])};
            }
            if (a[0] == b[0]) {
                return new int[]{a[0], a[1] + b[1]};
            } else {
                return a[0] < b[0] ? a : b;
            }
        }

        private int gcd(int a, int b) {
            return b == 0 ? a : gcd(b, a % b);
        }
    }
}
