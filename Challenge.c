#include <stdio.h>
#include <string.h>

// Définition des structures ambrique
struct Adresse {
    char rue[40];
    char ville[20];
    int code_postal;
};
//la défition de structure de personne
struct Personne {
    char nom[30];
    int age;
    struct Adresse adresse;
};

// Fonction pour créer une personne
void creerPersonne(struct Personne personnes[], int index) {
    printf("Entrez le nom de la personne : ");
    scanf(" %[^\n]", personnes[index].nom); // Lecture multi-mots
    printf("Entrez l Age de la personne : ");
    scanf("%d", &personnes[index].age);
    printf("Entrez la rue : ");
    scanf(" %[^\n]", personnes[index].adresse.rue);
    printf("Entrez la ville : ");
    scanf(" %[^\n]", personnes[index].adresse.ville);
    printf("Entrez le code postal : ");
    scanf("%d", &personnes[index].adresse.code_postal);
}
// Fonction pour afficher toutes les personnes
void AfficherPersonnes(struct Personne personnes[], int total) {
    if (total == 0) {
        printf("Aucune personne à afficher.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nPersonne %d :\n", i + 1);
        printf("Nom : %s\n", personnes[i].nom);
        printf("Âge : %d\n", personnes[i].age);
        printf("Adresse :\n");
        printf("\tRue : %s\n", personnes[i].adresse.rue);
        printf("\tVille : %s\n", personnes[i].adresse.ville);
        printf("\tCode postal : %d\n", personnes[i].adresse.code_postal);
    }
}


// Fonction pour mettre à jour les informations d'une personne
void mettreAJourPersonne(struct Personne personnes[], int position) {
    printf("Entrez le nouveau nom de la personne : ");
    scanf(" %[^\n]", personnes[position].nom);
    printf("Entrez le nouvel Age de la personne : ");
    scanf("%d", &personnes[position].age);
    printf("Entrez la nouvelle rue : ");
    scanf(" %[^\n]", personnes[position].adresse.rue);
    printf("Entrez la nouvelle ville : ");
    scanf(" %[^\n]", personnes[position].adresse.ville);
    printf("Entrez le nouveau code postal : ");
    scanf("%d", &personnes[position].adresse.code_postal);
}

// Fonction pour supprimer une personne
int supprimerPersonne(struct Personne personnes[], int nbrT, int position) {
//verfier la la positin exist ou non (validation de positin)
    if (position < 0 || position >= nbrT) {
        printf("position invalide.\n");
        return nbrT; 
    }
    //la suppression
    for (int i = position; i < nbrT - 1; i++) {
        personnes[i] = personnes[i + 1];
    }
    
    nbrT--;//Diminue le nombre total d'éléments dans le tableau pour refléter la suppression.

    printf("Personne supprimee avec succes.\n");
    return nbrT; 
}


int main() {
    struct Personne personnes[10]; //  Tableau stockage 
    int choix, position = 0;

    do {
        printf("\nMenu :\n");
        printf("1. Creer une personne\n");
        printf("2. Afficher les informations d une personne\n");
        printf("3. Mettre a jour une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Création d'une personne
                if (position < 10) {
                    creerPersonne(personnes, position);
                    position++;
                } else {
                    printf("Liste de personnes pleine !\n");
                }
                break;

            case 2: // Affichage d'une personne
               if (position > 0) {
                 AfficherPersonnes(personnes, position);
                     } else {
                        printf("Aucune personne à afficher.\n");
                        }
                    break;
            case 3: // Mise à jour d'une personne
                if (position > 0) {
                    int i;
                    printf("Entrez l position de la personne a mettre A jour  : ", position - 1);
                    scanf("%d", &i);
                    if (i >= 0 && i < position) {
                        mettreAJourPersonne(personnes, i);
                    } else {
                        printf("Index invalide.\n");
                    }
                } else {
                    printf("Aucune personne a mettre a jour.\n");
                }
                break;
                // Suppression d'une personne
                 case 4: 
                 //vérifier la tableau contient des personne ou non
                if (position > 0) {
                    int i;// declaration de la position qui doit entrer
                    printf("Entrez la position  de la personne a supprimer (0 a %d) : ", position - 1);
                    scanf("%d", &i);
                    //validation de postion entrer
                    if (i >= 0 && i < position) {
                        position = supprimerPersonne(personnes, position, i);
                    } else {
                        printf("position invalide.\n");
                    }
                } else {
                    printf("Aucune personne a supprimer.\n");
                }

            case 5: // Quitter
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
