#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter;

//MENU PRINCIPALE-------------------------------------

void affichageMenu(){

   printf("**************|MENU PRINCIPAL|*******************\n");
   printf("|     1 : Ajouter une ou plusieurs taches.        |\n");
   printf("|     2 : Rechercher les taches.                  |\n");
   printf("|     3 : Modifier une tache.                     |\n");
   printf("|     4 : Supprimer une tache.                    |\n");
   printf("|     5 : Affiche les Statistiques.               |\n");
   printf("|     6 : Afficher la liste de toutes les taches. |\n");
   printf("|     7 : EXIT.                                   |\n");
   printf("***************************************************\n");
   printf("-Choisser un Choix : ");
}

struct deadline{

    int jour;
    int mois;
    int annee;

};

struct Info
{
    char title [25];
    char description[250];
    struct deadline time;
    char statut[50];
    int id;
};

//AFFICHER

void afficher(struct Info Tasks[], int i){

    printf("\n==================================\n");
    printf("|-TITLE : %s\n",Tasks[i].title);
    printf("|-ID #%d\n",Tasks[i].id);
    printf("|-DESCRIPTION :%s\n",Tasks[i].description);
    printf("|%d/%d/%d\n" ,Tasks[i].time . jour, Tasks[i].time . mois, Tasks[i].time . annee);
    printf("|%s\n",Tasks[i].statut);
    printf("===================================\n");
}

//AJOUTER PLUSIEURS DES TACHES---------------------

void plusieursTaches(struct Info Tasks[], int counter, int start){


    for (int i = start; i < counter; i++){


            Tasks[i].id = i + 1;
            printf("Entrer titre de tache %d : ",i+1);
            scanf("%s" ,Tasks[i].title);
            printf("Entrer description de tache %d : ",i+1);
            getchar();

            scanf("%[^\n]s", Tasks[i].description);

            int jour1, mois1, annee1;
            printf("Entrer deadline de tache :");
            printf("Jour: ");
            scanf("%d", &jour1);

            while(jour1<1 || jour1>31){
                printf("Jour:");
                scanf("%d", &jour1);
            }

            printf("Mois: ");
            scanf("%d", &mois1);
            while(mois1<1 || mois1>12){
                printf("Mois:");
                scanf("%d", &mois1);
            }
                printf("Annee: ");
                scanf("%d", &annee1);
            while( annee1<2023 || annee1> 2024){
                printf("Annee: ");
                scanf("%d", &annee1);
            }
             Tasks[i].time.jour=jour1;
             Tasks[i].time.mois=mois1;
             Tasks[i].time.annee=annee1;

            printf("Entrer statut de tache {a_realise},{en_cours},{finalise}: ");
            scanf("%s", Tasks[i].statut);


            while(strcmp(Tasks[i].statut, "a_realise")!= 0&& strcmp(Tasks[i].statut, "en_cours")!= 0&& strcmp(Tasks[i].statut, "finalise")!=0){
                printf("le statut doit etre soit {a_realise} soit {en_cours} soit {finalise} pour etre valider: \n");
                scanf("%s",Tasks[i].statut);
            }

    }

//AFFICHAGE---------------------------------------------------------------

    for(int i = 0; i < counter; i++){

        afficher(Tasks, i);

    }

}
//RECHERCHER LES TACHES par ID--------------------------------------------


int rechechetacheID(struct Info Tasks[], int counter, int idRecherche){
    int check = 0;
    int p = 0;


    for (int i=0; i < counter; i++){

        if( idRecherche == Tasks[i].id){
            printf("la tache existe\n");
            p=i;
            check++;
            break;
        }
    }

        if (check==0){
            printf("la tache n'existe pas");
        }
    return p;
}
//RECHERCHE TACHE par TITRE------------------------------------

