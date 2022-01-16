
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class duels {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        String line = br.readLine();
        int a = 0;
        //for a
        List<Integer> less = new ArrayList();
        List<Integer> more = new ArrayList();
        for(int i = 0; i<line.length(); i++){
            int c= line.charAt(i) - '0';
            if(i < 3){
                a += c;
                more.add(9 - c);
                less.add(c);
            }else{
                a -= c;
                less.add(9 - c);
                more.add(c);
            }
        }
       
        int i = 0;
        if(a < 0){
            Collections.sort(more, Collections.reverseOrder());
            for(; i<more.size() && a < 0; i++){
                a += more.get(i);
            }
        }else{
            Collections.sort(less, Collections.reverseOrder());
            for(; i<less.size() && a > 0; i++){
                a -= less.get(i);
            }
        }
        pw.println(i);
        pw.close();
    }
}
