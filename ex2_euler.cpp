#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10
#define inputfile "D:/test.txt"
typedef struct STACK{
	int array[100];
 	int size;
}STACK;

typedef struct GRAPH{
	int n;
 	int a[MAX][MAX];
}DOTHI;

int DocMaTranKe(char Tenfile[100], DOTHI &g){
	FILE *f = fopen(Tenfile, "rt");
 	if (f == NULL) {
 		printf("Khong mo duoc file\n");
 		return 0;
}
	fscanf(f, "%d", &g.n);
 	int i, j;
 	for (i=0; i < g.n; i++){
  		for (j=0; j < g.n; j++){
   			fscanf(f, "%d", &g.a[i][j]);
   		}
 	}
 	fclose(f);
	return 1;
}

void XuatMaTranKe (DOTHI g){
	printf("So dinh cua do thi la %d\n", g.n);
 	printf("Ma tran ke cua do thi la\n");
 	for (int i = 0; i < g.n; i++) {
 		printf ("\t");
 		for (int j = 0; j < g.n; j++){
 			printf("%d ",g.a[i][j]);
 		}
 		printf("\n");
 	}
}

void khoitaoStack(STACK &stack){
	stack.size = 0;
}

void DayGiaTriVaoStack (STACK &stack, int value){
	if(stack.size + 1 >= 100){
  		return;
 	}
	stack.array[stack.size] = value;
  	stack.size++;
}

void TimDuongDi (DOTHI &g, STACK &stack, int i){
	for (int j = 0; j < g.n ; j++){
  		if (g.a[i][j] != 0) {
  			g.a[i][j] = g.a[j][i] = 0;
  			TimDuongDi(g,stack,j);
  		}
 	}
	DayGiaTriVaoStack(stack,i);
}

int KiemTraChuTrinhEuler (DOTHI g){
	int i, j, bac;
 	for (i = 0; i < g.n; i++){
 		bac = 0;
 		for (j = 0; j < g.n; j++){
  			bac += g.a[i][j];
 		}
 	if (bac % 2)
 	return 0;
}
	int x = 0;
 	int flag = 0;
 	for (i = 0; i < g.n; i++){
  		for (j = 0; j < g.n; j++){
  			if (g.a[i][j] != 0){
   				x = i;
   				flag = 1;
   				break;
   			}
  		}
  		if(flag==1)
  		break;
 	}
	DOTHI temp = g;
 	STACK stack;
 	khoitaoStack(stack);
 	TimDuongDi(temp, stack, x);
 	for (i = 0; i < temp.n; i++){
  		for (j = 0; j < temp.n; j++){
   			if (temp.a[i][j] != 0)
   			return 0;
  		}
 	}
	if (stack.array[stack.size - 1] != stack.array[0])
 	return 0;
 	printf("\nChu trinh Euler: ");
 	for(i = stack.size - 1; i >= 0 ; i--)
 		printf("%d ",stack.array[i] + 1);
 		return 1;
}
int KiemTraDuongDiEuler (DOTHI g){
	int i,j;
 	int x = 0;
 	int flag = 0;
 	int bac = 0;
 	for (i = 0; i < g.n; i++){
  		bac = 0;
  		for (j = 0; j < g.n; j++){
   			if (g.a[i][j] != 0){
    			bac++;
   			}
  		}
 		if (bac%2 != 0) {
 			x = i;
 			flag = 1;
 			break;
 		}
 	}
 	if(flag == 0)
 		return 0;
 		DOTHI temp = g;
 		STACK stack;
 		khoitaoStack (stack);
 		TimDuongDi(temp, stack,x);
 		for (i = 0; i < temp.n; i++){
  			for (j = 0; j < temp.n; j++){
   				if(temp.a[i][j]!=0)
   					return 0;
  			}
 		}
 		if (stack.array[stack.size - 1] == stack.array[0])
 			return 0;
 			printf("\nDuong di Euler : ");
 			for(i = stack.size - 1; i >= 0 ; i--)
 				printf("%d ",stack.array[i] + 1);
 				return 1;
}


int main(){
	DOTHI g;
	if(DocMaTranKe(inputfile,g)==1){
 		printf("Da lay thong tin do thi tu file thanh cong.\n\n");
 		XuatMaTranKe(g);
 		printf("Bam 1 phim bat ki de bat dau xet tim chu trinh euler ...\n\n");
 		getch();
 		if (!KiemTraChuTrinhEuler(g)){
            printf("Khong co chu trinh Euler trong do thi cua ban\n");
 			printf("\nBam 1 phim bat ki de bat dau xet tim duong di euler ...\n");
  			getch();
  			if (!KiemTraDuongDiEuler(g)){
   				printf("\nKhong co duong di Euler trong do thi cua ban \n");
   				getch();
  			}
 		}
 	}
	getch();
}
