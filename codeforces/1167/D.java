
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

        int N = Integer.parseInt(br.readLine());
        char[] cs = br.readLine().toCharArray();
        int max = 0;
        int cur = 0;
        for(int i =0; i<N; i++){
            if(cs[i] == '(') {
                cur++;
            }else{
                cur--;
            }
            max = Math.max(max, cur);
        }
        for(int i= 0; i<N; i++){
            if(cs[i] == '(') {
                cur++;
            }
            if(cur <= max/2){
                pw.print(0);
            }else{
                pw.print(1);
            }
            if(cs[i] == ')'){
                cur--;
            }
        }
        pw.close();
        br.close();
    }
}
