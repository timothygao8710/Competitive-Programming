
import java.io.*;
import java.util.*;

public class randoms {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        trie bt = new trie();
        for(int i= 0; i<N; i++){
            bt.insert(Integer.parseInt(st.nextToken()), 30);
        }
        pw.println(N - dfs(bt));
        pw.close();
        br.close();
    }
    
    static int dfs(trie c){
        if(c.size == 1) return 1;
        if(c.c[0] == null) return dfs(c.c[1]);
        if(c.c[1] == null) return dfs(c.c[0]);
        return Math.max(dfs(c.c[0]), dfs(c.c[1]))+1;
    }
    
    static class trie{
        public trie[] c = new trie[2];
        public int size = 0;
        public void insert(int num, int shift){
            size++;
            if(shift == -1) { //remember this shift is the next bit after this one
                return;
            }
            int bit = (num >> shift)&1;
            if(c[bit] == null) c[bit] = new trie();
            c[bit].insert(num, shift-1);
        }
    }
}
