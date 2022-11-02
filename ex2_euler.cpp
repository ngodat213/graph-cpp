#include<bits/stdc++.h>
#define MAX 100

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

void init(stack &st){
    st.n = 0;
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

void display_st(stack st){
    for(int i = 0; i < st.n; ++i){
        printf("%d ", st.a[i]);
    }
    printf("\n");
}

void isEuler(graph g){

}

int main(){

    return 0;
}
