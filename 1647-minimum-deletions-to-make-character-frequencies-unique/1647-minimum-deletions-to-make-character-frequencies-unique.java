class Solution {
     public int minDeletions(String s) {
        int[] arr = new int[26];
        for(char ch : s.toCharArray()) {
            arr[ch - 'a']++;
        }
        int count = 0;
        Set<Integer> set = new HashSet();
        for(int i = 0; i < 26; i++) {
            int frequency = arr[i];
            while(frequency > 0 && set.contains(frequency)) {
                frequency--;
                count++;
            }
            set.add(frequency);
        }
        return count; 
    }
}