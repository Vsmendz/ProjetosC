#include <stdio.h>

int main() {
    FILE *arquivo = fopen(".txt", "r"); // Abrindo para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fclose(arquivo);
    return 0;
}
