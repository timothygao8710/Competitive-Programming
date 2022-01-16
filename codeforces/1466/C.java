
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i<T; i++){
            int ret = 0;
            char[] chars = br.readLine().toCharArray();
            for(int j = 1; j<chars.length; j++){
                if(chars[j-1] == chars[j] || (j-2 >= 0 && chars[j] == chars[j-2])){
                    ret++;
                    chars[j] = '~';
                }
            }
            pw.println(ret);
        }
        
        
        pw.close();
        br.close();
    }
}