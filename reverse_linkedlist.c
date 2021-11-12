#include <stdio.h>
#include <stdlib.h>
typedef struct _listnode
{
    int num;
    struct _listnode *next;
} ListNode;
void printList(ListNode *head)
{
    ListNode *cur=head;
    if (cur== NULL) return;
    while (cur!= NULL)
    {
        printf("%d\n", cur ->num);
        cur = cur ->next;
    }
}
void reverse(ListNode **head)
{
    ListNode *prev = NULL;
    ListNode *cur = *head;
    ListNode *next = NULL;
    while (cur != NULL)
    {
        next = cur->next; //lưu lại node next
        cur->next = prev; //Đảo ngược con trỏ next của con trỏ cur
        prev = cur; // // Di chuyển con trỏ lên trước một vị trí.
        cur = next;
    }
    *head = prev;
}
int main(void)
{
    ListNode *head = NULL;
    int n;
    ListNode *newNode;
    printf("Nhap n: ");
    scanf("%d", &n);
    newNode=malloc(sizeof(ListNode));
    head=newNode;
    for (int i=1; i<n; i++)
    {
        scanf("%d", &newNode->num);
        newNode->next=malloc(sizeof(ListNode));
        newNode=newNode->next;
    }
    scanf("%d", &newNode->num); //the last num
    newNode->next=NULL;
    printf("DSLK Chua dao nguoc: \n");
    printList(head);
    reverse(&head);
    printf("DSLK Da dao nguoc: \n");
    printList(head);
    return 0;
}
