#include <ctype.h>
#include <stdio.h>

#include "stack.h"

unsigned short check_priority(char chChar) {
    switch (chChar) {
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
        case '%':
            return 2;
            break;
        default:
            return 3;
            break;
    }
}

void intopos(char* pchExpr) {
    printf("infix expression = %s\n", pchExpr);
    for (size_t i = 0; pchExpr[i] != '\0'; i++) {
        if (isalnum(pchExpr[i])) {
            printf("%c", pchExpr[i]);
        } else if (pchExpr[i] == '(') {
            push(pchExpr[i]);
        } else if (pchExpr[i] == ')') {
            char chEx = peek();
            while (chEx != '(') {
                printf("%c", chEx);
                chEx = pop();
            }
        } else {
            int p1 = check_priority(peek());
            int p2 = check_priority(pchExpr[i]);
            unsigned short k = isEmpty();
            char d;
            while (p1 >= p2 && k == 0) {
                d = pop();
                printf("%c", d);
                p1 = check_priority(peek());
                k = isEmpty();
            }
            push(pchExpr[i]);

            // k = isEmpty();
            // while (k == 0) {
            //     d = pop();
            //     printf("%c", d);
            //     k = isEmpty();
            // }
        }
    }
}

int main() {
    intopos("(a-b)");
    while (!isEmpty()) {
        char a = pop();
        printf("%c", a);
    }
}
