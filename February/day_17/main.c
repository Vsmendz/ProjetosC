#include "pilha_din.c"

int main(int argc, char const *argv[])
{
    pilha_dado *pd = NULL;
    
    empilhar(10,&pd);
    empilhar(20,&pd);
    empilhar(30,&pd);
    print(pd);
    printf("\n");

    printf("(%d)\n",rec_print(pd));
    return 0;
}
