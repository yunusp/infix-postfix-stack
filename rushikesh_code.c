#include <ctype.h>
#include <stdio.h>
#define SIZE 20

int stk[SIZE];
int top = -1;

int isempty() {
    if (top == -1)
        return (1);
    else
        return (0);
}
int isfull() {
    if (top == SIZE - 1)

        return (1);
    else
        return (0);
}
void push(char d) {
    int k;
    k = isfull();
    if (k == 0) {
        top++;
        stk[top] = d;

    }
     else
        printf("\n Stack is full");
}
char pop() 
{
    char d;
    d = stk[top];
    top = top - 1;
    return (d);
}

int priority(char d)
 {
    if (d == '(')
        return (0);
    if ((d == '+') || (d == '-'))
        return (1);
    if ((d == '*') || (d == '/') || (d == '%'))
        return (2);
    else
        return (3);
}

int main()
 {
    int k, i, p1, p2;
    char d, s[20];
    printf("\n Enter infix expression");
    scanf("%s", s);
    printf("\n postfix is: \n");

    for (i = 0; s[i] != '\0'; i++)
     {
        if (isalnum(s[i]))
            printf("%c", s[i]);
        else if (s[i] == '(')
            push(s[i]);
        else if (s[i] == ')') 
        {
            d = pop();
            while (d != '(') {
                printf("%c", d);
                d = pop();
            }
        } else
         {
            p1 = priority(stk[top]);
            p2 = priority(s[i]);
            k = isempty();
            while (p1 >= p2 && k == 0) 
            {
                d = pop();
                printf("%c", d);
                p1 = priority(stk[top]);
                k = isempty();
            }
            push(s[i]);
        }
    } // end for for loop
    k = isempty();
    while (k == 0) 
    {
        d = pop();
        printf("%c", d);
        k = isempty();
    }
}
