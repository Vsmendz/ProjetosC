#include "arvore_bin_mult.c"

int main(int argc, char const *argv[])
{
    tipo_arvore* arv = NULL;
    insere(&arv,'a',20);
    insere(&arv,'b',30);
    insere(&arv,'c',50);

    insere(&arv,'e',10);

    insere(&arv,'e',25);

    insere(&arv,'e',40);

    insere(&arv,'d',70);
    insere(&arv,'e',80);
    ordem(arv);
    printf("´%d´",total_no(arv,0));
    return 0;
}
