
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        
        for(int t = 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()); int b = Integer.parseInt(st.nextToken()); int c = Integer.parseInt(st.nextToken());
            long sum = a+b+c;
            int min = Math.min(a, Math.min(b, c));
            if(min*6 < sum - 3*min || sum%9 != 0){
                pw.println("no");
            }else{
                pw.println("yes");
            }
               
        }
        br.close();
        pw.close();
    }
}
