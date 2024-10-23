#include "nascimento.h"
#include <stdio.h>
#include <time.h>

int eh_bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int dias_no_mes(int mes, int ano) {
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    

    if (mes == 2 && eh_bissexto(ano)) {
        return 29;
    }
    return dias_mes[mes - 1];
}

int dias_totais(data_t data) {
    int total_dias = 0;

    for (int ano = 1; ano < data.ano; ano++) {
        total_dias += eh_bissexto(ano) ? 366 : 365;
    }

    for (int mes = 1; mes < data.mes; mes++) {
        total_dias += dias_no_mes(mes, data.ano);
    }

    total_dias += data.dia;

    return total_dias;
}

int dias_de_vida(data_t nasc) {
    time_t t = time(NULL);
    struct tm *data_atual = localtime(&t);

    data_t hoje;
    hoje.dia = data_atual->tm_mday;
    hoje.mes = data_atual->tm_mon + 1; 
    hoje.ano = data_atual->tm_year + 1900; 

    int dias_nascimento = dias_totais(nasc);
    int dias_hoje = dias_totais(hoje);

    return dias_hoje - dias_nascimento;
}

int main() {
    data_t data_nascimento;
    
    printf("Digite o dia de nascimento: ");
    scanf("%d", &data_nascimento.dia);
    
    printf("Digite o mes de nascimento: ");
    scanf("%d", &data_nascimento.mes);
    
    printf("Digite o ano de nascimento: ");
    scanf("%d", &data_nascimento.ano);
    
    int dias = dias_de_vida(data_nascimento);
    
    printf("Voce tem %d dias de vida.\n", dias);
    
    return 0;
}
