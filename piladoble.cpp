#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int val;
    struct node *next, *previ;
};

void crear(struct node *head)
{
    struct node *prev, *cur;
    cout << "Cuantos nodos desea:" << endl;
    int n;
    cin >> n;
    head->val=1;
    prev=head;
    for (int i=2; i<=n; i++){
        cur=(struct node*)malloc(sizeof(struct node));
        cur->val=i;
        prev->next=cur;
        prev=cur;
    }
    prev->next=NULL;
};

void impr(struct node *head)
{
    cout << "IMPRIMIENDO:" << endl;
    struct node *t;
    t=head;
    while (t!=NULL){
        cout << t->val << endl;
        t=t->next;
    }
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

void reve(struct node *head)
{
	struct node *cur;
	cur=head;
	cur->previ=NULL;
	while (cur->next!=NULL){
		(cur->next)->previ=cur;
		cur=cur->next;
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
