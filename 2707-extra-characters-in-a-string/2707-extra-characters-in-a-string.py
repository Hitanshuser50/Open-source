from collections import defaultdict

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
   
        n = len(s)
        
        
        word_dict = defaultdict(list)
        
      
        for word in dictionary:
            word_dict[word[0]].append(word)
            
        # Initialize a list 'result' of length 'n+1' to store minimum extra characters at each position
        result = [0] * (n + 1)
        
        # Iterate through the string 's' from right to left
        for i in range(n - 1, -1, -1):
            # Initialize the current position in 'result' with one more extra character than the next position
            result[i] = result[i + 1] + 1
            
            # Check if the current character 's[i]' is found in 'word_dict'
            if s[i] in word_dict:
                # Iterate through the words that start with 's[i]'
                for word in word_dict[s[i]]:
                    # Check if the substring starting at position 'i' matches the current word
                    if s[i:i + len(word)] == word:
                        # Update 'result[i]' with the minimum of its current value and 'result[i + len(word)]'
                        result[i] = min(result[i], result[i + len(word)])
                        
  
        return result[0]