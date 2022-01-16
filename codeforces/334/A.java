
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author timothy
 */
public class candies {
    //rainbow
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int left = 1;
        int right = N*N;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N/2; j++, left++, right--){
                System.out.print(left + " " + right + " ");
            }
            System.out.println();
        }
    }
}
