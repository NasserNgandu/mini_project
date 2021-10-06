#include <stdlib.h>
#include <stdio.h>
#include "fonctionalite.h"

#include <ctype.h>
#include <string.h>

void conversion_minuscul_majiscule(char *str){ 
	int i; 
	char resultat[100]={0};
	for (i = 0; str[i]; i++){ 
		str[i]=toupper(str[i]);
	}
}
void affichier_etudiant_ou_tuteur(int numero_fichier){
	FILE* fichier = NULL;
	char chaine[100] = "";
	if(numero_fichier==0){
		fichier = fopen("data_bases/etudiant_data.txt", "r");
	}
	else{
		fichier = fopen("data_bases/parent_data.txt", "r");

	}
	if (fichier != NULL){
		while (fgets(chaine, 100, fichier) != NULL){
			if(!strcmp(chaine,"\n")==0){
				printf("%s",chaine);
			}
		}
	}else{
		printf("Erreur d'ouverture du fichier date_bases/etudiant_data.txt");
	}
	fclose(fichier);
}
int compter_nombre_ligne(int numero_fichier){
	int compteur_ligne=0;
	FILE* fichier = NULL;
	char chaine[100] = "";
	if(numero_fichier==0){
		fichier = fopen("data_bases/etudiant_data.txt", "r");
	}
	else{
		fichier = fopen("data_bases/parent_data.txt", "r");

	}
	if (fichier != NULL){
		while (fgets(chaine, 100, fichier) != NULL){
			compteur_ligne++;
		}
	}else{
		printf("Erreur d'ouverture du fichier date_bases/etudiant_data.txt");
	}
	fclose(fichier);
	return compteur_ligne;
}

void enregistrer_etudiant(char nom_etudiant[],char postnom_etudiant[],char age_etudiant[],char adresse_etudiant[],char telephone[],int numero_tuteur){
	conversion_minuscul_majiscule(nom_etudiant);
	conversion_minuscul_majiscule(postnom_etudiant);
	conversion_minuscul_majiscule(adresse_etudiant);

	int taille_postnom=strlen(postnom_etudiant);
	char matricule[100];

	FILE* fichier = NULL;
	fichier = fopen("data_bases/etudiant_data.txt", "a+");
	if (fichier != NULL)
	{
		//Generation et Ajout Matricule
		matricule[0]=nom_etudiant[0];
		matricule[1]=nom_etudiant[1];
		matricule[2]=postnom_etudiant[taille_postnom-2];
		matricule[3]=postnom_etudiant[taille_postnom-1];
		matricule[4]='\0';
		fprintf(fichier,"%s%s\t",matricule,age_etudiant);

		//ajout d'autres informations
		fprintf(fichier,"%s\t%s\t%s\t%s\t%s\t%d\n",nom_etudiant,postnom_etudiant,age_etudiant,adresse_etudiant,telephone,numero_tuteur);
		fclose(fichier);
	}else{
		printf("Erreur d'ouverture du fichier date_bases/etudiant_data.txt");
	}
}
void enregistrer_tuteur(char nom_tuteur[],char profession[],char telephone[]){
	conversion_minuscul_majiscule(nom_tuteur);
	conversion_minuscul_majiscule(profession);
	int numero_tuteur=compter_nombre_ligne(1)+1;

	FILE* fichier = NULL;
	fichier = fopen("data_bases/parent_data.txt", "a+");
	if (fichier != NULL)
	{
		//ajout d'autres informations
		fprintf(fichier,"%d\t%s\t%s\t%s\n",numero_tuteur,nom_tuteur,profession,telephone);
		fclose(fichier);
	}else{
		printf("Erreur d'ouverture du fichier date_bases/parent_data.txt");
	}
}

char *recuperer_numero_tuteur_etudiant(char chaine[]){
	int i; 
	int compte_tabulation=0;
	char *resultat=strdup("");
	for (i = 0; chaine[i]; i++){ 
		if(chaine[i]=='\t'){
			compte_tabulation++;
		}if(compte_tabulation>=6){
			resultat[strlen(resultat)]=chaine[i+1];
		}
	}
	resultat[strlen(resultat)-1]='\0';
	return resultat;
}
char *recuperer_numero_tuteur_parent(char chaine[]){
	int i; 
	int compte_tabulation=0;
	char *resultat=strdup("");
	for (i = 0; chaine[i]; i++){ 
		if(chaine[i]!='\t'){
			resultat[strlen(resultat)]=chaine[i];
		}else{
			break;
		}
	}
	return resultat;
}
void afficher_tuteur_etudiant(){
	FILE* fichier1 = NULL;
	char chaine1[100] = "";
	FILE* fichier2 = NULL;
	char chaine2[100] = "";
	fichier1 = fopen("data_bases/parent_data.txt", "r");
	fichier2 = fopen("data_bases/etudiant_data.txt", "r");
	if (fichier1 != NULL && fichier2 != NULL){
		while (fgets(chaine1, 100, fichier1) != NULL){
			printf("%s",chaine1);
			if(!strcmp(chaine1,"\n")==0){
				printf("etudiant(s):\n");
			}
			while (fgets(chaine2, 100, fichier2) != NULL){
				if (strcmp(recuperer_numero_tuteur_parent(chaine1), recuperer_numero_tuteur_etudiant(chaine2))==0){
					printf("  %s",chaine2);
				}
			}
			rewind(fichier2);
			if(!strcmp(chaine1,"\n")==0){
				printf("-------------------------------------------\n");
			}
		}
	}else{
		printf("Erreur d'ouverture du fichier date_bases/etudiant_data.txt");
	}
	fclose(fichier1);
	fclose(fichier2);
}
