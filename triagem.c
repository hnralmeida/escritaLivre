#include<stdio.h>
#include<stdlib.h>

int main (){
    fflush(stdin);
    float temperatura, i =0, pacientes = 3, gripario = 0, geral= 0;
    char tosse, febre, ar;

    for (i=0; i<pacientes; i++){
        printf("\nO usuario deve respontes S (sim) ou N (nao) para as seguintes perguntas:");

        printf("\nTosse? Febre? Falta de Ar? \n");
        scanf("%c %c %c", &tosse, &febre, &ar);
        fflush(stdin);

        printf("\nInsira a Temperatura: ");
        scanf("%f", &temperatura);

        if( (febre=='n' && ar == 'n' && temperatura < 37.5) ){
            printf("\nRecepcao Geral");
            geral++;
        }
        if(febre=='s' || ar == 's' || temperatura > 37.5){
            printf("\nGripario");
            gripario++;
        }
        printf("\n");
    }

    printf("\nGripario = %.2f \nGeral=%.2f", (100*gripario/pacientes), (100*geral/pacientes) );

return 0;
}
