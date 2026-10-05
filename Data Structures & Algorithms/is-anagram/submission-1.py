class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        mp=[0]*26
        if(len(s)!=len(t)):
             return False
        for c in s:
            mp[ord(c)-ord('a')]+=1
        for c in t:
            mp[ord(c)-ord('a')]-=1    
        for freq in mp:
            if(freq!=0):
                    return False
        return True    
