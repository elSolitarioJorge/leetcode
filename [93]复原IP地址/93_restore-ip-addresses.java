class Solution {
    private List<String> res = new ArrayList<>();
    private String s;
    private int pointNum = 3;

    public List<String> restoreIpAddresses(String s) {
        this.s = s;
        dfs(0);
        return res;
    }


    private void dfs(int start) {
        if (pointNum == 0) {
            if (isValid(start, s.length() - 1)) {
                res.add(s);
            }
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isValid(start, i)) {
                s = s.substring(0, i + 1) + "." + s.substring(i + 1);
                pointNum--;
                dfs(i + 2);
                s = s.substring(0, i + 1) + s.substring(i + 2);
                pointNum++;
            } else {
                break;
            }
        }
    }

    private boolean isValid(int left, int right) {
        if (left > right) {
            return false;
        }
        if (s.charAt(left) == '0' && left != right) {
            return false;
        }
        int num = 0;
        for (int i = left; i <= right; i++) {
            num = num * 10 + s.charAt(i) - '0';
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
}

class Solution {
    private List<String> res = new ArrayList<>();
    private StringBuilder s;
    private int pointNum = 3;

    public List<String> restoreIpAddresses(String s) {
        this.s = new StringBuilder(s);
        dfs(0);
        return res;
    }


    private void dfs(int start) {
        if (pointNum == 0) {
            if (isValid(start, s.length() - 1)) {
                res.add(s.toString());
            }
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isValid(start, i)) {
                s.insert(i + 1, ".");
                pointNum--;
                dfs(i + 2);
                s.deleteCharAt(i + 1);
                pointNum++;
            } else {
                break;
            }
        }
    }

    private boolean isValid(int left, int right) {
        if (left > right) {
            return false;
        }
        if (s.charAt(left) == '0' && left != right) {
            return false;
        }
        int num = 0;
        for (int i = left; i <= right; i++) {
            num = num * 10 + s.charAt(i) - '0';
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
}

class Solution {
    private List<String> res = new ArrayList<>();
    private StringBuilder s;
    private int pointNum = 3;

    public List<String> restoreIpAddresses(String s) {
        if (s.length() < 4 || s.length() > 12) {
            return res;
        }
        this.s = new StringBuilder(s);
        dfs(0);
        return res;
    }


    private void dfs(int start) {
        if (pointNum == 0) {
            if (isValid(start, s.length() - 1)) {
                res.add(s.toString());
            }
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isValid(start, i)) {
                s.insert(i + 1, ".");
                pointNum--;
                dfs(i + 2);
                s.deleteCharAt(i + 1);
                pointNum++;
            } else {
                break;
            }
        }
    }

    private boolean isValid(int left, int right) {
        if (left > right) {
            return false;
        }
        if (s.charAt(left) == '0' && left != right) {
            return false;
        }
        int num = 0;
        for (int i = left; i <= right; i++) {
            num = num * 10 + s.charAt(i) - '0';
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
}
    
    