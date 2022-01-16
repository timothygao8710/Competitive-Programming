
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class contest {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i<T; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int px = Integer.parseInt(st.nextToken());
            int py = Integer.parseInt(st.nextToken());
            
            int x = 0;
            int y = 0;
            
            String line = br.readLine();
            for(char c : line.toCharArray()){
                if(c == 'U'){
                    if(py > y) y++;
                }else if(c == 'D'){
                    if(py < y) y--;
                }
                if(c == 'L'){
                    if(px < x) x--;
                }
                if(c == 'R'){
                    if(px > x) x++;
                }
            }
            pw.println(px == x && py == y ? "YES" : "NO");
        }
        
        pw.close();
        br.close();
    }
}
