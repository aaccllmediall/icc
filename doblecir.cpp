#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int val;
    struct node *next, *ante;
};

void crear(struct node *head)
{
    struct node *prev, *cur, *vir;
    cout << "Cuantos nodos desea:" << endl;
    int n;
    cin >> n;
    head->val=1;
    prev=head;
    if (n>1){
		for (int i=2; i<=n; i++){
    	    cur=(struct node*)malloc(sizeof(struct node));
    	    cur->val=i;
    	    if (i==2){
                cur->ante=head;
    	    }
    	    vir=prev->next;
    	    vir->ante=cur;
    	    prev->next=cur;
    	    prev=cur;
    	}
    }
    prev->next=head;
    head->ante=prev;
};

void impr(struct node *head)
{
    cout << "IMPRIMIENDO:" << endl;
    struct node *t;
    t=head;
    cout << t->val << endl;
    t=t->next;
    while (t!=head){
        cout << t->val << endl;
        t=t->next;
    }
    cout << "AHORA AL REVES:" << endl;
    while (t!=head){
        cout << t->val << endl;
        t=t->ante;
    }
    cout << head->val << endl;
};

struct node *elim(struct node *head)
{
    cout << "Quitando nodo:" << endl << "Retire un termino existente:" << endl;
    int key;
    cin >> key;
	if (head->val==key){
        struct node *temp;
        temp=head->next;
        free(head);
        head=temp;
        return head;
    }
    else {
        struct node *prev, *cur;
        prev=head;
        cur=head->next;
        while(cur!=NULL){
            if (cur->val==key){
                prev->next=cur->next;
                free(cur);
                break;
            }
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};

int main()
{
    struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    crear(head);
    impr(head);
    head=elim(head);
    impr(head);
    return 0;
}
