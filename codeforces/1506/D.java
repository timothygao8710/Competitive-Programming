
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            int N = Integer.parseInt(br.readLine());
            HashMap<Integer, Integer> mp = new HashMap();
            int max = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i= 0; i<N; i++){
                int c = Integer.parseInt(st.nextToken());
                mp.putIfAbsent(c,0);
                mp.put(c, mp.get(c)+1);
                max = Math.max(max, mp.get(c));
            }
            
            if(max >= N-max){
                pw.println(2*max - N);
            }else{
                pw.println(N%2);
            }
        }
        pw.close();
                br.close();
    }
}
