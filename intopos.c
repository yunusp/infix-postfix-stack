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
            int iPr1 = check_priority(peek());
            int iPr2 = check_priority(pchExpr[i]);
            unsigned short k = isEmpty();
            char d;
            while (iPr1 >= iPr2 && k == 0) {
                d = pop();
                printf("%c", d);
                iPr1 = check_priority(peek());
                k = isEmpty();
            }
            push(pchExpr[i]);
        }
    }
}

int main() {
    intopos("(a+b)");
    while (!isEmpty()) {
        char a = pop();
        printf("%c", a);
    }
}
