#include <stdio.h>
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
int isEmptyStack(Stack *s)
{
    if ((s->ll).size == 0)
        return 1;
    return 0;
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
void main()
{
    int day = 1;
    int j, clothes;
    Stack s;
    int dryLeftDay[6]; //với mỗi áo (số 1 tới số 5), cần bao ngày nữa sẽ khô
    s.ll.head = NULL;
    s.ll.size=0; //khởi tạo stack s.
    for (j=1; j<=5; j++) push(&s, j);
    for (j=1; j<=5; j++) dryLeftDay[j]= -1; //<0 nghĩa là áo khô
    while (day <=10 )
    {
        for (j=1; j<=5; j++)
            dryLeftDay[j]--; //giảm 1 ngày cần để khô
        clothes=pop(&s);
        printf("Day %d is clothes No. %d. \n", day, clothes);
               dryLeftDay[clothes]=2; //ví dụ, M=2, cần 2 ngày để khô
               for (j=1; j<=5; j++)
               if (dryLeftDay[j]==0) //nghĩa là áo vừa khô
                   push(&s, j);
                   day++;
        }
}
