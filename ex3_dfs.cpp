#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;
#define MAX 10
#define inputfile "test.txt"
typedef struct QUEUE{
 	int size;
	int array[100];
};

typedef struct GRAPH{
	int n;
 	int a[MAX][MAX];
}DOTHI;

int LuuVet[MAX];
int ChuaXet[MAX];

// QUEUE
void KhoiTaoQueue(QUEUE &q){
    q.size = 0;
}

int push(QUEUE &q, int value){
    if(q.size + 1 >= 100){
        return 0;
    }
    q.array[q.size] = value;
    q.size++;
    return 1;
}

int pop(QUEUE &q, int &value){
    if(q.size <= 0){
        return 0;
    }
    value = q.array[0];
    for(int i = 0; i < q.size-1; ++i){
        q.array[i] = q.array[i+1];
    }
    q.size--;
    return 1;
}

int isEmpty(QUEUE q){
    if(q.size <= 0){
        return 1;
    }
    return 0;
}

// GRAPH DFS
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
    for(int i = 0; i < g.n; ++i){
        LuuVet[i] = -1;
        ChuaXet[i] = 0;
    }
    int i = F;
    DFS(S, g);
    if(ChuaXet[F] == 1){
        printf("Duong di tu dinh %d den dinh %d la: ", S, F);
        printf("%d ", F);
        while(S != F){
            cout << LuuVet[F] << ' ';
            F = LuuVet[F];
        }
    }else{
        printf("Khong co duong di tu dinh %d den dinh %d!\n", S, F);
    }
}

// GRAPH BFS
void BFS(int v, GRAPH g){
    QUEUE q;
    KhoiTaoQueue(q);
    push(q,v);
    while(!isEmpty(q)){
        pop(q, v);
        ChuaXet[v] = 1;
        for(int u = 0; u < g.n; ++u){
            if(g.a[v][u] != 0 && ChuaXet[u] == 0){
                push(q,u);
                if(LuuVet[u] == -1){
                    LuuVet[u] = v;
                }
            }
        }
    }
}

void DuyetTheoBFS(int S, int F, GRAPH g){
    for(int i = 0; i < g.n; ++i){
        LuuVet[i] = -1;
        ChuaXet[i] = 0;
    }
    int i = F;
    BFS(S, g);
    if(ChuaXet[F] == 1){
        printf("Duong di tu dinh %d den dinh %d la: ", S, F);
        printf("%d ", F);
        while(S != F){
            cout << LuuVet[F] << ' ';
            F = LuuVet[F];
        }
    }else{
        printf("Khong co duong di tu dinh %d den dinh %d!\n", S, F);
    }
}

int main(){
	DOTHI g;
	if(DocMaTranKe(inputfile,g) == 1){
        cout << "Read file comple!" << endl;
	}
	XuatMaTranKe(g);
    DuyetTheoBFS(0, 6,g);
}
