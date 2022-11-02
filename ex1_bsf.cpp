#include<bits/stdc++.h>
#define MAX 10
#define pathFile "test.txt"

struct graph{
    int n;
    int a[MAX][MAX];
};

int readFile(char path[100], graph &g){
    FILE *f;
    f = fopen(path, "rt");
    if(f == NULL){
        printf("error open file!\n");
        return 0;
    }
    fscanf(f, "%d", &g.n);
    for(int i = 0; i < g.n; ++i){
        for(int j = 0; j < g.n; ++j){
            fscanf(f, "%d", &g.a[i][j]);
        }
    }
    fclose(f);
    return 1;
}

void display(graph g){
    printf("%d\n", g.n);
    for(int i = 0; i < g.n; ++i){
        for(int j = 0; j < g.n; ++j){
            printf("%d ", g.a[i][j]);
        }
        printf("\n");
    }
}

int isGraph(graph g){
    for(int i = 0; i < g.n; ++i){
        if(g.a[i][i] != 0){
            return 0;
        }
    }
    return 1;
}

int isScalarGraph(graph g){
    for(int i = 0; i < g.n; ++i){
        for(int j = 0; j < g.n; ++j){
            if(g.a[i][j] != g.a[j][i]){
                return 0;
            }
        }
    }
    return 1;
}

void findVertices(graph g, int temp[MAX], int i){
    for(int j = 0; j < g.n; ++j){
        if(g.a[i][j] != 0 && temp[j] != temp[i]){
            temp[j] = temp[i];
            findVertices(g, temp, j);
        }
    }
}

void allBSF(graph g){
    int temp[MAX];
    for(int i = 0; i < g.n; ++i){
        temp[i] = 0;
    }
    int count = 0;
    for(int i = 0; i < g.n; ++i){
        if(temp[i] == 0){
            count++;
            temp[i] = count;
        }
        findVertices(g, temp, i);
    }
    for(int i = 1; i <= count; ++i){
        printf("Thanh phan lien thong thu %d: ", i);
        for(int j = 0; j < g.n; ++j){
            if(temp[j] == i){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main(){
    graph g;
    if(readFile(pathFile, g) == 1){
        printf("read file sucsessfull!\n");
        display(g);
        allBSF(g);
    }
    return 0;
}
