/*
FICHIER HEADER POUR LE FICHIER POUR LE FICHIER FONCTIONALITE
*/
//main
void onglet_accueil();
void onglet_enregistrer_etudiant();
void onglet_enregistrer_tuteur();
void onglet_afficher_etudiant();
void onglet_afficher_tuteur();
void onglet_afficher_tuteur_etudiant();

//fonctionalite
void conversion_minuscul_majiscule(char *str);
void affichier_etudiant_ou_tuteur(int numero_fichier);
int compter_nombre_ligne(int numero_fichier);
void enregistrer_etudiant(char nom_etudiant[],char postnom_etudiant[],char age_etudiant[],char adresse_etudiant[],char telephone[],int numero_tuteur);
void enregistrer_tuteur(char nom_tuteur[],char profession[],char telephone[]);
char *recuperer_numero_tuteur_etudiant(char chaine[]);
char *recuperer_numero_tuteur_parent(char chaine[]);
void afficher_tuteur_etudiant();