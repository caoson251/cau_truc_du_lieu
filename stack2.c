#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _listnode
{
    int num;
    struct _listnode *next;
} ListNode;
typedef struct _linkedlist
{
    ListNode *head;
    int size;
} LinkedList;
typedef struct _stack
{
    LinkedList ll;
} Stack;
void printList(ListNode *head)
{
    ListNode *cur = head;
    if (cur == NULL)
        return;
    while (cur != NULL)
    {
        printf("%d\n", cur->num);
        cur = cur->next;
    }
}
ListNode *findNode(ListNode *head, int i)
{
    ListNode *cur = head;
    if ((head == NULL) || (i < 0))
    {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    while (i > 0)
    {
        cur = cur->next;
        i--;
        if (cur == NULL)
        {
            printf("Phan tu tim kiem khong ton tai");
            return NULL;
        }
    }
    return cur;
}
void insertNode(ListNode **pHead, int index, int value)
{
    ListNode *cur, *newNode;
    if (*pHead == NULL || index == 0)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    else if ((cur = findNode(*pHead, index - 1)) != NULL)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else
        printf("Cannot insert the new item at index %d!\n", index);
}
void removeNode(ListNode **ptrHead, int index)
{
    ListNode *cur, *pre;
    if (index == 0)
    {
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    }
    else
    {
        pre = findNode(*ptrHead, index - 1);
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}
void push(Stack *s, int item)
{
    insertNode(&(s->ll.head), 0, item);
    s->ll.size++;
}
int pop(Stack *s)
{
    int item;
    if (!isEmptyStack(s))
    {
        item = ((s->ll).head)->num;
        removeNode(&(s->ll.head), 0);
        (s->ll).size--;
        return item;
    }
    else
    {
        printf("Ngan xep rong");
        return NULL;
    }
}
int isEmptyStack(Stack *s)
{
    if ((s->ll).size == 0)
        return 1;
    return 0;
}

int peek(Stack *s)
{
    if (((s->ll).head) != NULL)
    {
        return ((s->ll).head)->num;
    }
    else
    {
        printf("Ngan xep rong");
        return NULL;
    }
}
int isOperand(char ch)
{
    return ((ch >= 'a') && (ch <= 'z')) ||
           ((ch >= 'A') && (ch <= 'Z'));
}
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}
void infixToPostfix(char *exp, char *postfix)
{
    Stack *s = malloc(sizeof(Stack));
    s->ll.size = 0;
    s->ll.head = NULL;

    int i,k;
    k=-1;
    for(i=0; i < strlen(exp); i++)
    {
        //toan hang
        if(isOperand(exp[i]))
        {
            k++;
            postfix[k] = exp[i];
        }
        else if(exp[i] == '(')
        {
            push(s,exp[i]);
        }
        else if( exp[i] == ')')
        {
            while(!isEmptyStack(s) && peek(s) != '(' )
            {
                k++;
                postfix[k] = pop(s);
            }
            if(!isEmptyStack(s) && peek(s) != '(')
            {
                printf("Bieu thuc trung to khong hop le");
                return ;

            }
            else pop(s);
        }
        else  //toan tu
        {
            while(!isEmptyStack(s) && Prec(exp[i]) <= Prec(peek(s)))
            {
                k++;
                postfix[k] = pop(s);
            }
            push(s, exp[i]);
        }
    }
    while(!isEmptyStack(s))
    {
        k++;
        postfix[k] = pop(s);
    }
    postfix[++k] = '\0';

}
int main(void)
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    char *postfix = malloc(sizeof(char) * (strlen(exp) + 1));
    infixToPostfix(exp, postfix);
    printf("%s", postfix);
    return 0;
}
