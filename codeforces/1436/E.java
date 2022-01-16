
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E678 {
    //Solution Notes:
    /*
    First we notice the similarities "mex" has with "min". Particularly, once there exists a solution, any solution larger than it will not matter.
    Additionally, if we have reached X then all 1...X-1 must be valid
    So, this leads to an idea of iterating X from 1 - N
    
    How can be tell if a particular X is valid? Well, there must exist some segment that contains 1..X-1 but not X itself. We can do this by dividing up the array
    at indices where X occurs, then only checking the in-between segments(considering in search by modifying its parameters). 
    
    In order to do this, we use offline processing. If we iterate from left to right, we can keep the most recent occurance of each number,
    which can then be queried using a min SegTree. The generalization of this is implicit offline processing(even more generalized is precomputation) when the 
    queries are independent(or can be made so).
    */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);

        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] nums = new int[N];
        boolean ec = true;
        SegTree occs = new SegTree(N+1);
        int[] last = new int[N+2];
        boolean[] valid = new boolean[N+2];
        Arrays.fill(last, -1);
        for(int i = 0; i<N; i++){
            nums[i] = Integer.parseInt(st.nextToken());
            int back = occs.get(1, 1, nums[i]-1, 0, N);
            valid[nums[i]] = valid[nums[i]] || last[nums[i]] < back; //autoconsiders 1
            last[nums[i]] = i;
            if(nums[i] != 1) ec = false;
            occs.update(1, nums[i], i, 0, N);
        }
        int ret = N+2;
        //remember to check last....nums.length-1
        for(int i = 1; i<=N+1; i++){
            valid[i] = valid[i] || (last[i] < occs.get(1, 1, i-1, 0, N));
            if(!valid[i]){
                ret = i;
                break;
            }
        }
        pw.println(ec ? 1 : ret);
        pw.close();
        br.close();
    }
    
    static class SegTree {
        
        public int[] nodes;
        public int NEG = 1000042069;
        //Special trick: including 42069 in your code gurantees AC on CF
        
        public SegTree(int N) {
            nodes = new int[4 * N];
            Arrays.fill(nodes, -1);
        }
        
        public int get(int gI, int l, int r, int gL, int gR) {
            if (l > r) {
                return NEG;
            }
            if (gL == l && gR == r) {
                return nodes[gI];
            }
            int mid = (gR + gL) / 2;
            return Math.min(
                    get(2 * gI, l, Math.min(r, mid), gL, mid),
                    get(2 * gI + 1, Math.max(mid + 1, l), r, mid + 1, gR)
            );
        }
        
        public int update(int gI, int idx, int val, int gL, int gR) {
            if (idx < gL || idx > gR) {
                return nodes[gI];
            }
            if (gL == gR) {
                nodes[gI] = val;
            } else {
                nodes[gI] = Math.min(
                        update(2 * gI, idx, val, gL, (gL + gR) / 2),
                        update(2 * gI + 1, idx, val, (gL + gR) / 2 + 1, gR)
                );
            }
            return nodes[gI];
        }
    }
}
