
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class virtualB {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        test:
        for(int t=0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            int[] nums = new int[N];
            int sum = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                nums[i] = Integer.parseInt(st.nextToken()); sum ^= nums[i];
            }
            Set<Integer> has = new HashSet(); has.add(0);
            int run = 0;
            for(int i = 0; i<N; i++){
                if(run == 0 && has.contains(sum)){
                    pw.println("YES"); continue test;
                }
                run ^= nums[i]; has.add(run);
            }
            pw.println("NO");
        }
        pw.close();
        br.close();
    }
}
