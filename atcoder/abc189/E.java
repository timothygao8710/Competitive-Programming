
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int[][] ps = new int[N][2];
        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            ps[i] = new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
        }
        int M = Integer.parseInt(br.readLine());
        int[][] ops = new int[M][2];
        for(int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            ops[i][0] = Integer.parseInt(st.nextToken());
            if(ops[i][0] >= 3) ops[i][1] = Integer.parseInt(st.nextToken());
        }
        
        int Q = Integer.parseInt(br.readLine());
        int[][] qs = new int[Q][2];
        for(int i =0; i<Q; i++){
            st = new StringTokenizer(br.readLine());
            qs[i] = new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())-1, i};
        }
        
        Arrays.sort(qs, (int[] a, int[] b) -> a[0] - b[0]);
        long[] ad = new long[2];
        int[] mult = {1,1};
        int x = 0;
        
        long[][] ret = new long[Q][2];
        
        int p = 0;
        for(int[] i : qs){
            while(p < i[0]){
                if(ops[p][0] == 1){
                    mult[x] *= -1;
                    ad[x] *= -1;
                    x = (x+1)%2;
                }else if(ops[p][0] == 2){
                    x = (x+1)%2;
                    mult[x] *= -1;
                    ad[x] *= -1;
                }else if(ops[p][0] == 3){
                    ad[x] *= -1;
                    ad[x] += 2*ops[p][1];
                    mult[x] *= -1;
                }else{
                    ad[x^1] *= -1;
                    ad[x^1] += 2*ops[p][1];
                    mult[x^1] *= -1;
                }
                p++;
            }
            
            ret[i[2]][0] = ad[x] + mult[x]*ps[i[1]][x];
            ret[i[2]][1] = ad[x^1] + mult[x^1]*ps[i[1]][x^1];
        }
        for(long[] i : ret){
            pw.println(i[0] + " " + i[1]);
        }
        pw.close();
        br.close();
    }
}
