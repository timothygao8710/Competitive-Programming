// package contest;

import java.io.*;
import java.util.*;

public class taemb {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
     
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); int t = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        List<int[]> edges = new ArrayList<>();
        int[] nums = new int[t+2];
        nums[0] = 1;
        
        st = new StringTokenizer(br.readLine());
        for(int i =1; i<=t; i++){
            nums[i] = Integer.parseInt(st.nextToken());
        }
        int[] suf = new int[nums.length];
        for(int i = t; i>=0; i--){
            suf[i] = suf[i+1] + Math.max(0, nums[i] - nums[i+1]);
        }
        int cur = 1;
        for(int i = 0; i<=t; i++){ //consider 0
            if(nums[i] == 0 && nums[i+1] != 0){
                k = -1; break;
            }

           int next = cur + nums[i];
            if(suf[i] < k){
                int diff = Math.min(nums[i] - 1, k - suf[i+1]); k-=diff;
//                System.out.println(diff);
                int start = cur;
                cur += diff;
                for(int j = 0; j<nums[i+1]; j++, next++){
                    edges.add(new int[]{cur, next});
                    if(cur - start < nums[i]-1) cur++;
                }
                cur++;
                continue;
            }
            
            if(nums[i] >= nums[i+1]){
                int diff = nums[i] - nums[i+1]; k-=diff;
                cur += diff;
                for(int j = 0; j<nums[i+1]; j++, next++, cur++){
                    edges.add(new int[]{cur, next});
                }
            }else{
                for(int j = 0; j<nums[i]; j++, next++, cur++){
                    edges.add(new int[]{cur, next});
                }
                cur--;
                for(int j = 0; j<nums[i+1] - nums[i]; j++, next++){
                    edges.add(new int[]{cur, next});
                }
                cur++;
            }
        }
        if(k!= 0){
            pw.println(-1);
        }else{
            pw.println(n);
            for(int[] i : edges){
                pw.println((i[0]) + " "  + (i[1]));
            }
        }
        
        pw.close();
        br.close();
    }
}
