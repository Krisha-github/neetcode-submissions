class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # mp={}
        # for x in nums:
        #     mp[x]=mp.get(x,0)+1

        num_set=set(nums)

        longest=0



        for x in num_set:
            #check if x is the starting no of the sequence:
            if x-1 not in num_set:
                curr=1
                while(x+1 in num_set):
                    curr+=1
                    
                    x=x+1
                longest=max(longest,curr)    
        return longest            

