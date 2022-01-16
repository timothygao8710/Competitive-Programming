
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());
        long l = Long.parseLong(st.nextToken());
        long r = Long.parseLong(st.nextToken());

        List<Long> all = new ArrayList<>();
        long c = 1;
        all.add(c);
        while (c <= r / a) {
//            System.out.println(c);
            c *= a;
            all.add(c);
        }
        List<Long> n = new ArrayList<>();
        for (long i : all) {
            c = 1;
            if (i <= r - c) {
                n.add(i + c);
            }
            while (c <= (r - i) / b) {
                c *= b;
                n.add(c + i);
            }
        }
        long ret = 0;
        TreeSet<Long> has = new TreeSet<>();
        has.addAll(n);
        
//        for(long i : has){
//            System.out.println(i);
//        }
//        
        long last = l-1;
        Long lp = l-1;
        while(true){
            ret = Math.max(ret, lp - last - 1);
            last = lp;
            if(has.ceiling(lp+1) == null) break;
            lp = has.ceiling(lp+1);
        }
        
        pw.println(Math.max(r - lp, ret));
        pw.close();
        br.close();
    }
}
