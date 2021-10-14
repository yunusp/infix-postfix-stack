#include <stdlib.h>
#pragma once
#define MAX_CAPACITY 50

static char chStack[MAX_CAPACITY];
static int iTop = -1;

void push(char chChar);
char pop();
char peek();

unsigned short isEmpty() {
    return (iTop == -1);
}
unsigned short isFull() {
    return (iTop == (MAX_CAPACITY - 1));
}

void push(char chChar) {
    if(isFull()) return;
    chStack[++iTop] = chChar;
}
char pop(){
    if(isEmpty()) return NULL;
    return chStack[iTop--];
}
char peek(){
    if(isEmpty()) return NULL;
    return chStack[iTop];
}
