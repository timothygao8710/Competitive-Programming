
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());
            int[] nums = new int[N];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }
            solve(nums, K);
        }
        pw.close();
        br.close();
    }

    static void solve(int[] nums, int K) {
        int odds = 0;
        for (int i : nums) {
            if (i % 2 == 1) {
                odds++;
            }
        }
        if (odds < K || (odds - K) % 2 == 1) {
            System.out.println("NO");
            return;
        }
        System.out.println("YES");
        for (int i = 0; i < nums.length && K > 1; i++) {
            if (nums[i] % 2 == 1) {
                System.out.print((i + 1) + " "); K--;
            }
        }
        System.out.print(nums.length);
        System.out.println();
    }
}
