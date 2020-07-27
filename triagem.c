#include<stdio.h>
#include<stdlib.h>

int main (){
    float temperatura, i =0, pacientes = 2;
    char tosse, febre, ar;
    char* lixo;
    for (i=0; i<pacientes; i++){
        printf("\nO usuario deve respontes S (sim) ou N (não) para as seguintes perguntas:");

        printf("\nTosse? ");
        scanf("%c", &tosse);
        fflush(stdin);

        printf("\nFebre? ");
        scanf("%c", &febre);
        fflush(stdin);

        printf("\nFalta de Ar? ");
        scanf("%c", &ar);
        fflush(stdin);

        printf("\nInsira a Temperatura: ");
        scanf("%f", &temperatura);

        if( (febre=='n' && ar == 'n' && temperatura < 37.5) ){
            printf("\nRecepcao Geral");
        }
        if(febre=='s' || ar == 's' || temperatura > 37.5){
            printf("\nGripario");
        }
        printf("\n");
    }

return 0;
}
