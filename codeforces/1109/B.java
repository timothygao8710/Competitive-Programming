
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class duels {
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        String line = br.readLine();
        boolean can = false;
        for(int i = 1; i<line.length()/2; i++){
            if(line.charAt(i) != line.charAt(i-1)) can = true;
        }
        
        if(can){
                String res = "";
                l:
                for(int i = 1; i<line.length(); i++){
                    res = line.substring(i, line.length()) + line.substring(0, i);
                    if(res.equals(line)) continue;
                    for(int j = 0; j<res.length(); j++){
                        if(res.charAt(j) != res.charAt(res.length()-1-j)) continue l;
                    }
                    can = false;
                    break;
                }
                pw.println(!can ? 1 : 2);
        }else{
            pw.println("Impossible");
        }
        
        pw.close();
        br.close();
    }
}
