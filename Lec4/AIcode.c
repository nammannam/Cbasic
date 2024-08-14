#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Định nghĩa cấu trúc stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Hàm tạo một stack mới với kích thước cố định
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Hàm kiểm tra xem stack có trống không
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Hàm đẩy một ký tự vào stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Hàm lấy ra một ký tự từ stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0'; // Giá trị không hợp lệ
}

// Hàm chuyển đổi chuỗi thành chuỗi đảo ngược sử dụng stack
void reverseString(char* input) {
    int length = strlen(input);
    struct Stack* stack = createStack(length);

    // Đẩy tất cả các ký tự từ chuỗi vào stack
    for (int i = 0; i < length; i++) {
        push(stack, input[i]);
    }

    // Lấy các ký tự từ stack để in ra và tạo chuỗi đảo ngược
    for (int i = 0; i < length; i++) {
        input[i] = pop(stack);
    }
}

int main() {
    char input[100];
    
    printf("Nhập chuỗi: ");
    scanf("%s", input);
    
    reverseString(input);
    
    printf("Chuỗi đảo ngược: %s\n", input);
    
    return 0;
}
