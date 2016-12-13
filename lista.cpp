#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int val;
    struct node *next;
};

void crear(struct node *head, struct node *tail)
{
    struct node *prev, *cur;
    cout << "Cuantos nodos desea:" << endl;
    int n;
    cin >> n;
    head->val=1;
    prev=head;
    if (n>1){
		for (int i=2; i<=n; i++){
    	    cur=(struct node*)malloc(sizeof(struct node));
    	    cur->val=i;
    	    prev->next=cur;
    	    prev=cur;
    	}
    }
    tail=prev;
    tail->next=NULL;
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

struct node *elim(struct node *head, struct node *tail)
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
    else if (tail->val=key){
		struct node *cur;
		for (cur=head; cur->val<key-1; cur=cur->next)
    		;
    	free(tail);
    	tail=cur;
    	tail->next=NULL;
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
    struct node *head, *tail;
    head=(struct node*)malloc(sizeof(struct node));
    tail=(struct node*)malloc(sizeof(struct node));
	crear(head, tail);
    impr(head);
    head=elim(head, tail);
    impr(head);
    return 0;
}
