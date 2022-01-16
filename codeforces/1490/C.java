import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
            
        long max = (long)(1e12);
        
        Set<Long> c = new HashSet();
        
        for(long i = 1; i*i*i <= max; i++){
            c.add(i*i*i);
        }

        int T = Integer.parseInt(br.readLine());
        yeet:
        for(int t = 0; t<T; t++){
            long x = Long.parseLong(br.readLine());
            for(long i : c){
                if(c.contains(x - i)){
                    pw.println("yes");
                    continue yeet;
                }
            }
            pw.println("NO");
        }
        
        
        pw.close();
        br.close();
    }
}
