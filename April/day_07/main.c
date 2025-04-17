#include "arvore_bin.c"

int main(int argc, char const *argv[])
{
    tipo_arvore*no_buscado;
    tipo_arvore*arv = NULL;
    int qtd_no = 0;
    int qtd_folha = 0;
    insere_arvore(&arv,10);
    insere_arvore(&arv,8);
    insere_arvore(&arv,16);
    insere_arvore(&arv,120);
    insere_arvore(&arv,1);
    insere_arvore(&arv,2);
    pre_ordem(arv);
    printf("\n");
    pos_ordem(arv);
    printf("\n");
    ordem(arv);
    total_no(arv,&qtd_no);
    printf("\nquantidade no [%d]\n",qtd_no);
    total_folha(arv,&qtd_folha);
    printf("\nquantidade folha [%d]\n",qtd_folha);
    no_buscado = busca_no(arv,10);
    printf("\nno encontrado [%d]\n",no_buscado->valor);
    verificar_no(no_buscado);
    int h = altura_arvore(arv);
    printf("\naltura %d\n",h);
    return 0;
}
