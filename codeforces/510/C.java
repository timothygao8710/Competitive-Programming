
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author timothy
 */
public class FoxAndNames {
    public static void main(String[] args) throws IOException {
        System.out.println(solve());
    }
    //topological sort with characters
    
    public static String solve() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String ret = "";
        ArrayList<Integer>[] letters = new ArrayList[26];
        int[] inDeg = new int[26];
        for(int i = 0; i<26; i++){
            letters[i] = new ArrayList<Integer>();
        }
        int N = Integer.parseInt(br.readLine());
        String from = "";
        String to = br.readLine();
        in:
        for(int i = 1; i<N; i++){
            from = to;
            to = br.readLine();
            int stop = Math.min(to.length(), from.length());
            for(int j = 0; j<stop; j++){
                if(to.charAt(j) != from.charAt(j)){
                    letters[from.charAt(j) - 'a'].add(to.charAt(j) - 'a');
                    inDeg[to.charAt(j) - 'a']++;
                    continue in;
                }
            }
            if(from.length() > to.length()){
                return "Impossible";
            }
        }
        Queue<Integer> topo = new LinkedList();
        for(int i = 0; i<letters.length; i++){
            if(inDeg[i] == 0){
                topo.add(i);
            }
        }
        
        while(!topo.isEmpty()){
            int curr = topo.poll();
            ret += (char)(curr + 'a');
            for(int link : letters[curr]){
                inDeg[link]--;
                if(inDeg[link] == 0){
                    topo.add(link);
                }
            }
        }
        
        if(ret.length() == 26){
            return ret;
        }
        return "Impossible";
    }
}
