class Solution {
    public boolean validMountainArray(int[] arr) {
        int len = arr.length;
        int left = 0;
        int right = len - 1;
        while (left + 1 < len && arr[left] < arr[left + 1]) {
            left++;
        }
        while (right > 0 && arr[right - 1] > arr[right]){
            right--;
        }
        return left > 0 && right < len - 1 && left == right;
    }
}
    
    