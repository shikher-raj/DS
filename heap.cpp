#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
void swap(int a[],int x,int y)
{
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}
class max_heap {
	private:
		int arr[1000],last;
	public:
		max_heap() {
			last=0;
		}
		void push(int x) {
			arr[last+1]=x;
			int k=last+1;
			while(k>1) {
				if(arr[k/2]<arr[k]) {
					swap(arr,k,k/2);
					k/=2;
				}
				else
				break;
			}
			last++;
		}
		void pop() {
			swap(arr,1,last);
			last--;
			int k=1;
			while(2*k+1<=last) {
				if(arr[k]>=arr[2*k] && arr[k]>=arr[2*k+1])
				break;
				else {
					if(arr[2*k]>arr[2*k+1]) {
						swap(arr,2*k,k);
						k=2*k;
					}
					else {
						swap(arr,2*k+1,k);
						k=2*k+1;
					}
				}
			}
		}
		int top() {
			return arr[1];
		}
};
int main()
{
	max_heap p;
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		p.push(x);
	}
	cout<<p.top()<<"\n";
	p.pop();
	cout<<p.top()<<"\n";
	p.pop();
	cout<<p.top()<<"\n";
	return 0;
}
