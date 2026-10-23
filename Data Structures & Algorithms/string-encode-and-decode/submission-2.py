class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded=[]
        for s in strs:
            encoded.append(str(len(s)))
            encoded.append("#")
            encoded.append(s)
        return "".join(encoded)    

    def decode(self, s: str) -> List[str]:
        decoded=[]
        i=0
        n=len(s)

        while i<n:
            j=s.find('#',i) #delimiter index
            slen=int(s[i:j])
            start=j+1
            end=start+slen
            decoded.append(s[start:end]) 
            i=end
        return decoded      