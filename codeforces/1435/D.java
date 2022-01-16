
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        
        int N = Integer.parseInt(br.readLine());
        int idx = 0;
        int[] end = new int[N+1];
        int[] ret = new int[N];
        TreeMap<Integer, Deque<Integer>> mp = new TreeMap();
        Deque<Integer> cur = new ArrayDeque();
        boolean ok = true;
        for(int i = 0; i<2*N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            char c; c = st.nextToken().charAt(0);
            if(c == '+'){
                cur.add(idx); idx++;
            }else{
                int val = Integer.parseInt(st.nextToken());
                while(!mp.isEmpty() && mp.firstKey() < val){
                    Deque<Integer> other = mp.floorEntry(val).getValue();
                    if(other.size() > cur.size()){
                        for(int j : cur) other.add(j);
                        cur = other;
                    }else{
                        for(int j : other) cur.add(j);
                    }
                    mp.remove(mp.floorKey(val));
                }
                if(cur.isEmpty()){
                    ok = false;
                    pw.println("NO"); break; 
                }
                ret[cur.poll()] = val;
                mp.put(val, cur); cur = new ArrayDeque();
            }
        }
        if(ok){
            pw.println("YES");
            for(int i : ret) pw.print(i + " ");
        }
        pw.close();
        br.close();
    }
    
    
}
