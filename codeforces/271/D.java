
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;

public class duels {
    static long mod = Long.MAX_VALUE;
    static long base = 9973;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        char[] str = br.readLine().toCharArray();
        int[] good = new int[26];
        String line = br.readLine();
        for (int i = 0; i < 26; i++) {
            good[i] = line.charAt(i) - '0';
            good[i] ^= 1;
        }
        int K = Integer.parseInt(br.readLine());
        Set<Long> all = new HashSet();
      
        for(int i = 0; i<str.length; i++){
            int temp = K;
            long hash = 0;
            for(int j = i; j>=0; j--){
                temp -= good[str[j]-'a'];
                if(temp < 0) break;
//                for(int k = j; k<=i; k++) System.out.print(str[k]);
//                System.out.println();
                hash = (hash*base)%mod + str[j];
                hash %= mod;
                all.add(hash);
            }
        }
        pw.println(all.size());
        pw.close();
        br.close();
    }
    
    
}
