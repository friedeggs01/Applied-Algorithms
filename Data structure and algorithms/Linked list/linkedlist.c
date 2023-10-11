/*Cho 1 danh sách liên kết đơn, viết 1 hàm đảo chiều danh sách này.
Đầu vào hàm là một con trỏ tới danh sách đơn, đầu ra là một con trỏ trỏ tới danh sách đơn đã đảo chiều
a. Cho phép cấp phát thêm bộ nhớ động
b. Không được phép cấp thêm bộ nhớ động
c. Sử dụng đệ quy*/

#include<stdio.h>
#include<stdlib.h>

typedef struct _Node{
        int value;
        struct _Node *next;
}Node;

Node* head;

Node* makenewNode(int x){
    Node* p = NULL;
    p = (Node*)malloc(sizeof(Node));
    if(p==NULL){
        printf("Error in mem alloc\n");
        exit(0);
    }
    p->value = x;
    p->next = NULL;
    return p;
}
void printList(Node *l){
    Node *p = l;
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
}

Node *addHead(Node *l, int x){
    Node *temp = makenewNode(x);
    temp->next = l;
    l = temp;
    return l;
}
Node *daods1(Node *l){
    if(l==NULL) return l;
    Node *tmp = l, *dsmoi=NULL, *temp;
    //thêm phần tử vào đầu danh sách mới tạo
    while(tmp!=NULL){
        temp = makenewNode(tmp->value);
        temp->next = dsmoi;
        dsmoi = temp;
        tmp = tmp->next;
    }
    return dsmoi;
}

Node *daods2(Node *l){
    if((l==NULL)||(l->next==NULL)) return l;
    Node *p1 = NULL, *p2 = l, *p3 = p2->next;
    while(p2!=NULL){
        //đảo chiều danh sách
        p2->next = p1;

        //update
        if(p3==NULL) break;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    return p2;
}

Node *daods3(Node *l){
    if((l==NULL)||(l->next==NULL)) return l;
    Node *h = l;
    //điều kiện dừng
    if(h->next->next==NULL){
        h->next->next = h;
        Node *tmp = h->next;
        h->next = NULL;
        return tmp;
    } else {
        Node *dcnutdaumoi = daods3(h->next);
        h->next->next = h;
        h->next = NULL;
        return dcnutdaumoi;
    }
}

int main() {
    Node *old_p, *p, *head=NULL;
    int n, a;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        p=makenewNode(a);
        if(i==0){
            head=p;
        } else {
            old_p->next=p;
        }
        old_p = p;
    }
    printList(head);
    head = daods3(head);
    printf("\n");
    printList(head);
    
}