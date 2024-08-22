#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

// IDENTIFICAR NÚMERO PRIMO - PRIMEIRA QUESTÃO //

int primo(int a) {
    // "n" é o número para verificação //
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

// PRIMOS EM 60 SEGUNDOS - SEGUNDA QUESTÃO //

void seg() {
    // Tempo inicial //
    time_t start_time = time(NULL);
    int a = 2;
    int b = 1;
    while (difftime(time(NULL), start_time) <= 60){
        if (primo(a)){
            printf("%d ", a);
            b++;
        }
        a++;
    }
    printf("/ foram gerados %d numeros primos!\n", b);
}

// FATORAR - TERCEIRA QUESTÃO //

void fatorar(int a, int b, int c){
    // "a" é o número para fatorar, "b" é o divisor, "c" é uma variavel que armazena "a" para verificar se o número é primo, já que se for primo a resposta da fatoração é ele mesmo //
    if (primo(c)){
        printf("%d, pois o numero escolhido eh primo!\n", a);
        return;
        // Identifica se o número é primo //
    }
    if (primo(b) == 0){
        // Identifica se o divisor é primo //
        return fatorar(a, b + 1, c);
    }
    else if (a % b == 0 && a / b != 1){
        printf("%d x ", b);
        return fatorar(a / b, b, c);
    }
    else if (a % b != 0){
        return fatorar(a, b + 1, c);
    }
    else if (a / b == 1 && a % b == 0){
        printf("%d.\n", b);
        return;
    }
}

// MMC E MDC POR FATORAÇÃO - QUARTA QUESTÃO //

int mmc(int a, int b, int c, int d){
    // "a" e "b" são os númeoros para tirar o mmc, "c" é o divisor, "d" é o resultado //
    if (a == 1 && b == 1){
        return d;
    }
    else if (a % c == 0 && b % c == 0 ){
        return mmc(a / c, b / c, c, d * c);
    }
    else if (a % c != 0 && b % c == 0 ){
        return mmc(a, b / c, c, d * c);
    }
    else if (a % c == 0 && b % c != 0){
        return mmc(a / c, b, c, d * c);
    }
    else {
        return mmc(a, b, c + 1, d);
    }
}
int mdc(int a, int b, int c, int d){
    // "a" e "b" são os númeoros para tirar o mdc, "c" é o divisor, "d" é o resultado//
    if (a == 1 && b == 1){
        return d;
    }
    else if (a % c == 0 && b % c == 0 ){
        return mdc(a / c, b / c, c, d * c);
    }
    else if (a % c != 0 && b % c == 0 ){
        return mdc(a, b / c, c, d);
    }
    else if (a % c == 0 && b % c != 0){
        return mdc(a / c, b, c, d);
    }
    else {
        return mdc(a, b, c + 1, d);
    }
}

// MDC POR EUCLIDES - QUINTA QUESTÃO //

int mdceuclides(int a, int b){
    // "a" e "b" são os númeoros para tirar o mmdc //
    if (b > a){
        // Troca "a" e "b" se "b" for maior que "a" para que sempre "a" > "b" //
        int c;
        c = a;
        a = b;
        b = c;
        return mdceuclides(a, b);
    }
    if (b == 0 )
    {
        return a;
    }

    else{
        return mdceuclides(b, a % b);
    }
}

// CALCULAR OS COEFICIENTES "S" E "T" - SEXTA QUESTÃO   //

void st(int a, int b, int s){
    int mdc = mdceuclides(a, b);
    int t = (mdc - (s * a)) / b;
    if ((mdc + - ( s * a )) % b == 0 && mdc == (s * a + t * b)){
        printf("Os coeficientes que obedecem essa regra sao: s = %d e t = %d.", s, t);
        return;
    }
    else {
        return st(a, b, s + 1);
    }
    return;
}

// CALCULAR INVERSO - SÉTIMA QUESTÃO //

int inverso(int a, int b, int i) {
    if (a * i % b == 1) {
        return i;
    }
    else {
        return inverso(a, b, i + 1);
    }
}

// CALCULAR CONGRUÊNCIA - OITAVA QUESTÃO //

int congruencia(int a, int b, int c, int i) {
    if ((a * i) % c == b % c) {
        return i;
    }
    else {
        congruencia(a, b, c, i + 1);
    }
}

// CALCULAR TEOREMA CHINES DO RESTO - NONA QUESTÃO //

int coprimo(int a, int b, int c){
    int mdcab = mdceuclides(a, b);
    int resp = mdceuclides(mdcab, c);
    return resp;
    // Se forem coprimos o mdc deve dar 1 //
}
int passo1(int a, int b, int c, int i) {
    
    if ((a * i) % c == b % c) {
        return i;
    }
    else {
        passo1(a, b, c, i + 1);
    }

}
int passo2(int a, int b){
    return a * b;
}
int passo3(int a, int b){
    return a % b;
}
int passo4(int a, int b, int i){
    if ((a * i) % b == 1){
        return i;
    }
    else {
        return passo4(a, b, i + 1);
    }
}
// Se a congruencia foi definida //
int calculofinal1(){
            int b1, c1, b2, c2, b3, c3;
            int i = 0;
            printf("Da primeira congruencia:\n");
            printf("Digite o valor de 'a': ");
            scanf("%d", &b1);
            printf("Digite o valor de 'b': ");
            scanf("%d", &c1);
            printf("Da segunda congruencia:\n");
            printf("Digite o valor de 'a': ");
            scanf("%d", &b2);
            printf("Digite o valor de 'b': ");
            scanf("%d", &c2);
            printf("Da terceira congruencia:\n");
            printf("Digite o valor de 'a': ");
            scanf("%d", &b3);
            printf("Digite o valor de 'b': ");
            scanf("%d", &c3);
            if (coprimo(c1, c2, c3) != 1){
                printf("Os modulos não são coprimos. Ja que o mdc deles = %d. Portanto o Teorema Chines do Resto nao pode ser usado!", coprimo(c1, c2, c3));
                return 0;
            }
            int resultadoCong1 = b1;
            int resultadoCong2 = b2;
            int resultadoCong3 = b3;
            int resultadoMult1 = passo2(c2, c3);
            int resultadoMult2 = passo2(c1, c3);
            int resultadoMult3 = passo2(c2, c1);
            int resultadoResto1 = passo3(resultadoMult1, c1);
            int resultadoResto2 = passo3(resultadoMult2, c2);
            int resultadoResto3 = passo3(resultadoMult3, c3);
            int resultadoModular1 = passo4(resultadoResto1, c1, i);
            int resultadoModular2 = passo4(resultadoResto2, c2, i);
            int resultadoModular3 = passo4(resultadoResto3, c3, i);
            int resultado = resultadoCong1 * resultadoMult1 * resultadoModular1 + resultadoCong2 * resultadoMult2 * resultadoModular2 + resultadoCong3 * resultadoMult3 * resultadoModular3;
            int multModulos = c1 * c2 * c3;
            int resultadoFinal = resultado % multModulos;
            return resultadoFinal;
}
int calculofinal2(){
    int a1, b1, c1, a2, b2, c2, a3, b3, c3;
            int i = 0;
            printf("Da primeira congruencia:\n");
            printf("Digite o valor de 'a': ");
            scanf("%d", &a1);
            printf("Digite o valor de 'b': ");
            scanf("%d", &b1);
            printf("Digite o valor de 'm': ");
            scanf("%d", &c1);
            printf("Da segunda congruencia:\n");
            printf("Digite o valor de 'a': ");
            scanf("%d", &a2);
            printf("Digite o valor de 'b': ");
            scanf("%d", &b2);
            printf("Digite o valor de 'm':");
            scanf("%d", &c2);
            printf("Da terceira congruencia:\n");
            printf("Digite o valor de 'a': ");
            scanf("%d", &a3);
            printf("Digite o valor de 'b': ");
            scanf("%d", &b3);
            printf("Digite o valor de 'm': ");
            scanf("%d", &c3);
            if (coprimo(c1, c2, c3) != 1){
                printf("Os modulos não são coprimos. Ja que o mdc deles = %d.Portanto o Teorema Chines do Resto nao pode ser usado!", coprimo(c1, c2, c3));
                return 0;
            }
            int resultadoCong1 = passo1(a1, b1, c1, i);
            int resultadoCong2 = passo1(a2, b2, c2, i);
            int resultadoCong3 = passo1(a3, b3, c3, i);
            int resultadoMult1 = passo2(c2, c3);
            int resultadoMult2 = passo2(c1, c3);
            int resultadoMult3 = passo2(c2, c1);
            int resultadoResto1 = passo3(resultadoMult1, c1);
            int resultadoResto2 = passo3(resultadoMult2, c2);
            int resultadoResto3 = passo3(resultadoMult3, c3);
            int resultadoModular1 = passo4(resultadoResto1, c1, i);
            int resultadoModular2 = passo4(resultadoResto2, c2, i);
            int resultadoModular3 = passo4(resultadoResto3, c3, i);
            int resultado = resultadoCong1 * resultadoMult1 * resultadoModular1 + resultadoCong2 * resultadoMult2 * resultadoModular2 + resultadoCong3 * resultadoMult3 * resultadoModular3;
            int multModulos = c1 * c2 * c3;
            int resultadoFinal = resultado % multModulos;
            return resultadoFinal;
}

// MAIN //
int main(){
    printf("\tO que deseja fazer?\n1 - Saber se o numero eh primo!\n2 - Desafie nosso programa! Qual a maior quantidade de primos conseguimos imprimir em 60 segundos?\n3 - Decompor um numero em seus fatores primos!\n4 - Saber o mdc e o mmc de dois numeros com base em seus fatores primos!\n5 - Saber o mdc de dois numeros, usando como base o algoritimo de Euclides!\n6 - Encontre os coeficientes 's' e 't' da combinacao linear 'mdc(a,b) = s * a + t * b'\n7 - Encontre o inverso de 'a mod b'!\n8 - Encontre a congruencia do tipo 'ax' congruente a 'b mod m'\n9 - Encontre a solucao unica de tres congruencias usando o Teorema Chines do Resto!\n\nDigite um numero de 1 - 9 para realizar uma das operacoes: ");
    int escolha;
    scanf("%d", &escolha);
    if (escolha == 1){
        printf("Digite um numero inteiro:\nNumero: ");
        int num;
        scanf("%d", &num);
        if (primo(num)){
            printf("Eh primo!\n");
        }
        else{
            printf("Nao eh primo!\n");
        }
    }
    else if (escolha == 2){
        seg();
    }
    else if (escolha == 3){
        printf("Digite um numero inteiro:\nNumero: ");
        int num;
        scanf("%d", &num);
        printf("A fatoracao do numero eh: ");
        fatorar(num, 2, num);
    }
    else if (escolha == 4){
        printf("Digite dois numeros inteiros:\nPrimeiro numero: ");
        int num1, num2;
        scanf("%d", &num1);
        printf("Segundo numero: ");
        scanf("%d", &num2);
        int res1 = mmc(num1, num2, 2, 1);
        int res2 = mdc(num1, num2, 2, 1);
        printf("O mmc de %d e %d eh = %d\nJa o mdc de %d e %d eh = %d. ", num1, num2, res1, num1, num2, res2);
        if(res2 == 1){
            printf("Portando sao coprimos!");
        }
    }
    else if (escolha == 5){
        printf("Digite dois numeros inteiros:\nPrimeiro numero: ");
        int num1, num2;
        scanf("%d", &num1);
        printf("Segundo numero: ");
        scanf("%d", &num2);
        int resp = mdceuclides(num1, num2);
        printf("O mdc de %d e %d eh = %d. ", num1, num2, resp);
        if(resp == 1){
             printf("Portando sao coprimos!\n");
        }
    }
    else if (escolha == 6){
        printf("Digite o valor de 'a': ");
        int num1, num2;
        scanf("%d", &num1);
        printf("Digite o valor de 'b': ");
        scanf("%d", &num2);
        st(num1, num2, 1);
    }
    else if (escolha == 7){
        printf("Lembrando que 'a' e 'b' precisam ser coprimos entre si!\nDigite o valor de 'a': ");
        int num1, num2;
        scanf("%d", &num1);
        printf("Digite o valor de 'b': ");
        scanf("%d", &num2);
        if(mdceuclides(num1, num2) != 1){
            printf("'a' e 'b' nesse caso não são coprimos, ja que seu mdc eh = %d.", mdceuclides(num1, num2));
            return 0;
        }
        int resp = inverso(num1, num2, 1);
        printf("O inverso de %d mod %d = %d\n", num1, num2, resp);
    }
    else if (escolha == 8){
        int num1, num2, num3;
        printf("Digite o valor de 'a': ");
        scanf("%d", &num1);
        printf("Digite o valor de 'b': ");
        scanf("%d", &num2);
        printf("Digite o v alor de'm': ");
        scanf("%d", &num3);
        int resp = congruencia(num1, num2, num3, 1);
        printf("A congruencia de '%dx' congruente a '%d mod %d' = %d\n", num1, num2, num3, resp, resp, num3);
    }
    else if (escolha == 9){
        printf("As congruencias ja estao definidas?\n1 - Sim!\n2 - Não!\n");
        int escolha2;
        scanf("%d", &escolha2);
        if (escolha2 == 1){
            int resp = calculofinal1();
            printf("A solucao das tres congruencias e %d.\n", resp);
        }
        else if (escolha2 == 2){
            int resp = calculofinal2();
            printf("A solucao das tres congruencias e %d.\n", resp);
        }
    }
    return 0;
}