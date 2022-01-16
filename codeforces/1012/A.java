
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        long[] nums = new long[2*N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<2*N; i++) nums[i] = Integer.parseInt(st.nextToken());
        Arrays.sort(nums);
        long best = (nums[N-1]-nums[0])*(nums[2*N-1]-nums[N]);
        for(int i= 1; i+N-1<2*N-1; i++){
            best = Math.min(best, (nums[2*N-1] - nums[0])*(nums[i+N-1]-nums[i]));
        }
        pw.println(best);
        pw.close();
    }
}
