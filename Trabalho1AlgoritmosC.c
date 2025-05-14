#include <stdio.h>

int main(void) {
    // Declaracao de variaveis
    int qtdDescargas, qtdEscovacoes, qtdBanhos, qtdPessoasResidencia;
    int torneiraLigada;
    float tempoBanho, consumoVaso, consumoTorneira, consumoChuveiro, mediaTotal;

    printf("=== Calculadora de Consumo de Agua (Apenas Banheiro) ===\n");
    printf("Quantas pessoas moram em sua residencia atualmente? ");
    scanf("%d", &qtdPessoasResidencia);
    
    // Descargas -> sera considerado media de 10l de consumo por descarga
    printf("Quantas descargas sao dadas por dia em sua residencia? ");
    scanf("%d", &qtdDescargas);
    consumoVaso = qtdDescargas * 10;
    
    // Escovacao -> sera considerado media de 1l com torneira desligada e 5l com torneira ligada por escovacao
    printf("Quantas vezes sao escovados os dentes diariamente em sua residencia? ");
    scanf("%d", &qtdEscovacoes);
    printf("Voce escova os dentes com a torneira ligada? (1 = sim, 0 = nao) ");
    scanf("%d", &torneiraLigada);
    if (torneiraLigada == 1) {
    	// consumo de 5 litros por escovacao
    	consumoTorneira = qtdEscovacoes * 5;
	}
	else {
		// consumo de 1 litro por escovacao
		consumoTorneira = qtdEscovacoes * 1;
	}
	
	// Chuveiro -> sera considerado media de 15l de consumo por minuto no banho
    printf("Quantas banhos sao tomados por dia em sua residencia? ");
    scanf("%d", &qtdBanhos);
    printf("Qual a media de tempo dos banhos? ");
    scanf("%f", &tempoBanho);
	// considerando 15l por minuto
    consumoChuveiro = (qtdBanhos * tempoBanho) * 15;
    
    // Media total de consumo de litros por pessoa
    mediaTotal = (consumoVaso + consumoTorneira + consumoChuveiro) / qtdPessoasResidencia;
    
    // Resultados
    printf("\n=== RESULTADOS ===\n");
    printf("Consumo com descargas: %.2f litros\n", consumoVaso);
    printf("Consumo com escovacao de dentes: %.2f litros\n", consumoTorneira);
    printf("Consumo com chuveiro: %.2f litros\n", consumoChuveiro);
    printf("Media total do consumo considerando as pessoas residentes: %.2f litros", mediaTotal);
    
    // Avaliacao de desperdicio
    if (mediaTotal < 200) {
    	printf("\nO consumo de agua em sua residencia esta ok, continue assim e siga as dicas apresentadas abaixo para melhorar mais ainda!\n");
	}
	else if (mediaTotal > 200 && mediaTotal < 300) {
		printf("\nO consumo de agua em sua residencia esta moderado, eh recomendado que seja avaliado melhorias para diminuir o consumo, siga as dicas apresentadas abaixo para melhorar mais ainda!\n");
	}
	else {
		printf("\nO consumo de agua em sua residencia esta elevado!! Eh recomendado que seja avaliado melhorias imediatamente para diminuir o consumo, seguindo as dicas apresentadas abaixo!\n");
	}
	
	printf("\n Dica 1 para melhoria do consumo de agua: Escove os dentes com a torneira desligada!\n");
	printf("\n Dica 2 para melhoria do consumo de agua: Tome banhos rapidos, tentando nao passar mais de 10 minutos no chuveiro!\n");
	printf("\n Dica 3 para melhoria do consumo de agua: Use a descarga com consciencia, apenas quando necessario!\n");

    return (0);
}

