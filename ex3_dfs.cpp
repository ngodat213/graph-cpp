#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
#define MAX 10
#define inputfile "test.txt"
typedef struct STACK{
	int array[100];
 	int size;
}STACK;

typedef struct GRAPH{
	int n;
 	int a[MAX][MAX];
}DOTHI;

int LuuVet[MAX] = {-1};
int ChuaXet[MAX] = {0};

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

void DFS(int v, GRAPH g){
    ChuaXet[v] = 1;
    for(int i = 0; i < g.n; ++i){
        if(g.a[v][i] != 0 && ChuaXet[i] == 0){
            LuuVet[i] = v;
            DFS(i,g);
        }
    }
}

void DuyetTheoDFS(int S, int F, GRAPH g){
    int i = F;
    DFS(S, g);
    if(ChuaXet[F] == 1){
        printf("Duong di tu dinh %d den dinh %d la: ", S, F);
//        i = F;
        printf("%d ", F);
        for(int i = F; i >= g.n; i--){
            if(LuuVet[i] + 1 == F){
                cout << LuuVet[i] << " ";
                if(LuuVet[i] == -1){
                    break;
                }
            }
        }
    }
}

int main(){
	DOTHI g;
	if(DocMaTranKe(inputfile,g) == 1){
        cout << "Read file comple!" << endl;
	}
	DFS(0, g);
//	DuyetTheoDFS(0, 5, g);
	getch();
}
