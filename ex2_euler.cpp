#include<bits/stdc++.h>
#define MAX 100
#define pathFile "test.txt"
/*
    DK: Euler
    Do thi vo huong co chu trinh euler neu:
        - Cac dinh co bac khac 0 cua do thi lien thong voi nhau
        - Tat ca dinh cua do thi deu co bac chan
*/

// STRUCT
struct graph{
    int n;
    int a[MAX][MAX];
};

struct stack{
    int a[MAX];
    int n;
};
// -- graph func
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

void display_graph(graph g){
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

// -- stack func

stack init(stack &st){
    st.n = 0;
    return st;
}

void push(stack &st, int value){
    if(st.n + 1 >= MAX){
        return;
    }
    st.a[st.n] = value;
    st.n++;
}

void find(int i, graph &g, stack &st){
    for(int j = 0; j < g.n; ++j){
         if(g.a[i][j] != 0){
            g.a[i][j] = g.a[j][i] = 0;
            find(j, g, st);
         }
    }
    push(st, i);
}

void display_st(stack &st){
    for(int i = 0; i < st.n; ++i){
        printf("%d ", st.a[i]);
    }
    printf("\n");
}

int checkPeak(graph g){
    int s, d = 0;
    for(int i = 0; i < g.n; ++i){
        s = 0;
        for(int j = 0; j < g.n; ++j){
            s+=g.a[i][j];
        }
        if(s % 2) d++;
    }
    if(d > 0) return 0;
    return 1;
}

void isEuler(graph g){
    if(checkPeak(g) == 0){
        printf("do thi khong co chu trinh euler vi co dinh bac le.\n");
        return;
    }
    for(int i = 0; i < g.n; ++i){
        graph temp = g;
        stack st = init(st);
        printf("xuat phat tu %d: ", i);
        find(i, temp, st);
        display_st(st);
    }
}

int main(){
    graph g;
    readFile(pathFile, g);
    display_graph(g);
    isEuler(g);
    return 0;
}
