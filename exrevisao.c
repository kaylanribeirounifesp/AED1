#include <stdio.h>
#include <stdlib.h>

/*void calcularmedias(int alunos[][]){
    int media[4];
    int soma;
    for(int i = 0 ;i <  4 ; i++){
        soma = alunos[i][j];
        for(int j= 0 ; j < 4; j++){
            soma += alunos[i][j];
        }
        media[i] = soma /4;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("media do aluno %d : %d",i ,media[i]);
    }
    

}*/

int main(){
    float alunos[4][4];

    for(int i = 0 ;i <  4 ; i++){
        for(int j = 0 ; j < 4; j++){
        scanf("%lf", &alunos[i][j]);
            
        }
    }

    float media[4];
    float soma = 0;
    int j = 0;
    for(int i = 0 ;i <  4 ; i++){
        for(int j= 0 ; j < 4; j++){
            soma += alunos[i][j];
        }
        media[i] = soma /4;
        soma = 0;
    }

    for (int i = 0; i < 4; i++)
    {
        printf("media do aluno %d : &.2f\n",i + 1,media[i]);
    }
    

}