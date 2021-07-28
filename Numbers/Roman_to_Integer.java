class Solution {
    public int romanToInt(String s) {
        Map<String,Integer> map = new HashMap<String,Integer>();
        map.put("I",1);
        map.put("V",5);
        map.put("X",10);
        map.put("L",50);
        map.put("C",100);
        map.put("D",500);
        map.put("M",1000);
        int sum = 0;
        for (int i = 0 ; i < s.length()-1; i++){
            int temp = map.get(s.substring(i,i+1));
            int next = map.get(s.substring(i+1,i+2));
            if (temp < next){
                sum += (next-temp);
            }
            else{
                sum += temp;
            }
        }
        sum += map.get(s.substring(s.length()-1));
        return sum;
    }
}

// Example Test cases
// Input: s = "IV"
// Output: 4
//
//
// Input: s = "IX"
// Output: 9
