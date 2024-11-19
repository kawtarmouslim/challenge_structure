#include <stdio.h>
#include <string.h>

// Définition des structures Adresse et Personne
struct Adresse {
    char rue[40];
    char ville[20];
    int code_postal;
};

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
void mettreAJourPersonne(struct Personne personnes[], int index) {
    printf("Entrez le nouveau nom de la personne : ");
    scanf(" %[^\n]", personnes[index].nom);
    printf("Entrez le nouvel Age de la personne : ");
    scanf("%d", &personnes[index].age);
    printf("Entrez la nouvelle rue : ");
    scanf(" %[^\n]", personnes[index].adresse.rue);
    printf("Entrez la nouvelle ville : ");
    scanf(" %[^\n]", personnes[index].adresse.ville);
    printf("Entrez le nouveau code postal : ");
    scanf("%d", &personnes[index].adresse.code_postal);
}

// Fonction pour supprimer une personne
void supprimerPersonne(struct Personne personnes[], int *index, int supprimerIndex) {
    for (int i = supprimerIndex; i < *index - 1; i++) {
        personnes[i] = personnes[i + 1];
    }
    (*index)--; // Réduction du nombre total de personnes
    printf("Personne supprimee avec succes.\n");
}


int main() {
    struct Personne personnes[10]; //  Tableau de 10 personnes
    int choix, index = 0;

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
                if (index < 10) {
                    creerPersonne(personnes, index);
                    index++;
                } else {
                    printf("Liste de personnes pleine !\n");
                }
                break;

            case 2: // Affichage d'une personne
               if (index > 0) {
                 AfficherPersonnes(personnes, index);
                     } else {
                        printf("Aucune personne à afficher.\n");
                        }
                    break;
            case 3: // Mise à jour d'une personne
                if (index > 0) {
                    int i;
                    printf("Entrez l index de la personne a mettre A jour  : ", index - 1);
                    scanf("%d", &i);
                    if (i >= 0 && i < index) {
                        mettreAJourPersonne(personnes, i);
                    } else {
                        printf("Index invalide.\n");
                    }
                } else {
                    printf("Aucune personne a mettre a jour.\n");
                }
                break;

            case 4: // Suppression d'une personne
                if (index > 0) {
                    int i;
                    printf("Entrez l index de la personne a supprimer  : ", index - 1);
                    scanf("%d", &i);
                    if (i >= 0 && i < index) {
                        supprimerPersonne(personnes, &index, i);
                    } else {
                        printf("Index invalide.\n");
                    }
                } else {
                    printf("Aucune personne a supprimer.\n");
                }
                break;

            case 5: // Quitter
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
        }
    } while (choix != 5);

    return 0;
}
