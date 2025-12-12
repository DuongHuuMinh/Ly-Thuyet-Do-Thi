#include <bits/stdc++.h>
#include <stack>
using namespace std;
int A[101][101],n;
int d[101];

void readfile(){
	FILE*f = fopen("D:/Matrix.txt", "r");
	if(f==NULL){
		cout <<"file khong ton tai" << endl;
	} else {
		fscanf(f,"%d",&n);
		for(int i=1; i<=n;i++)
			for(int j=1; j<=n;j++)
				fscanf(f,"%d ",&A[i][j]);
		fclose(f);
		}
}

void infile(){
	cout << "So dinh " << n << endl;
	for(int i=1; i<=n;i++){
		for(int j=1; j<=n;j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}


int main()
{
	readfile();
	infile();
	int x;
	cout << "nhap dinh can duyet: ";
	cin>>x;
	// Khoi tao m?ng ban d?u
	for(int i=1; i<=n;i++) d[i]=0;
	stack<int>st;
	st.push(x);
	cout << "ket qua duyet DFS (" << x << ") la ";
	while(!st.empty()){
		int kq = st.top();
		st.pop();
		if(d[kq]==0){
			cout <<kq<<" ";
			d[kq] =-1;
		for(int j=n; j>=1; j--){
			if(A[kq][j] == 1 && d[j] ==0){
				st.push(j);
				}
			}
		}
	}
	
    return 0;
}