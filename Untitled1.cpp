#include <stdio.h>

int A[100][100],n;

void docfile(){
	FILE *f;
	f=fopen("Matrix.txt","r");
	if(f==NULL)
		printf("tui khong thay file");
	else
		fscanf(f, "%d",&n );
		for(int i=0; i<n;i++)
			for(int j=0; j<n;j++)
				fscanf(f, "%d", &A[i][j]);
	fclose(f);			
}

void infile(){
	printf("So dinh %d\n", n);
	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
}

int doixung(){
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++)
	if(A[i][j]!=A[j][i]) return 0;
	
	return 1;
}

int MTnhohon1(){
	int count = 0;
	for(int i=0; i<n;i++)
		for(int j=0; j<n;j++){
			if(A[i][j]>1) count++;
		}
		if(count==0) return 0; 
	return 1; 
}

int ktraDC(){
	for(int i = 0; i<n;i++)
		if(A[i][i]!=0)
			return 0;
	return 1; 
}

int main(){
	docfile();
	infile();
	if(doixung()){
		if(!ktraDC()) printf("gia do thi vo huong");
		else{
			if(MTnhohon1()) printf("da do thi vo huong");
			else printf("don do thi vo huong");
		}	
	} else{
		if(!MTnhohon1()) printf("don do thi co huong") ;
		else printf("da do thi co huong") ;
	} 
	return 0;
}