import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
            
        int T = Integer.parseInt(br.readLine());
        
        for(int t = 0; t<T; t++){
            int N = Integer.parseInt(br.readLine());
            int[][] nums = new int[N][2];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i = 0; i<N; i++){
                nums[i][0] = Integer.parseInt(st.nextToken());
                nums[i][1] = i;
            }
            
            Arrays.sort(nums, (int[] a, int[] b) -> a[0] - b[0]);
            
            int r = 0;
            long sum = 0;
            List<Integer> ret = new ArrayList();
            for(int i = 0; i<N; i++){
                if(i == r){
                    sum += nums[i][0];
                    r++;
                }
                while(r < N && sum >= nums[r][0]){
                    sum += nums[r][0];
                    r++;
                }
                
                if(r == N){
                    ret.add(nums[i][1]);
                }
            }
            Collections.sort(ret);
            pw.println(ret.size());
            for(int i : ret){
                pw.print((i+1) + " ");
            }
            pw.println();
        }
        
        
        pw.close();
        br.close();
    }
}
/*
1
3
3 1 1
*/