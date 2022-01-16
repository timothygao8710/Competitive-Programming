// package atcoder;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        
        for(int i = 0; i<K; i++){
            N = dc(N) - ac(N);
        }
        pw.println(N);
        pw.close();
        br.close();
    }
    
    static int ac(int a){
        String t = a +"";
        char[] c = t.toCharArray();
        Arrays.sort(c);
        return Integer.parseInt(new String(c));
    }
    static int dc(int a){
        String t = a +"";
        char[] c = t.toCharArray();
        Arrays.sort(c);
        for(int i = 0; i<c.length/2; i++){
            char j = c[i];
            c[i] = c[c.length-1-i];
            c[c.length-1-i] = j;
        }
        return Integer.parseInt(new String(c));
    }
}
