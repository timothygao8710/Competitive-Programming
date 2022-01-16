
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * - Long/int - Draw stuff - Use comments - Drink Water - Reread Problem
 *
 * - package/pw.close
 *
 * @author timothy
 */
public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        String str = br.readLine();

        Map<Character, long[]> mp = new HashMap(); //see the lc problem on counting unique subs.
        long[] lens = new long[N + 1];
        lens[0] = 1;
        for (int i = 0; i <N; i++) {
            long[] last = mp.get(str.charAt(i)); //we are subtracting the "addings"
            mp.put(str.charAt(i), lens.clone());
            for(int j = N; j>=1; j--){
                lens[j] += lens[j-1];
                if(last != null){
                    lens[j] -= last[j-1];
                }
            }
        }
//        System.out.println(Arrays.toString(lens));
        long ret = 0;
        for (int i = N; i >= 0; i--) {
            ret += Math.min(lens[i], K) * (N - i);
            K -= Math.min(lens[i], K);
            if (K == 0) {
                break;
            }
        }
        System.out.println(K == 0 ? ret : -1);
    }
}

