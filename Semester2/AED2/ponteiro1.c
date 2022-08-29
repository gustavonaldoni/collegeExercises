#include <stdio.h>

int main(void)
{
    int x;
    int *ap_x = &x;

    x = 100;
    printf("\ nvalor de x = %d\n", *ap_x);

    *ap_x = 200;
    printf("\ nvalor de x = %d\n", *ap_x);

    return (0);
}

/*
O programa acima cria duas variáveis, x e ap_x, sendo a última um ponteiro.
Tal ponteiro recebe, na linha 6, o endereço de memória da otura variável.

Assim, é atribuído, na linha 8, o valor inteiro 100 para x e mostrado, logo abaixo,
na saída-padrão, seu valor por meio da expressão *ap_x. Tal expressão serve para que
seja acessado o conteúdo da variável o qual o ponteiro ap_x aponta.

Na linha 11 isso é novamente usado no intuito de mudar o valor de x para 200, que é
mostrado na saída padrão em sequência pela mesma estrutura.
*/