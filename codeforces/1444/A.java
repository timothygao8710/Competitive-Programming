
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class randoms {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            if(a%b != 0){
                pw.println(a); continue;
            }
            long temp = a;
            long min = Long.MAX_VALUE;
            for(int i = 2; i*i <= b; i++)
            {
                if(b%i != 0) continue;
                long cur = 1;
                while(a%i == 0){
                    cur *= i;
                    a /= i;
                    if(b%i == 0){
                        cur /= i;
                        b /= i;
                    }
                }
                min = Math.min(min, cur*i);
            }
            long c = 1;
            if(a%b != 0) System.out.println("NAINSDFHWIRKLKLKKKLKLLKLKUHSDLFKSHDFLKWJFHDSL");
            while(b != 1 && a%b == 0){
                a /= b;
                c *= b;
            }
            if(c != 1) min = Math.min(min, c);
            pw.println(temp/min);
        }
        
        pw.close();
        br.close();
    }
}
/*
857754240051582063 933416507
*/