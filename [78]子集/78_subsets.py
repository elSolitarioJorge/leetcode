class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        n = len(nums)
        def dfs(i):
            if i == n:
                ans.append(path.copy())
                return

            dfs(i + 1)

            path.append(nums[i])
            dfs(i + 1)
            path.pop()

        dfs(0)
        return ans
    
    