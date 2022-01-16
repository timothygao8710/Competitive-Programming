
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class virtual {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        for(int t= 0; t<T; t++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int min = Integer.MAX_VALUE;
            int neg = 0;
            int sum = 0;
            for(int i = 0; i<N; i++){
                st = new StringTokenizer(br.readLine()); 
                for(int j = 0; j<M; j++){
                    int a = Integer.parseInt(st.nextToken());
                    if(a <= 0){
                        neg++;
                    }
                    min = Math.min(min, Math.abs(a));
                    sum += Math.abs(a);
                }
            }
            if(neg % 2 == 0) min = 0;
            pw.println(sum - 2*min);
        }
        pw.close();
        br.close();
    }
}
/*

*/