// package atcoder;

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        String s = br.readLine();
        boolean good = true;
        for(int i = 0; good && i<s.length(); i++){
            if(i % 2 == 0){
                good = good && s.charAt(i) >= 'a' && s.charAt(i) <= 'z';
            }else{
                good = good && s.charAt(i) >= 'A' && s.charAt(i) <= 'Z';
            }
        }
        pw.println(good ? "Yes" : "No");
        pw.close();
        br.close();
    }
}
