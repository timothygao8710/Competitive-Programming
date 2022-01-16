
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author timothy
 */
public class generalarrival {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int[] soldiers = new int[N];
        int max = 0;
        int min = 1001;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i= 0; i<N; i++){
            soldiers[i] = Integer.parseInt(st.nextToken());
            max = Math.max(max, soldiers[i]);
            min = Math.min(min, soldiers[i]);
        }
        int mI; //minI
        for(mI = N-1; mI>=0; mI--){
            if(soldiers[mI] == min){
                break;
            }
        }
        
        int sI; //super
        for(sI = 0; sI < N; sI++){
            if(soldiers[sI] == max){
                break;
            }
        }
        if(mI < sI){
            System.out.println((sI) + (N - 1 - mI) - 1); 
        }else{
            System.out.println((sI) + (N - 1 - mI));
        }
    }
}
