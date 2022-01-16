
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;

public class virtual {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
           int N = Integer.parseInt(br.readLine());
           int[][] grid = new int[N][N];
           for(int i = 0; i<N; i++){
               String l = br.readLine();
               for(int j = 0; j<N; j++){
                   grid[i][j] = l.charAt(j) - '0';
               }
           }
           for(int i = 0; i<2; i++){
               ArrayList<int[]> ret = new ArrayList();
               if(grid[0][1] != i){
                   ret.add(new int[]{0, 1});
               }
               if(grid[1][0] != i){
                   ret.add(new int[]{1, 0});
               }
               if(grid[N-1][N-2] == i){
                   ret.add(new int[]{N-1, N-2});
               }
               if(grid[N-2][N-1] == i){
                   ret.add(new int[]{N-2, N-1});
               }
               if(ret.size() <= 2){
                   pw.println(ret.size());
                   for(int[] j : ret){
                       pw.println((j[0]+1) + " " + (j[1]+1));
                   }
                   break;
               }
           }
        }
        pw.close();
        br.close();
    }
}