
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * - Long/int - Draw stuff - Use comments - Drink Water - Reread Problem
 *
 * - package/pw.close
 *
 * @author timothy
 */
public class randoms {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        long C = 9973;
        var mod = (long)(1e9+7);
        
        long[] pows = new long[10000000];
        pows[0] = 1;
        for(int i = 1; i<pows.length; i++){
            pows[i] = (pows[i-1]*C)%mod;
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0;i<N; i++){            
            String next = st.nextToken();
            int l = 0;
            
            int len = Math.min(next.length(), sb.length());            
            long a = 0;
            long b = 0;
            
            for(int j = 0; j<len; j++){
                a = a*C + sb.charAt(sb.length()-1-j);
                a %= mod;
                
                b += pows[j]*next.charAt(j);
                b %= mod;
                if(a == b) l = j+1;
            }
            sb.append(next.substring(l));
        }
        
        System.out.println(sb);
    }
}

