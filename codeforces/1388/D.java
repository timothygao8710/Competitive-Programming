
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * -Take it slow, think-
 * Watch out for:
 * - Long/Int
 * - Edge cases (make test case)
 * - Unexpected behavior?
 *
 * @author timothy
 */
public class treasure {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        long[] a = new long[N+1];
        int[] b = new int[N+1];
        int[] inDeg = new int[N+1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=N; i++){
            a[i] = Long.parseLong(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=N; i++){
            int to = Integer.parseInt(st.nextToken());
            b[i] = to;
            if(to != -1) inDeg[to]++;
        }
        
        long ret = 0;
        Queue<Integer> topo = new LinkedList();
        for(int i = 1; i<=N; i++){
            if(inDeg[i] == 0){
                topo.add(i);
            }
        }
        List<Integer> order = new ArrayList();
        List<Integer> bads = new LinkedList();
        while(!topo.isEmpty()){
            int curr = topo.poll();
            ret += a[curr];
            if(a[curr] < 0){
                bads.add(0, curr);
                a[curr] = 0;
            }else{
                order.add(curr);
            }
            if(b[curr] == -1){
                continue;
            }
            a[b[curr]] += a[curr];
            inDeg[b[curr]]--;
            if(inDeg[b[curr]] == 0){
                topo.add(b[curr]);
            }
        }
        for(int i : bads){
            order.add(i);
        }
        System.out.println(ret);
        for(int i : order){
            System.out.print(i + " ");
        }
    }
}
