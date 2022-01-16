
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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
public class KitaharaHarukiGift {
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(System.out.toString())));
        
        int N = Integer.parseInt(br.readLine());

        //each two is cancelled by another 2 or 2 ones
        int one = 0;
        int two = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<N; i++){
            if(Integer.parseInt(st.nextToken()) == 200){
                two++;
            }else{
                one++;
            }
        }
        
        if(one % 2 == 1 || (two%2 == 1 && one == 0)){
            System.out.println("NO");
        }else{
            System.out.println("YES");
        }
        
//        pw.close();
        br.close();
    }
}
