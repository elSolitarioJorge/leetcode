int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = -1;
    for (int i = 0; i < tokensSize; i++) {
        char* token = tokens[i];
        if (strlen(token) > 1 || token[0] >= '0') {
            stack[++top] = atoi(token);
        } else {
            int num2 = stack[top--];
            int num1 = stack[top--];
            switch (token[0]) {
                case '+':
                    stack[++top] = num1 + num2;
                    break;
                case '-':
                    stack[++top] = num1 - num2;
                    break;
                case '*':
                    stack[++top] = num1 * num2;
                    break;
                case '/':
                    stack[++top] = num1 / num2;
                    break;
            }
        }
    }
    return stack[top];
}
    
    