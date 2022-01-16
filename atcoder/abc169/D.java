
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// package divisibility;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long N = Long.parseLong(br.readLine());
        int ret = 0;
        for(long i = 2; i*i <= N; i++){
            int curr = 0;
            while(N%i == 0){
                N /= i;
                curr++;
            }
            //1+2+3... = curr
            //(1+N)(N)/2 = curr
            ret += find(curr);
        }
        if(N > 1) ret++;
        System.out.println(ret);
    }
    static int find(int num){
        int l = 0;
        int r = num;
        while(l < r){
            int mid = (l+r+1)/2;
            if(((mid+1)*(mid)/2 <= num)){
                l = mid;
            }else{
                r = mid-1;
            }
        }
        return l;
    }
}
