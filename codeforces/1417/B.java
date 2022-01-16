
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken()); int num = Integer.parseInt(st.nextToken());
            Set<Integer> set = new HashSet();
            st = new StringTokenizer(br.readLine());
            for(int i =0 ; i<N; i++){
                int c = Integer.parseInt(st.nextToken());
                if(set.contains(num-c)){
                    pw.print(1 +" ");
                    if(c == num-c) set.remove(c);
                }else{
                    pw.print(0 + " ");
                    set.add(c);
                }
            }
            pw.println();
        }
        
        pw.close();
        br.close();
    }
}
