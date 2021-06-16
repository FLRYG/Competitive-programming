#include<stdio.h>
#include<stdlib.h>

typedef struct myint
{
    int a;
}Myint;


void exBad(int *x_){
    x_=malloc(sizeof(int));
    *x_=1;
}

void exGood(int **x_){
    *x_=malloc(sizeof(int));
    **x_=1;
}

void ex2Bad(Myint *y_){
    y_=malloc(sizeof(Myint));
    (y_)->a=1;
}

void ex2Good(Myint **y_){
    *y_=malloc(sizeof(Myint));
    (*y_)->a=1;
}

// void ex2Better(Myint *y_){
//     printf("%x",&y_);
// }

int main(){
    int *x=NULL;
    exBad(x);
    if(x==NULL) puts("NULL\n");
    else printf("%d\n\n",*x);

    x=NULL;
    exGood(&x);
    if(x==NULL) puts("NULL\n");
    else printf("%d\n\n",*x);

    Myint *y=NULL;
    ex2Bad(y);
    if(y==NULL) puts("NULL\n");
    else printf("%d\n\n",y->a);

    y=NULL;
    ex2Good(&y);
    if(y==NULL) puts("NULL\n");
    else printf("%d\n\n",y->a);

    // y=NULL;
    // printf("%x\n",&y);
    // ex2Better(y);
}