#include <stdio.h>

int A[100][100],n;// biến cục bộ
//đoc file
void docfile(){
	FILE *f;
	f=fopen("Matrix.txt","r");//tim file
	if(f==NULL)
		printf("tui khong thay file");
	else
		fscanf(f, "%d",&n );
		for(int i=0; i<n;i++){
			for(int j=0; j<n;j++)
				fscanf(f, "%d", &A[i][j]);
	}
	fclose(f);			
}
//viet file
void infile(){
	printf("\nSo dinh %d\n", n);
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
}
//đối xứng qua đừng chéo
int doixung(){
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)//lap theo ma tran
			if(A[i][j]!=A[j][i]) return 0;// xuất hiện 1 cặp số khác nhau thì trả về không
	return 1;//nếu đối xứng thì về 1
}
//ktra ma tran có số lớn hơn 1 hay khoong
int MTnhohon1(){
	int count = 0;
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++){
			if(A[i][j]>1) count++; //có 1 số lớn hơn 1 thì count khac 0
		}
		if(count!=0) return 0; // ma tran có số lớn hơn 1
	return 1; // ma tran khong có số lớn hơn 1
}
int ktraDC(){
	for(int i = 0; i<n;i++)
		if(A[i][i]!=0)
			return 0;
	return 1; 
}
int main(){
	int x, bac = 0;
	docfile();
	printf("Ma tran ke cua do thi");
	infile();
	printf("nhap x");
	scanf("%d",&x);
	if(doixung()){
		for(int j=0;j<n;j++){
			if(j==x){
				if(A[x][j]>0)
					bac += 2*A[x][j];
			}else
				bac += A[x][j];
		}
		printf("bac dinh %d la %d", x, bac);
	} else {
		int bacvao = 0, bacra = 0;
		for(int i = 0; i<n; i++){
			bacvao += A[i][x]; //bac vao la tong hang doc
			bacra += A[x][i];// bac ra la tong hang ngang	
		}
		printf("bac vao cua x la %d\n", bacvao);	
		printf("bac ra cua x la %d", bacra);
	}
	return 0;
}