void rechechetacheTITRE(struct Info Tasks[], int counter){

    char rechercheTitre[40];
    int check = 0;

    printf("entrez TITRE de tache que vous voulez cherche:");
    scanf("%s", rechercheTitre);

    for (int i=0; i < counter; i++){
            if(strcmp(rechercheTitre, Tasks[i].title)==0){

                afficher(Tasks, i);
            check++;
        }
    }

        if (check==0){
            printf("la tache n'existe pas\n");
        }

}

//modification de tache DESCRIPTION----------------

void modificationDescrition (struct Info Tasks[], int p, char nvDescription[]){

    strcpy(Tasks[p].description, nvDescription);
}

//modification de tache STATUT---------------------

void modificationStatut (struct Info Tasks[], int s, char nvStatut[]){

    strcpy(Tasks[s].statut, nvStatut);
}

//modification de tache DEADLINE-------------------

void modificationDeadline (struct Info Tasks[], int d, struct deadline nvDeadline){


    Tasks[d].time = nvDeadline;
}

// afficher le nombre total de taches----------------

void afficherNombreTotalTaches(int counter){

    printf("Nombre total des taches : %d\n", counter);

}

// afficher le nombre de taches complete et incomplete--------------------

void afficherNombreTachesFinalisesEnCours(struct Info Tasks[], int counter) {

    int arealise = 0;
    int finalisees = 0;
    int enCours = 0;

    for (int i = 0; i < counter; i++) {
        if (strcmp(Tasks[i].statut, "finalise") == 0) {
            finalisees++;
        } else if (strcmp(Tasks[i].statut, "en_cours") == 0) {
            enCours++;
            }
            else if (strcmp(Tasks[i].statut, "a_realise")== 0){
                arealise++;
            }

    }
    printf("Nombre de taches finalises : %d\n", arealise);
    printf("Nombre de taches finalises : %d\n", finalisees);
    printf("Nombre de taches en cours : %d\n", enCours);
}

// afficher le nombre de jours restants ------------------------------

void afficherJoursRestants(struct Info Tasks[], int counter) {

    struct deadline currentDate;
    currentDate.jour = 25; //le jour actuel
    currentDate.mois = 9;  //le mois actuel
    currentDate.annee = 2023; //l'année actuelle

    for (int i = 0; i < counter; i++) {
        int joursRestants = 0;
        if (Tasks[i].time.annee > currentDate.annee ||
           (Tasks[i].time.annee == currentDate.annee && Tasks[i].time.mois > currentDate.mois) ||
           (Tasks[i].time.annee == currentDate.annee && Tasks[i].time.mois == currentDate.mois && Tasks[i].time.jour >= currentDate.jour)) {

    joursRestants = (Tasks[i].time.annee - currentDate.annee) * 365 + (Tasks[i].time.mois - currentDate.mois) * 30 + (Tasks[i].time.jour - currentDate.jour);
        }
        printf("Tache : %s, Jours restants jusqu'au delai : %d jours\n", Tasks[i].title, joursRestants);
    }
}

// supprimer une tache par ID

