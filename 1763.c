#include <stdlib.h>
#include <stdio.h>
char **dados;
struct dados{
   char[20] = "brasil"              Feliz Natal!
    alemanha            Frohliche Weihnachten!
    austria             Frohe Weihnacht!
    coreia              Chuk Sung Tan!
    espanha             Feliz Navidad!
    grecia              Kala Christougena!
    estados-unidos      Merry Christmas!
    inglaterra          Merry Christmas!
    australia           Merry Christmas!
    portugal            Feliz Natal!
    suecia              God Jul!
    turquia             Mutlu Noeller
    argentina           Feliz Navidad!
    chile               Feliz Navidad!
    mexico              Feliz Navidad!
    antardida           Merry Christmas!
    canada              Merry Christmas!
    irlanda             Nollaig Shona Dhuit!
    belgica             Zalig Kerstfeest!
    italia              Buon Natale!
    libia               Buon Natale!
    siria               Milad Mubarak!
    marrocos            Milad Mubarak!
    japao               Merii Kurisumasu!
}
int main (){
    char frase[100];  
    
 while (fgets(frase, sizeof(frase), stdin) != NULL) {
        // Remove o caractere de nova linha, se presente
        frase[strcspn(frase, "\n")] = '\0';
         
         if(strcmp(frase , "brasil") == 0)printf("Feliz Natal!")
        
        
    }
}