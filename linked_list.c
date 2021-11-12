#include <stdio.h>
typedef struct _listnode {
 int num;
 struct _listnode *next;
} ListNode;
 void printList(ListNode *head){
    ListNode *cur=head; // Gán con trỏ hiện tại ở phần tử đầu
    if (cur== NULL) return; // nếu con trỏ cur = Null thì trả về;
        while (cur!= NULL){
            printf("%d\n", cur ->num); // in ra giá trị cur
                cur = cur ->next; // gán con trỏ cur bằng cur -> next
        }
}
ListNode *findNode(ListNode *head, int i) {
    ListNode *cur = head; // Gán con trỏ hiện tại ở phần tử đầu
    if ((head == NULL) || (i < 0)) { //Khi ds tróng hoặc chỉ số k hợp lệ
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
    return NULL;
    }
    while (i > 0 ) {
        cur = cur->next; // cur tiến lên 1 giá trị
        i--; //Giảm i đi 1 (i chỉ số nút ở trong dslk)
        if (cur == NULL) { // Khi ds ngắn hơn chỉ số (cur vượt quá số i)
            printf("Phan tu tim kiem khong ton tai");
        return NULL;
        }
    }
return cur;
}
void insertNode(ListNode **pHead, int index, int value) {
    ListNode *cur, *newNode;
    if (*pHead == NULL || index == 0) { // Ds chưa có phần tử nào or chèn 1 node vào đầu ds có chỉ số = 0
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    else if ((cur = findNode(*pHead, index - 1)) != NULL) { //Sử dụng findNode() để tìm địa chỉ của con trỏ cur
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;       
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else printf("Cannot insert the new item at index %d!\n", index);
}
void removeNode(ListNode **ptrHead, int index){
    ListNode *cur, *pre;
    if (index == 0){ // nếu nút cần xóa là nút đầu tiên
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur); //Xóa cur
    } else {
        pre = findNode(*ptrHead, index - 1); // Tìm nút trước nút cần xóa
        cur = pre->next ; // cur = index
        pre->next = cur->next ; //nối 
        free(cur); // giải phóng cur
 }
}
int main(void){
    ListNode *node0, *node1, *head;
    node0 = malloc(sizeof(ListNode));
    node1 = malloc(sizeof(ListNode));
    node0->num = 20;
    node1->num = 30;
    node0->next = node1;
    node1->next = NULL;
    head = node0;

    printf("List ban dau\n");
    printList(head);

    ListNode *node1addr = findNode(head, 1);
    printf("Dia chi cua node1: %p\n", node1);
    printf("Dia chi cua node1 tim thay: %p\n", node1addr);
    printf("Gia tri cua node1: %d\n", node1addr->num);

    ListNode **pHead;
    pHead = &head;

    insertNode(pHead, 2, 40);
    insertNode(pHead, 3, 50);
    insertNode(pHead, 4, 60);
    printf("List sau khi insert\n");
    printList(pHead);

    ListNode **ptrHead;
    ptrHead = &head;
    removeNode(ptrHead, 3);
    printf("List sau khi remove\n");
    printList(ptrHead);
    return 0;
}