int supprimerTacheParID(struct Info Tasks[], int counter, int id) {
    int found = 0;

    for (int i = 0; i < counter; i++) {
        if (Tasks[i].id == id) {
            found = 1;


            for (int j = i; j < (counter) - 1; j++) {
                Tasks[j] = Tasks[j + 1];
            }

            --counter; // Reduce the task counter
            printf("Tache avec l'ID %d supprimee avec succes.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Aucune tache trouve avec l'ID %d.\n", id);
    }

    return counter;
}


// Fonction pour trier les taches par ordre alphabetique en utilisant le tri a bulles

void trierParTitre(struct Info Tasks[], int counter) {
    int i, j;
    struct Info temp;

    for (i = 0; i < counter - 1; i++) {
        for (j = 0; j < counter - i - 1; j++) {
            if (strcmp(Tasks[j].title, Tasks[j + 1].title) > 0) {
                temp = Tasks[j];
                Tasks[j] = Tasks[j + 1];
                Tasks[j + 1] = temp;
            }
        }
    }
}

// trier les taches par deadline en utilisant le tri a bulle


void trierParDeadline(struct Info Tasks[], int counter) {
    int i, j;
    struct Info temp;

    for (i = 0; i < counter - 1; i++) {
        for (j = 0; j < counter - i - 1; j++) {
            struct deadline deadline1 = Tasks[j].time;
            struct deadline deadline2 = Tasks[j + 1].time;
            if (deadline1.annee > deadline2.annee || (deadline1.annee == deadline2.annee && deadline1.mois > deadline2.mois) ||
                (deadline1.annee == deadline2.annee && deadline1.mois == deadline2.mois && deadline1.jour > deadline2.jour)) {
                temp = Tasks[j];
                Tasks[j] = Tasks[j + 1];
                Tasks[j + 1] = temp;
            }
        }
    }
}

//afficher les taches dont le deadline est dans 3 jours ou moins------------------

void afficherTachesDeadlineProche(struct Info Tasks[], int counter) {
    struct deadline currentDate;
    currentDate.jour = 25; // Replace with the current day
    currentDate.mois = 9;  // Replace with the current month
    currentDate.annee = 2023; // Replace with the current year

    printf("\nTaches dont le deadline est dans 3 jours ou moins :\n");
    for (int i = 0; i < counter; i++) {
        struct deadline taskDeadline = Tasks[i].time;

        int daysRemaining =
            (taskDeadline.annee - currentDate.annee) * 365 +
            (taskDeadline.mois - currentDate.mois) * 30 +
            (taskDeadline.jour - currentDate.jour);

        if (daysRemaining <= 3) {
            afficher(Tasks, i);
        }
    }
}


int main() {
    struct Info Tasks[20];
    int n, start = 0;
    int idRecherche;
    int p, s;
    char nvDescrition[250];
    char nvStatut[50];
    int jour2, mois2, annee2;
    struct deadline nvDeadline;

    int choix = 0;

    while (choix != 7) {
        affichageMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:

                printf("********AJOUTER UNE OU PLUSIEURS TACHES**********\n");
                printf("- Combien de taches vous voulez ajouter : ");
                scanf("%d", &n);
                counter += n;
                plusieursTaches(Tasks, counter, start);
                start += n;
                break;
            case 2:

                do {
                    printf("**************|CHERCHER UNE TACHE|*********************\n");
                    printf("1- Chercher une tache par ID.\n");
                    printf("2- Chercher une tache par titre.\n");
                    printf("3- Retour au menu principal.\n");
                    printf("Choisissez un choix : ");
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            printf("Entrez l'ID de la tache que vous voulez chercher : ");
                            scanf("%d", &idRecherche);
                            rechechetacheID(Tasks, counter, idRecherche);
                            break;
                        case 2:
                            rechechetacheTITRE(Tasks, counter);
                            break;
                        case 3:

                            break;
                        default:
                            printf("Choix invalide.\n");
                            break;
                    }
                } while (choix != 3);
                break;
            case 3:

                do {
                    printf("************|MODIFICATION DES TACHES|**************\n");
                    printf("1- Modifier la description d'une tache.\n");
                    printf("2- Modifier le statut d'une tache.\n");
                    printf("3- Modifier la deadline d'une tache.\n");
                    printf("4- Retour au Menu Principal.\n");
                    printf("-Choisissez un choix : ");
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:
                            // Modifier la description
                            printf("Entrez l'ID de la tache que vous voulez modifier : ");
                            scanf("%d", &idRecherche);
                            p = rechechetacheID(Tasks, counter, idRecherche);
                            getchar();
                            printf("Entrez la nouvelle description de la tache : ");
                            scanf("%[^\n]s", nvDescrition);
                            modificationDescrition(Tasks, p, nvDescrition);
                            for (int i = 0; i < counter; i++) {
                                afficher(Tasks, i);
                            }
                            break;
                        case 2:
                            // Modifier le statut
                            printf("Entrez l'ID de la tache que vous voulez modifier : ");
                            scanf("%d", &idRecherche);
                            s = rechechetacheID(Tasks, counter, idRecherche);
                            getchar();
                            while (strcmp(nvStatut, "a_realise") != 0 && strcmp(nvStatut, "en_cours") != 0 &&
                                   strcmp(nvStatut, "finalise") != 0) {
                                  printf("Le statut doit etre soit {a_realise}, soit {en_cours}, soit {finalise} pour etre valide.\n");
                                  scanf("%s", nvStatut);
                            }
                            modificationStatut(Tasks, s, nvStatut);
                            for (int i = 0; i < counter; i++) {
                                afficher(Tasks, i);
                            }
                            break;
                        case 3:

                            int d;
                            printf("Entrez l'ID de la tache que vous voulez modifier : ");
                            scanf("%d", &idRecherche);
                            d = rechechetacheID(Tasks, counter, idRecherche);
                            printf("Entrez la nouvelle deadline de la tache :\n");
                            printf("Jour : ");
                            scanf("%d", &jour2);
                            while (jour2 < 1 || jour2 > 31) {
                                printf("Jour : ");
                                scanf("%d", &jour2);
                            }
                            printf("Mois : ");
                            scanf("%d", &mois2);
                            while (mois2 < 1 || mois2 > 12) {
                                printf("Mois : ");
                                scanf("%d", &mois2);
                            }
                            printf("Annee : ");
                            scanf("%d", &annee2);
                            while (annee2 < 2023 || annee2 > 2024) {
                                printf("Annee : ");
                                scanf("%d", &annee2);
                            }
                            nvDeadline.jour = jour2;
                            nvDeadline.mois = mois2;
                            nvDeadline.annee = annee2;
                            modificationDeadline(Tasks, d, nvDeadline);
                            for (int i = 0; i < counter; i++) {
                                afficher(Tasks, i);
                            }
                            break;
                        case 4:

                            break;
                        default:
                            printf("Choix invalide.\n");
                            break;
                    }
                } while (choix != 4);
                break;
            case 4:

                printf("**************|SUPPRIMER UNE TACHE|*******************\n");
                int idASupprimer;
                printf("Entrez l'ID de la tache a supprimer : ");
                scanf("%d", &idASupprimer);
                counter = supprimerTacheParID(Tasks, counter, idASupprimer);
                printf("Nombre total de taches : %d\n", counter);
                for (int i = 0; i < counter; i++) {
                    afficher(Tasks, i);
                }
                    break;


            case 5:

                printf("**************|STATISTIQUES|*******************\n");
                afficherNombreTotalTaches(counter);
                afficherNombreTachesFinalisesEnCours(Tasks, counter);
                afficherJoursRestants(Tasks, counter);
                break;
            case 6:

                do {
                    printf("************|Afficher la liste de toutes les taches|**************\n");
                    printf("1- Trier les taches par ordre alphabetique.\n");
                    printf("2- Trier les taches par deadline.\n");
                    printf("3- Afficher les taches dont le deadline est dans 3 jours ou moins.\n");
                    printf("4- Retour au Menu Principal.\n");
                    printf("Choisissez un choix : ");
                    scanf("%d", &choix);
                    switch (choix) {
                        case 1:

                            trierParTitre(Tasks, counter);
                            printf("Taches triees par ordre alphabetique :\n");
                            for (int i = 0; i < counter; i++) {
                                afficher(Tasks, i);
                            }
                            break;
                        case 2:

                            trierParDeadline(Tasks, counter);
                            printf("Taches triees par deadline :\n");
                            for (int i = 0; i < counter; i++) {
                                afficher(Tasks, i);
                            }
                            break;
                        case 3:

                            afficherTachesDeadlineProche(Tasks, counter);
                            break;
                        case 4:

                            break;
                        default:
                            printf("Choix invalide.\n");
                            break;
                    }
                } while (choix != 4);
                break;
            case 7:

                printf("EXIT avec succes !\n");
                break;
            default:
                printf("Choix invalide. Entrez un nombre valide.\n");
                break;
        }
    }

    return 0;
}
