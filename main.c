#include <stdio.h>
#include <stdlib.h>



typedef struct {
    int jour;
    char mois[10];
    int annee;
}date;
typedef struct {
    int codeDeVoiture;
    int numeroDeChasse;
    char marqueDelaVoiture[10];
    char model[10];
    date dateDeMiseEnCirculation;
    int nombreDecheveaux;
}voiture;






void ajoutVoiture(voiture *v,int *t){
    printf("entrer code de voiture :");
    scanf("%d",&v->codeDeVoiture);
    printf("entrer le numero de chasse :");
    scanf("%d",&v->numeroDeChasse);
    printf("entrer la marque de la voiture :");
    scanf("%s",v->marqueDelaVoiture);
    printf("entrer le model de la voiture :");
    scanf("%s",v->model);
    printf("entrer la date de mise en circulation de cette voiture :\n");
    printf("le jour : ");
    scanf("%d",&v->dateDeMiseEnCirculation.jour);
    printf("le mois : ");
    scanf("%s",v->dateDeMiseEnCirculation.mois);
    printf("l'annee : ");
    scanf("%d",&v->dateDeMiseEnCirculation.annee);
    printf("la voiture qui a le code : %d a etait enregistrer avec succee\n",v->codeDeVoiture);
    *t =*t +1;
}
void afficheVoiture(voiture *v){
        printf("code de voiture : %d \n", v->codeDeVoiture);
        printf("num de chasse : %d\n", v->numeroDeChasse);
        printf("marque : %s\n", v->marqueDelaVoiture);
        printf("model : %s\n", v->model);

        printf("date   M.E.C : %d/%s/%d\n", v->dateDeMiseEnCirculation.jour,
               v->dateDeMiseEnCirculation.mois, v->dateDeMiseEnCirculation.annee);
    }
void afficheTousLesVoitures(voiture v[],int *t){
    for (int i = 0; i <*t; ++i) {
        printf("affichage des donnees du voiture numero %d\n",i+1);
        afficheVoiture(&v[i]);
    }
    if(*t==0)printf("le tableau est vide \n");
}
void modifierUneVoiture(voiture *v){
    int m;

        printf("1.modifier le codeDeVoiture \n");
        printf("2.modifier le numeroDeChasse\n");
        printf("3.modifier la marque de la voiture\n");
        printf("4.modifier le model\n");
        printf("5.modifier le nembre de cheveaux \n");
        printf("6.modifier la date\n");
        printf("*entrer un nombre : ");
        scanf("%d", &m);
        while (m < 1 || m > 6) {
            printf("entrer un numero entre 1 et 6\n");
            scanf("%d", &m);
        }
        switch (m) {
            case 1:
                printf("l'ancien code de voiture est %d , entrer le nouveau\n", v->codeDeVoiture);
                scanf("%d", &v->codeDeVoiture);
                break;
            case 2:
                printf("l'ancien numero de chasse est %d , entrer le nouveau\n", v->numeroDeChasse);
                scanf("%d", &v->numeroDeChasse);
                break;
            case 3:
                printf("l'ancien marque de la voiture est %s , entrer la nouveau\n", v->marqueDelaVoiture);
                scanf("%s", v->marqueDelaVoiture);
                break;
            case 4:
                printf("l'ancien model est %s , entrer le nouveau\n", v->model);
                scanf("%s", v->model);
                break;
            case 5:
                printf("l'ancien nembre de chevaux est %d , entrer le nouveau\n", v->nombreDecheveaux);
                scanf("%d", &v->nombreDecheveaux);
                break;
            case 6:
                printf("l'ancien date est %d/%s/%d , entrer la nouveau\n", v->dateDeMiseEnCirculation.jour,
                       v->dateDeMiseEnCirculation.mois, v->dateDeMiseEnCirculation.annee);
                printf("jour : ");
                scanf("%d", &v->dateDeMiseEnCirculation.jour);
                printf("mois : ");
                scanf("%s", v->dateDeMiseEnCirculation.mois);
                printf("annee : ");
                scanf("%d", &v->dateDeMiseEnCirculation.annee);
                break;
        }
        printf("les donnees de la voiture devient :\n");
        afficheVoiture(v);
}
int decision(){
    int d;
    printf("entrer le numero d'operation que vous voulez effectuer :\n");
    printf("1.entrer une voiture\n");
    printf("2.voire les donnees d'une voiture\n");
    printf("3.voire les donnees de toutes les voitures\n");
    printf("4.modifier les donnees d'une voiture\n");
    printf("5.quitter le programme\n");
    scanf("%d",&d);
    while (d<1 || d>5){
        printf("entrer un numero entre 1 et 5\n");
        scanf("%d",&d);
    }
    return d;
}
void action(int d,voiture lesVoiture[],int *t,int *nbVoiture){
    int codeDeVoiture,i,check=0;
    switch (d){
        case 1:
            printf("combien de voiture voulez vous ajouter ? (la limite est 10)\n");
            scanf("%d",&i);
            if( *nbVoiture>9 || i>10 ){
                printf("vous avez depasse la limite!\n");

                break;
            }
            for (int j = 0; j <i ; ++j) {
                printf("ajouter la voiture numero %d\n",*nbVoiture+1);
                ajoutVoiture(&lesVoiture[*nbVoiture],t);
                *nbVoiture = (*nbVoiture)+1;
            }
            break;
        case 2:
            printf("entrer le code de voiture\n");
            scanf("%d",&codeDeVoiture);
            for (int k = 0; k <10 ; ++k) {
                if(codeDeVoiture == lesVoiture[k].codeDeVoiture)
                    afficheVoiture(&lesVoiture[k]);
                else if(codeDeVoiture != lesVoiture[k].codeDeVoiture && k==9) {printf("code incorrect\n");
                    break;}
            }
            break;
        case 3:
            afficheTousLesVoitures(lesVoiture,t);
            break;
        case 4:
            printf("entrer le code de voiture\n");
            scanf("%d",&codeDeVoiture);
            for (int l = 0; l <10 ; ++l) {
                if(codeDeVoiture == lesVoiture[l].codeDeVoiture){
                    modifierUneVoiture(&lesVoiture[l]);
                    check=1;
                }
            }
            if(check==0){
                printf("code incorrect\n");
            }

            break;
        case 5:
            exit(0);
    }
}







int main() {
    int retour,track=0,nbVoiture=0;
    voiture lesVoiture[10];
    mainProgramme : action(decision(),lesVoiture,&track,&nbVoiture);
    printf("pour revenir au menu principale tapez 1 , sinon tapez autre chose\n");
    scanf("%d",&retour);
    while (retour==1){
        goto mainProgramme;
    }
    return 0;
}