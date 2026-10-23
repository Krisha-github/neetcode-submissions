from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        output = [1] * n

        # Pass 1: compute prefix products
        for i in range(1, n):
            output[i] = output[i - 1] * nums[i - 1]

        # Pass 2: multiply by running suffix products
        suffix = 1
        for i in range(n - 1, -1, -1):
            output[i] *= suffix
            suffix *= nums[i]

        return output