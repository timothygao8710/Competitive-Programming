
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

public class virtual {

    static int[][] dirs = new int[][]{
        {1, 0}, {1,1}, {0, 1}, {-1, 1}, {-1, 0}, {-1,-1}, {0, -1}, {1, -1}
    };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        for(int i= 0; i<T; i++){
            int N = Integer.parseInt(br.readLine());
            pw.println(N);
            for(int j = 1; j<=N; j++){
                pw.print(j + " ");
            }
            pw.println();
        }
        pw.close();
        br.close();
    }
}