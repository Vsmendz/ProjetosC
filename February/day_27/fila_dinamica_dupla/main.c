#include "lista_d.c"

int main(int argc, char const *argv[])
{
    tipo_lista *ls = NULL;
    inserirIni(&ls,10);
    inserirIni(&ls,20);
    inserirFim(&ls,90);
    inserirId(&ls,780,1);
    removerFim(&ls);
    inserirFim(&ls,90);
    inserirFim(&ls,90);
    inserirFim(&ls,90);
    inserirFim(&ls,90);
    removerValor(&ls,7870);
    remover_especial(&ls);
    remover_especial(&ls);
    remover_especial(&ls);
    remover_especial(&ls);
    imprimir(ls);

    return 0;
}
