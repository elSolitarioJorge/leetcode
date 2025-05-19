class Solution {
    private static final String[] MAPPING = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    public List<String> letterCombinations(String digits) {
        int n = digits.length();
        if (n == 0) {
            return List.of();
        }
        List<String> res = new ArrayList<>();
        char path[] = new char[n];
        dfs(0, res, path, digits.toCharArray());
        return res;
    }

    private void dfs(int i, List<String> res, char[] path, char[] digits) {
        if (i == digits.length) {
            res.add(new String(path));
            return;
        }

        String letters = MAPPING[digits[i] - '0'];
        for (char c : letters.toCharArray()) {
            path[i] = c;
            dfs(i + 1, res, path, digits);
        }
    }
}