
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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
public class capflint {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i<N; i++){
            int num = Integer.parseInt(br.readLine());
            if(num > 30){
                System.out.println("YES");
                if(num - 30 == 6){
                    System.out.println(6 + " " + 5 + " " + 10 + " " + 15);
                }else if(num - 30 == 10){
                    System.out.println(6 + " " + 14 + " " + 15 + " " + 5);
                }else if(num - 30 == 14){
                    System.out.println(6 + " " + 10 + " " + 7 + " " + 21);
                }else{
                    System.out.println( 6 + " " + 10 + " " + 14 + " " + (num-30));
                }
            }else{
                System.out.println("NO");
            }
        }
    }
}
