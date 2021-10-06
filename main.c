#include <stdlib.h>
#include <stdio.h>
#include "fonctionalite.c"

int main(int argc, char *argv[]){
	onglet_accueil();
}
void onglet_accueil(){
	int choix=0;
	printf("===========================================\n");
	printf("     APPLICATION DE GESTION D'ETUDIANT\n");
	printf("===========================================\n");
	printf("MENU:\n");
	printf("-----\n");
	printf("1. enregistrer tuteur\n");
	printf("2. enregistrer etudiant\n");
	printf("3. lister etudiant\n");
	printf("4. lister tuteur\n");
	printf("5. lister tuteur etudiant\n");
	printf("6. quitter\n");
	printf("- tapez votre choix: ");
	scanf("%d",&choix);

	while(choix<1 || choix>6){
		printf("- choix invalide reessayez: ");
		scanf("%d",&choix);
	}
	switch (choix)
	{
	case 1:
		onglet_enregistrer_tuteur();
		break;
	case 2:
		onglet_enregistrer_etudiant();
		break;
	case 3:
		onglet_afficher_etudiant();
		break;
	case 4:
		onglet_afficher_tuteur();
		break;
	case 5:
		onglet_afficher_tuteur_etudiant();
		break;
	case 6:
		printf("good bay !");
		exit;
		break;
	default:
		printf("choix invalide");
		break;
	}
}
void onglet_enregistrer_etudiant(){
	int choix=0;
	printf("===========================================\n");
	printf("             ENREGISTRER ETUDIANT\n");
	printf("===========================================\n");

	//Etudiant enregistrement
	char *nom_etudiant=strdup("");
	char *postnom_etudiant=strdup("");
	char *age_etudiant=strdup("");
	char *adresse_etudiant=strdup("");
	char *telephone=strdup("");
	int numero_tuteur=1;
	printf("tapez le nom: ");
	while (getchar() != '\n');
	scanf("%[^\n]",nom_etudiant);

	printf("tapez le postnom: ");
	while (getchar() != '\n');
	scanf("%[^\n]",postnom_etudiant);

	printf("tapez l'age: ");
	while (getchar() != '\n');
	scanf("%[^\n]",age_etudiant);

	printf("tapez l'adresse: ");
	while (getchar() != '\n') ;
	scanf("%[^\n]",adresse_etudiant);

	printf("tapez le telephone: ");
	while (getchar() != '\n');
	scanf("%[^\n]",telephone);

	printf("tapez le numero tuteur: ");
	while (getchar() != '\n');
	scanf("%d",&numero_tuteur);

	enregistrer_etudiant(nom_etudiant,postnom_etudiant,age_etudiant,adresse_etudiant,telephone,numero_tuteur);

	printf("MENU:\n");
	printf("-----\n");
	printf("1. enregistrer un autre\n");
	printf("2. retour\n");
	printf("- tapez votre choix: ");
	scanf("%d",&choix);

	while(choix>1 && choix<2){

		printf("- choix invalide reessayez: ");
		scanf("%d",&choix);
	}
	switch (choix)
	{
	case 1:
		onglet_enregistrer_etudiant();
		break;
	case 2:
		onglet_accueil();
		break;
	default:
		printf("choix invalide");
		break;
	}
}
void onglet_enregistrer_tuteur(){
	int choix=0;
	printf("===========================================\n");
	printf("             ENREGISTRER TUTEUR\n");
	printf("===========================================\n");
	
	//Tuteur enregistrement
	char *nom_tuteur=strdup("");
	char *profession=strdup("");
	char *telephone_tuteur=strdup("");
	printf("tapez le nom: ");
	while (getchar() != '\n');
	scanf("%[^\n]",nom_tuteur);
	printf("tapez la profession: ");
	while (getchar() != '\n');
	scanf("%[^\n]",profession);
	printf("tapez le telephone: ");
	while (getchar() != '\n');
	scanf("%[^\n]",telephone_tuteur);
	enregistrer_tuteur(nom_tuteur,profession,telephone_tuteur);

	printf("MENU:\n");
	printf("-----\n");
	printf("1. enregistrer un autre\n");
	printf("2. retour\n");
	printf("- tapez votre choix: ");
	scanf("%d",&choix);

	while(choix>1 && choix<2){

		printf("- choix invalide reessayez: ");
		scanf("%d",&choix);
	}
	switch (choix)
	{
	case 1:
		onglet_enregistrer_tuteur();
		break;
	case 2:
		onglet_accueil();
		break;
	default:
		printf("choix invalide");
		break;
	}
}
void onglet_afficher_etudiant(){
	int choix=0;
	printf("===========================================\n");
	printf("              LISTE ETUDIANT\n");
	printf("===========================================\n");
	affichier_etudiant_ou_tuteur(0);
	printf("MENU:\n");
	printf("-----\n");
	printf("1. retour\n");
	printf("- tapez votre choix: ");
	scanf("%d",&choix);

	while(choix!=1){
		printf("- choix invalide reessayez: ");
		scanf("%d",&choix);
	}
	switch (choix)
	{
	case 1:
		onglet_accueil();
		break;
	default:
		printf("choix invalide");
		break;
	}
}
void onglet_afficher_tuteur(){
	int choix=0;
	printf("===========================================\n");
	printf("              LISTE TUTEUR\n");
	printf("===========================================\n");
	affichier_etudiant_ou_tuteur(1);
	printf("MENU:\n");
	printf("-----\n");
	printf("1. retour\n");
	printf("- tapez votre choix: ");
	scanf("%d",&choix);

	while(choix!=1){
		printf("- choix invalide reessayez: ");
		scanf("%d",&choix);
	}
	switch (choix)
	{
	case 1:
		onglet_accueil();
		break;
	default:
		printf("choix invalide");
		break;
	}
}
void onglet_afficher_tuteur_etudiant(){
	int choix=0;
	printf("===========================================\n");
	printf("          LISTE TUTEUR ETUDIANT\n");
	printf("===========================================\n");
	afficher_tuteur_etudiant();
	printf("MENU:\n");
	printf("-----\n");
	printf("1. retour\n");
	printf("- tapez votre choix: ");
	scanf("%d",&choix);

	while(choix!=1){
		printf("- choix invalide reessayez: ");
		scanf("%d",&choix);
	}
	switch (choix)
	{
	case 1:
		onglet_accueil();
		break;
	default:
		printf("choix invalide");
		break;
	}
}
