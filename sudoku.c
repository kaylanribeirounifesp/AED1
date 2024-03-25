#include <stdio.h>
int vvetor( int numero[]){
    for ( int i = 0 ; i < 9 ; i++){
        for(int j = i+1 ; j < 9   ; j++ ) 
            if(numero[i] == numero [j] ){
                return 1;
        }    
    }
    return 0;
}
int vlinha(int m[9][9]){
    int num;
    int i = 0;
    int j = 0 ;
    for ( i = 0; i < 9; i++)
    {
        for (int linha = 0; linha < 9; linha++)
        {  num = m[linha][i];
            for ( j = 0 ; j < linha ; j++)
            {   
                if(num == m[j][i] ){
                return 1;
                } 
            }
         j=0;
        } 
        i++;
    }
    return 0;
}
int vcolunas(int m[9][9]){
    int num;
    int j = 0;
    for ( int coluna = 0; coluna < 9; coluna++)
    {
        for (int  i= 0; i < 9; i++){
            num = m[i][coluna];   //salva o numero
            for ( j = 0 ; j < i ; j++){
                if(num == m[j][coluna] ){   //verifica se é igual o da mesma coluna
                    return 1;
                } 
            }
         j=0;
        }
    }
    return 0;
}
    
    
    int v3x3(int m[9][9],int linha,int coluna){
        int num;
        int numeros[9];
        int l = 0;
         
            for(int i = linha ; i < linha + 3; i++){
                for(int j = coluna ; j < coluna + 3; j++){
                    num = m[i][j];
                    numeros[l] = num;
                    l++;
                    }
            }
            if (vvetor(numeros)== 1){
                    return 1;
            }
            return 0;
        }   
     
    int v9x9(int m[9][9]){
    for ( int i = 0; i < 9; i += 3){
        for (int j = 0; j < 9; j += 3){
            if (v3x3(m, i , j) == 1)return 1;
        }
    } 
    return 0;

    }

int main(){
    int matriz[9][9];
    int inst;
    scanf("%d",&inst);

    for (int n = 0; n < inst; n++)
    {
        for (int i = 0; i < 9; i++)
        { for (int j = 0; j < 9; j++)
            {
                scanf("%d",& matriz[i][j]);
            }
        
        }
           if(vlinha(matriz)==1 || vcolunas(matriz)==1 || v9x9(matriz)==1){
            printf("Instancia %d\nNAO\n\n",n+1);
            }else printf("Instancia %d\nSIM\n\n",n+1);
    }

}

    
    