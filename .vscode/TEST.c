#include<stdio.h>
  struct Adresse {
    char rue[40];
    char ville[20];
    int code_postal;
};
    struct Personne
    {
     char nom[30];
     int age;
     struct Adresse adresse;
    };
    void ajouter(struct Personne personne[], int index ){
        printf(" Entrer le nom de personne:");
        scanf(" %[^\n]",personne[index].nom);
        printf(" Entrer Age de personne:");
        scanf("%d",&personne[index].age);
        printf(" Entrer le Rue de personne:");
        scanf("%[^\n]",personne[index].adresse.rue);
        printf(" Entrer le Ville de personne:");
        scanf("%[^\n]",personne[index].adresse.ville);
        printf(" Entrer le Code postal de personne:");
        scanf("%d",&personne[index].adresse.code_postal);

    }
int main(){
    struct Personne personne[10];
    int position=0;
    int choix;
    do
    {
         printf("\n ********* Menu  **********\n");
         printf("1.Ajouter un personne\n");
         printf("2.Afficher un personne\n");
         printf("3.Modifier un personne\n");
         printf("4.Supprimer un personne\n");
         printf("5.Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            if (position<10)
            {
                ajouter(personne,position);
                position++;
            }else
            printf("la liste les pleine");
            
            break;
        /*case 2:
            
            break;
        case 3:
           
            break;
        case 4:
          
            break;
        case 5:
           
            break;*/
        default:
            break;
        }
    } while (choix != 5);
    
}