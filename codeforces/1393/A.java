
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
public class qa {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i<T; i++){
            int num = Integer.parseInt(br.readLine());
            System.out.println(
            (int)((num/2)+0.5) + 1
            );
        }
    }
}
