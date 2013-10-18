
public class Solution {
    public int longestConsecutive(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int n = num.length;
        HashMap<Integer, Boolean> visit = new HashMap<Integer, Boolean>(n);
        for(int i = 0 ; i < n; i++)
            visit.put(new Integer(num[i]), new Boolean(false));
        Iterator<Integer> it = visit.keySet().iterator();
        Integer range1, range2, b;
        int len, max =1;
        while(it.hasNext()){
            range1 = it.next();
            if(visit.get(range1))
                continue;
            len = 1;
            range2 = range1;
            while(true){
                boolean flag = false;
                b = new Integer(range1.intValue() -1);
                if(visit.get(b) != null && !visit.get(b)){
                    visit.put(b, new Boolean(true));
                    len += 1;
                    range1 = b;
                    flag = true;
                }
                b = new Integer(range2.intValue() +1);
                if(visit.get(b) != null && !visit.get(b)){
                    visit.put(b, new Boolean(true));
                    len += 1;
                    range2 = b;
                    flag = true;
                }
                if(!flag)
                    break;
            }
            if(max < len)
                max = len;
        }
        return max;
    }
}
