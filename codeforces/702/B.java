
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        Map<Integer, Integer> nums = new HashMap<>();
        long ret = 0;
        for(int i = 0; i<N; i++){
            int c = Integer.parseInt(st.nextToken());
            for(int j = 0; j<32; j++){
                int d = 1<<j;
                if(nums.containsKey(d - c)) ret += nums.get(d-c);
            }
            if(nums.get(c) == null) nums.put(c, 0);
            nums.put(c, nums.get(c) + 1);
        }
        pw.println(ret);
        pw.close();
    }
}
