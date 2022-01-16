
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
public class beautifulmatrix {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        loop:
        for(int i = 0; i<5; i++){
            String curr = br.readLine();
            for(int j = 0; j<curr.length(); j+=2){
                if(curr.charAt(j) == '1'){
                    System.out.println(Math.abs(j - 4)/2 + Math.abs(i - 2));
                    break loop;
                }
            }
            System.out.println();
        }
    }
}
