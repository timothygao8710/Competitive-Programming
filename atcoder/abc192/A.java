// package atcoder;

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        int N = Integer.parseInt(br.readLine());
        pw.println(100 - N%100);
        
        pw.close();
        br.close();
    }
}
