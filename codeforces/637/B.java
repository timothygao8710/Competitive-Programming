
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
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
        String[] strs = new String[N];
        for(int i = 0; i<N; i++){
            strs[i] = br.readLine();
        }
        Set<String> vis = new HashSet();
        for(int i = strs.length-1; i>=0; i--){
            if(!vis.contains(strs[i])){
                System.out.println(strs[i]);
                vis.add(strs[i]);
            }
        }
    }
}

