#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct _listnode
{
    int num;
    struct _listnode *next;
} ListNode;
typedef struct _linkedlist
{
    ListNode *head;
    ListNode *tail;
    int size;
} LinkedList;
typedef struct _queue
{
    LinkedList ll;
} Queue;
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
void enqueue(Queue *q, int item)
{
    insertNode(&(q->ll.head), q->ll.size, item);
    q->ll.size++;
}
int dequeue(Queue *q)
{
    int item;
    if (q->ll.head != NULL)
    {
        item = ((q->ll).head)->num;
        removeNode(&(q->ll).head, 0);
        (q->ll).size--;
        return item;
    }
    else
    {
	printf("Hang doi rong");
        return 0;
    }
}
int peek(Queue *q)
{
    if (q->ll.head != NULL)
        return (q->ll).head->num;
    else
    {
        printf("Hang doi rong");
        return 0;
    }
}
int isEmptyQueue(Queue *q)
{
    if ((q->ll).size == 0)
        return 1;
    return 0;
}
int main(){
    //EAS*Y*QUE***ST***10*N***
    char d[50] = "EAS*Y*QUE***ST***I0*N***";
    Queue *q = malloc(sizeof(Queue));
	q->ll.size = 0;
	q->ll.head = NULL;
    //scanf("%s",d);
    for(int i=0;i<strlen(d);i++)
        if (d[i]=='*')
            printf("%c ",dequeue(q));
        else
            enqueue(q, d[i]);

    //printList(q);
}
