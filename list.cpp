#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
struct Node {
	int data;
	Node *next;
};
class List {
	private:
		Node *head,*tail;
	public:
		List() {
			head=NULL;
		}
		void addNode(int n) {
			Node *temp=new Node;
			temp->data=n;
			temp->next=NULL;
			if(head==NULL) {
				head=temp;
				tail=temp;
			}
			else {
				tail->next=temp;
				tail=temp;
			}
		}
		int size() {
			Node *p=head;
			int k=0;
			while(p!=NULL) {
				k++;
				p=p->next;
			}
			return k;
		}
		void remove(int n) {
			Node *p=head,*pre=NULL;
			int k=0;
			if(n==1) {
				Node *temp=head;
				head=head->next;
				if(head==tail)
				tail=NULL;
				free(temp);
				return;
			}
			while(p!=NULL) {
				k++;
				if(k==n) {
					Node *temp=p;
					pre->next=p->next;
					if(tail==p)
					tail=pre;
					free(temp);
					return;
				}
				pre=p;
				p=p->next;
			}
		}
		void print() {
			Node *p=head;
			while(p!=NULL)
			{
				cout<<p->data<<" ";
				p=p->next;
			}
			cout<<"\n";
		}
};
int main()
{
	List A;
	A.addNode(1);
	A.addNode(7);
	A.addNode(6);
	A.addNode(4);
	A.addNode(13);
	A.addNode(10);
	cout<<A.size()<<"\n";
	A.remove(2);
	cout<<A.size()<<"\n";
	A.remove(1);
	A.print();
	A.addNode(1);
	A.print();
	return 0;
}
