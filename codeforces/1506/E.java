
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            HashMap<Integer, Integer> mp = new HashMap();
            StringTokenizer st = new StringTokenizer(br.readLine());
            TreeSet<Integer> max = new TreeSet<>();
            TreeSet<Integer> min = new TreeSet<>();
            int[] nums = new int[N];
            for (int i = 0; i < N; i++) {
                max.add(i + 1);
                min.add(i + 1);
                nums[i] = Integer.parseInt(st.nextToken());
            }
            int[] mina = new int[N];
            int[] maxa = new int[N];
            for(int i = 0; i<N; i++){
                if(i != 0 && nums[i] == nums[i-1]){
                    mina[i] = min.ceiling(1);
                    maxa[i] = max.floor(nums[i]);
                }else{
                    mina[i] = maxa[i] = nums[i];
                }
                min.remove(mina[i]); max.remove(maxa[i]);
            }
            for(int i : mina) pw.print(i + " ");
            pw.println();
            for(int i : maxa) pw.print(i +" ");
            pw.println();
        }
        pw.close();
        br.close();
    }
}
