#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    Node *next;
} Node;

Node *stack;

struct _Stack{
    Node *head;
    Node *tail;
} Stack;

//tạo Node
Node *createNode(int data) {
    Node *p = new Node();
    if (p == NULL) {
        return NULL;
    }
    p->data = data;
    p->next = NULL;
 
    return p;
}



int main (){
 int lc, k;
    Stack s;
  push(s, 10);
  push(s, 11);
  push(s, 12);
  push(s, 13);
  push(s, 14);
  push(s, 15);
  push(s, 16);

}