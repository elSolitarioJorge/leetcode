int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;                        // 初始化层数计数器
    *returnColumnSizes = NULL;              // 初始化列宽数组指针

    if(root == NULL) return NULL;          // 处理空树直接返回

    int** ans = (int**)malloc(2000 * sizeof(int*));       // 预分配结果数组
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));// 预分配列宽数组

    struct TreeNode* queue[2000];          // 固定大小数组模拟队列
    int front = 0, rear = 0;               // 队列头尾指针
    queue[rear++] = root;                  // 根节点入队

    // 分层处理循环
    while(front != rear) {
        int levelSize = rear - front;      // 计算当前层节点数
        ans[*returnSize] = (int*)malloc(levelSize * sizeof(int)); // 分配当前层存储空间

        // 当前层节点处理循环
        for(int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front + i];  // 按序访问当前层节点
            ans[*returnSize][i] = node->val;           // 存储节点值

            // 子节点入队（下一层处理）
            if(node->left) queue[rear++] = node->left;
            if(node->right) queue[rear++] = node->right;
        }

        (*returnColumnSizes)[*returnSize] = levelSize; // 记录当前层节点数
        front += levelSize;               // 移动队列头指针到下一层起始位置
        (*returnSize)++;                   // 层数自增
    }

    return ans;
}
    
    