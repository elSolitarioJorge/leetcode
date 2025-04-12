MAPPING = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ans = []
        n = len(digits)
        if n == 0:
            return ans
        path = [''] * n
        def dfs(i):
            if i == n:
                ans.append(''.join(path))
                return
            for c in MAPPING[int(digits[i])]:
                path[i] = c
                dfs(i + 1)
        dfs(0)
        return ans
    
    