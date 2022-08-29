#include <stdio.h>

int main(void)
{
    int *p, *q, a = 10, b = 20, c;

    p = &a;
    q = &b;
    c = *p + *q;
    printf("\n\n%x %x %d\n\n", p, q, c);
    return (0);
}

/*
O programa acima cria 5 variáveis, sendo 3 inteiras (a, b e c) e 2 ponteiros (p e q) e efetua
uma soma, armazenada em c, entre os conteúdos de memória para onde q e p apontam, mostrando seu
resultado, junto com os endereços de memória de p e q, na saída padrão,

Nas linhas 7 e 8 é feita a atribuição dos valores dos endereços de memória das variáveis a e b 
para os ponteiros p e q, respectivamente. Abaixo, na linha 9, a soma descrita acima é efetuada
e tem seu valor guardado em c.
*/