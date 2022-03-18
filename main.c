#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Etudiant
 {
    int matri ;
    char nom [35] ;
    int moyAlgo ;
    char prenom[40];

};

 int n ;

struct Etudiant Etud ;
 // fonction de recherche

int rech(int num_recherche){
    FILE *fichier ;
    fichier = fopen("Etudiant.txt","r") ;

    while(!feof(fichier))
    {
        fscanf(fichier,"%d ;%s ;%s ;%f \n",&Etud.matri,&Etud.nom,&Etud.prenom,&Etud.moyAlgo) ;
        fflush(stdin) ;

        if (Etud.matri == num_recherche)
        {
            fclose(fichier) ;
            return 1 ;
        }
    }
    fclose(fichier) ;
    return -1 ;
}

// ajout du etudiant

void Ajouter_Etudiant ()
{
    int num ;
    char reponse[20] ;
    while(1)
    {
        FILE *fichier ;
        fichier = fopen("Etudiant.txt","a") ;

        printf("\n\nEntrez le matricule de l'etudiant : ") ;
        scanf("%d",&num) ;

         while(correcteur() == 0)
        {
            printf("\n Saisie invalide veuillez reessayer s'il vous plait !! \n") ;
            printf("\nEntrez a nouveau  le matricule de l'etudiant  :  ") ;
            scanf("%d",&num);
        }

        while(num < 0)
        {
            printf("\n\nEntrez une valeur positif s'il vous plait : ") ;
             scanf("%d",&num) ;
        }
        fflush(stdin) ;


        while (rech(num) == 1 )
        {
            printf("\n\nDesole ! Cet matricule existe deja \n") ;
            printf("\nVeuillez entrez un nouveau matricule : ") ;
            scanf("%d",&num) ;
        }

        // ajout des informations

        Etud.matri = num ;

        printf("\n\nEntrez le nom : ") ;
        scanf("%s",&Etud.nom) ;
         while(correcteur() == 0)
        {
            printf("\nSaisie invalide veuillez reessayer s'il vous plait !! \n") ;
            printf("\nEntrez a nouveau le nom de l'etudiant  :  ") ;
            scanf("%s",&Etud.nom);

        }
        fflush(stdin) ;

        printf("\n\nEntrez le prenom : ") ;
        scanf("%s",&Etud.prenom) ;
         while(correcteur() == 0)
        {
            printf("\n Saisie invalide veuillez reessayer s'il vous plait !! \n") ;
            printf("\nEntrez a nouveau le nom de l'etudiant  :  ") ;
            scanf("%s",&Etud.prenom);

        }
        fflush(stdin) ;

        printf("\n\nEntrez la moyenne en algo: ") ;
        scanf("%f",&Etud.moyAlgo) ;
        while(correcteur() == 0)
        {
            printf("\n Saisie invalide veuillez reessayer s'il vous plait !! \n") ;
            printf("\nEntrez a nouveau la moyenne en algo de l'etudiant  :  ") ;
            scanf("%f",&Etud.moyAlgo);

        }
        fflush(stdin) ;

         while(Etud.moyAlgo < 0)
        {
            printf("\n\nEntrez une valeur positif s'il vous plait: ") ;
             scanf("%f",&Etud.moyAlgo) ;
        }

        printf("\n\n*************** AJOUT EFFECTUE ****************\n") ;

        fprintf(fichier,"%d ;%s ;%s ;%f \n",Etud.matri,Etud.nom,Etud.prenom,Etud.moyAlgo) ;

        fclose(fichier) ;


        printf("\n\nVoulez vous ajouter un autre Etudiant oui ou non ? : ") ;
        scanf("%s",&reponse) ;

        fflush(stdin) ;

        if  (strcmp(reponse,"oui") == 0 || strcmp(reponse,"OUI") == 0  )
        {
            system("cls") ;
            continue ;
        }
        else
        {
            break ;
        }
    }
}


// rechercher un etudiant

void Recherche_Etudiant ()
{

    int compteur = 0 ;
    int num_1 ;
    char reponse[20] ;

    while(1)
    {
        printf("\n\nEntrez le matricule de l'etudiant : ") ;
        scanf("%d",&num_1) ;
           while(correcteur() == 0)
        {
            printf("\n Saisie invalide veuillez reessayer s'il vous plait!! \n") ;
            printf("\nEntrez a nouveau le matricule de l'etudiant  :  ") ;
            scanf("%d",&num_1);

        }

 // verification de la clé

        while (rech(num_1) != 1 )
        {
            printf("\nCet matricule n'existe pas !!!! ") ;

            if (compteur == 2 && rech(num_1) != 1)
            {
                printf("\n\n\tDerniere chance pour entrez un matricule valide !!!!!!\n") ;
            }

            printf("\n\nEntrez un nouveau matricule : ") ;
            scanf("%d",&num_1) ;
            while(correcteur() == 0)
            {
                printf("\n Saisie invalide veuillez reessayer svp !! \n") ;
                printf("\nEntrez a nouveau le matricule de l'etudiant  :  ") ;
                scanf("%d",&num_1);

            }

            compteur = compteur + 1 ;

            if (compteur == 3 && rech(num_1) != 1)
            {
                system("cls") ;
                printf("\n\t Fin du programme car plus de trois saisies invalide !!!\n ") ;
                break ;
            }
        }


        FILE *fichier ;
        fichier = fopen("Etudiant.txt","r") ;

        while(!feof(fichier))

        {
            fscanf(fichier,"%d ;%s ;%s ;%f \n",&Etud.matri,&Etud.nom,&Etud.prenom,&Etud.moyAlgo) ;

            if (Etud.matri == num_1)
            {
                system("cls") ;
                printf("\t__________ INFORMATIONS SUR L'ETUDIANT__________\n\n") ;
                printf(" MATRICULE :\t%d\n\n",Etud.matri) ;
                printf(" NOM : \t%s\n\n",Etud.nom) ;
                printf(" PRENOM : \t%s\n\n",Etud.prenom) ;
                printf(" MOYENNE en ALGO : %f\n\n",Etud.moyAlgo) ;

            }
        }

        printf("\n\nVoulez vous faire une nouvelle recherche oui ou non ? : ") ;
        scanf("%s",&reponse) ;
        fflush(stdin) ;

         if  (strcmp(reponse,"oui") == 0 || strcmp(reponse,"OUI") == 0  )
        {
            system("cls") ;
            continue ;
        }
        else
        {
            break ;
        }
    }
}

// supprimer un etudiant

void Supprimer_Etudiant ()
{
    int compteur = 0 ;
    int num_2 ;
    char reponse_k [10] ;
    char reponse [10] ;

    while(1)
    {
        printf("\n\nEntrez le matricule de l'etudiant a supprimer : ") ;
        scanf("%d",&num_2) ;
        while(correcteur() == 0)
        {
            printf("\n Saisie invalide veuillez reessayer s'il vous plait!! \n") ;
            printf("\nEntrez a nouveau le matricule de l'etudiant  :  ") ;
            scanf("%d",&num_2);

        }

        fflush(stdin) ;

// verification de la clé

        while (rech(num_2) != 1 )
        {
            printf("\nCet matricule n'existe pas !!!! ") ;
            if (compteur == 2)
            {
                printf("\n\nDerniere chance pour entrez un matricule valide !!!!!!\n") ;
            }
            printf("\n\nEntrez un nouveau matricule : ") ;
            scanf("%d",&num_2) ;
            compteur = compteur + 1 ;

            if (compteur == 3)
            {
                system("cls") ;
                printf("\n\t Fin du programme car plus de trois saisies invalide !!! ") ;
                break ;
            }

        }


        if (rech(num_2) == 1)
        {
            printf("\n\nVoulez-vous vraiment supprimer cet etudiant oui ou non ? :  ") ;
            scanf("%s",&reponse) ;
            fflush(stdin) ;

            if (strcmp(reponse,"oui") == 0 || strcmp(reponse,"OUI ") == 0)
            {
                FILE *fichier, *fichier_1 ;
                fichier = fopen("Etudiant.txt","r") ;
                fichier_1 = fopen("Etudiant_NEW.txt","a") ;


                while(!feof(fichier))
                {
                    fscanf(fichier,"%d ;%s ;%s ;%f \n",&Etud.matri,&Etud.nom,&Etud.prenom,&Etud.moyAlgo) ;
                    fflush(stdin) ;

                    if (num_2 != Etud.matri )
                    {
                        fprintf(fichier_1,"%d ;%s ;%s ;%f \n",Etud.matri,Etud.nom,Etud.prenom,Etud.moyAlgo) ;
                    }
                }

                fclose(fichier_1) ;
                fclose(fichier) ;
                remove("Etudiant.txt") ;
                rename("Etudiant_NEW.txt","Etudiant.txt") ;
                printf("\n\t____ SUPPRESSION EFFECTUEE ____\n") ;

            }
        }
            printf("\n\nVoulez vous faire une nouvelle suppression oui ou non ? : ") ;
            scanf("%s",&reponse_k) ;
            fflush(stdin) ;

             if  (strcmp(reponse_k,"oui") == 0 || strcmp(reponse_k,"OUI") == 0  )
            {
                system("cls") ;
                continue ;
            }
            else
            {
                break ;
            }
    }

}

// Modifier un etudiant

void Modifier_Etudiant()
{
    FILE *fichier, *fichier_1 ;
    int num_3 ;
    int reponse_b ;
    int compteur = 0 ;
    char reponse_1 [50] ;
    char reponse [50] ;

    while(1)
    {
        printf("\n\nEntrez le matricule de l'etudiant a modifier : ") ;
        scanf("%d",&num_3) ;
        while(correcteur() == 0)
        {
            printf("\n Saisie invalide veuillez reessayer s'il vous plait!! \n") ;
            printf("\nEntrez a nouveau  le matricule de l'etudiant a modifier  :  ") ;
            scanf("%d",&num_3);
        }

        fflush(stdin) ;

// verification de la clé

        while (rech(num_3) != 1 )
        {
            printf("\nCet matricule n'existe pas !!!! ") ;
            if (compteur == 2)
            {
                printf("\n\nDerniere chance pour entrez une reference valide !!!!!!") ;
            }
            printf("\n\nEntrez un nouveau matricule: ") ;
            scanf("%d",&num_3) ;
            compteur = compteur + 1 ;

            if (compteur == 4)
            {
                system("cls") ;
                printf("\n\t Fin du programme car plus de trois saisies invalides !!! ") ;
                break ;
            }

        }


        if(rech(num_3) == 1)
        {
            printf("\n\nVoulez-vous vraiment modifier cet etudiant oui ou non  ? :  ") ;
            scanf("%s",&reponse_1) ;

            if (strcmp(reponse_1,"oui") == 0 || strcmp(reponse_1,"OUI") == 0 )
            {

                system("cls") ;
                printf("\t__________ INFORMATIONS ACTUELS SUR  L'ETUDIANT__________\n\n") ;
                printf(" MATRICULE :\t%d\n\n",Etud.matri) ;
                printf(" NOM : \t%s\n\n",Etud.nom) ;
                printf(" PRENOM : \t%s\n\n",Etud.prenom) ;
                printf(" MOYENNE en ALGO : %f\n\n",Etud.moyAlgo) ;
                printf("__________________________________________\n\n") ;

                fichier = fopen("Etudiant.txt","r") ;
                fichier_1 = fopen("Etudiant_NEW.txt","a") ;

                while(!feof(fichier))
                {
                    fscanf(fichier,"%d ;%s ;%s ;%f \n",&Etud.matri,&Etud.nom,&Etud.prenom,&Etud.moyAlgo) ;

                    if (Etud.matri== num_3)
                    {

                        printf(" Entrez 1 pour : Modifier le nom \n") ;
                         printf("Entrez 2 pour : Modifier le prenom \n") ;
                        printf(" Entrez 3 pour : Modifier la moyenne en algo \n") ;
                        printf(" Entrez 4 pour : Modifier l'enregistrement complet\n") ;
                        printf("\nEntrez votre choix : ") ;
                        scanf("%d",&reponse_b) ;
                        while(correcteur() == 0)
                            {
                                printf("\n Saisie invalide veuillez reessayer svp !! \n") ;
                                printf("\nEntrez a nouveau votre choix :  ") ;
                                scanf("%d",&reponse_b);
                            }

                        fflush(stdin) ;


                          if (reponse_b == 1)
                          {
                              printf("\nEntrez le nom de l'etudiant : ") ;
                              scanf("%s",&Etud.nom);
                              while(correcteur() == 0)
                                {
                                    printf("\n Saisie invalide veuillez reessayer s'il vous plait!! \n") ;
                                    printf("\nEntrez a nouveau le nouveau nom de l'etudiant :  ") ;
                                    scanf("%s",&Etud.nom);
                                }

                          }


                          if (reponse_b == 2)
                          {
                              printf("\nEntrez le prenom de l'etudiant : ") ;
                              scanf("%s",&Etud.prenom);
                              while(correcteur() == 0)
                                {
                                    printf("\n Saisie invalide veuillez reessayer s'il vous plait !! \n") ;
                                    printf("\nEntrez a nouveau le nouveau prenom de l'etudiant :  ") ;
                                    scanf("%s",&Etud.prenom);
                                }

                          }

                          if (reponse_b == 3)
                          {
                               printf("\nEntrez la moyenne de l'etudiant: ") ;
                               scanf("%f",&Etud.moyAlgo);
                                while(correcteur() == 0)
                                {
                                    printf("\n Saisie invalide veuillez reessayer svp !! \n") ;
                                    printf("\nEntrez a nouveau la moyenne de l'etudiant :  ") ;
                                    scanf("%f",&Etud.moyAlgo);

                                }
                                 while(Etud.moyAlgo < 0)
                                {
                                    printf("\n\nEErreur \n Entrez une valeur positif svp : ") ;
                                     scanf("%f",&Etud.moyAlgo) ;

                                }

                               fflush(stdin) ;
                          }

                          if (reponse_b == 4)
                          {


                               printf("\nEntrez le nom de l'etudiant : ") ;
                               scanf("%s",&Etud.nom);
                               while(correcteur() == 0)
                                {
                                    printf("\n Saisie invalide veuillez reessayer svp !! \n") ;
                                    printf("\nEntrez a nouveau le nom de l'etudiant:  ") ;
                                    scanf("%s",&Etud.nom);

                                }
                               fflush(stdin) ;

                                printf("\nEntrez le prenom de l'etudiant : ") ;
                               scanf("%s",&Etud.prenom);
                               while(correcteur() == 0)
                                {
                                    printf("\n Saisie invalide veuillez reessayer svp !! \n") ;
                                    printf("\nEntrez a nouveau le prenom de l'etudiant:  ") ;
                                    scanf("%s",&Etud.prenom);

                                }
                               fflush(stdin) ;


                               printf("\nEntrez la moyenne de l'etudiant : ") ;
                               scanf("%f",&Etud.moyAlgo);
                                while(correcteur() == 0)
                                {
                                    printf("\n Saisie invalide veuillez reessayer svp !! \n") ;
                                    printf("\nEntrez a nouveau la moyenne de l'etudiant :  ") ;
                                    scanf("%f",&Etud.moyAlgo);

                                }

                                 while(Etud.nom < 0)
                                {
                                    printf("\n\nEntrez une valeur positif s'il vous plait : ") ;
                                     scanf("%s",&Etud.nom) ;
                                }
                               fflush(stdin) ;
                          }

                          while(reponse_b > 4 || reponse_b == 0 )
                          {
                              printf("\n Erreur\nEntrez un reponse valide s'il vous plait !!!\n") ;
                              printf("\n Entrez un nouveau choix  : ") ;
                              scanf("%d",&reponse_b) ;
                               fflush(stdin) ;
                          }
                    }

                    fprintf(fichier_1,"%d ;%s ;%s ;%f \n",Etud.matri,Etud.nom,Etud.prenom,Etud.moyAlgo) ;
                }

                fclose(fichier_1) ;
                fclose(fichier) ;
                remove("Etudiant.txt") ;
                rename("Etudiant_NEW.txt","Etudiant.txt") ;
                printf("\n\n\t____MODIFICATION EFFECTUEE____\n") ;
                 fflush(stdin) ;

            }
            else
            {
                printf("\n\n\t____MODIFICATION ANNULEE____\n") ;
            }

        }

        printf("\n\nVoulez vous modifier un autre etudiant oui ou non ? : ") ;
        scanf("%s",&reponse) ;
        fflush(stdin) ;

        if  (strcmp(reponse,"oui") == 0 || strcmp(reponse,"OUI") == 0  )
        {
            system("cls") ;
            continue ;
        }
        else
        {
            break ;
        }
    }
}
void Afficher_Etudiant ()
{
    system("cls") ;
    FILE *fichier ;
    fichier = fopen ("Etudiant.txt","r") ;

    printf("\nLa liste des etudiants est :  \n\n") ;
    printf("      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n") ;
    printf("     |  MATRICULE \t|     NOM   \t|     PRENOM        |\t MOYENNE en ALGO |\n") ;
    printf("      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n") ;

    while(!feof(fichier))
    {
        fscanf(fichier,"%d ;%s ;%s ;%f \n",&Etud.matri,&Etud.nom,&Etud.prenom,&Etud.moyAlgo) ;
        fflush(stdin) ;

        printf("\n") ;
        printf("\t%d\t",Etud.matri) ;
        printf("\t%s\t",Etud.nom) ;
        printf("\t%s\t",Etud.prenom) ;
        printf("\t%f   \n",Etud.moyAlgo) ;
    }
    fclose(fichier) ;
}

void main ()
{
    int choix_num ;
    char reponse_final [50] ;
    char reponse_final1 [50] ;

    while(1)
    {
        n = 0 ;
        system("cls") ;
        printf("\t---------------------------------------------------------------------------------------\n") ;
        printf("\t|                              PROGRAMME DE MISE A JOUR                              |\n") ;
        printf("\t---------------------------------------------------------------------------------------\n") ;
        printf("\n\n\t ************************* ");
        printf("\n\n\t            MENU         ") ;
        printf("\n\n\t *************************\n\n");
        printf("\n     Entrez 1 pour : Ajouter un etudiant \n") ;
        printf("\n     Entrez 2 pour : Rechercher un  etudiant \n") ;
        printf("\n     Entrez 3 pour : Supprimer un  etudiant \n") ;
        printf("\n     Entrez 4 pour : Modifier un  etudiant \n") ;
        printf("\n     Entrez 5 pour : Afficher tous les  etudiants \n") ;
        printf("\n     Entrez 6 pour : Quitter \n") ;

        printf("\n\n          *******************     FAISONS DONC LES OPERATIONS      ******************* ") ;

        printf("\n\n Vous pouvez saisir votre choix ? : ") ;

        scanf("%d",&choix_num) ;
         while(correcteur() == 0)
         {
            printf("\n Saisie invalide veuillez reessayer svp !! \n") ;
            printf("\nEntrez a nouveau votre choix :  ") ;
            scanf("%d",&choix_num);

        }
         fflush(stdin) ;

        while(choix_num < 1 || choix_num > 6)
        {
            printf("\n\nErreur !!! Entrez un nouveau choix : ") ;
            scanf("%d",&choix_num) ;
            fflush(stdin) ;
        }

        switch (choix_num)
        {
            case 1 : Ajouter_Etudiant () ;
            break ;

            case 2 : Recherche_Etudiant () ;
            break ;

            case 3 : Supprimer_Etudiant () ;
            break ;

            case 4 : Modifier_Etudiant () ;
            break ;

            case 5 : Afficher_Etudiant () ;
            break ;

            case 6 : n = 1 ;
            break ;

        }

        if (n == 1)
        {

            printf("\n\nVoulez vous vraiment quitter oui ou non ? : ") ;
            scanf("%s",&reponse_final1) ;
            while(correcteur() == 0)
             {
                printf("\n Saisie invalide veuillez reessayer s'il vous plait !! \n") ;
                printf("\nEntrez a nouveau votre choix :  ") ;
                scanf("%d",&choix_num);
            }
            fflush(stdin) ;

             if  (strcmp(reponse_final1,"oui") == 0 || strcmp(reponse_final1,"OUI") == 0  )
             {
                    system("cls") ;
                    n = 0 ;
                    break ;
             }
             else
             {
                 n = 2 ;
             }
        }

       if ( n  == 0 )
       {
            printf("\n\nVoulez vous effectuer d'autres operations oui ou non ? : ") ;
            scanf("%s",&reponse_final) ;
            fflush(stdin) ;

            if  (strcmp(reponse_final,"non") == 0 || strcmp(reponse_final,"NON") == 0  )
            {
                n = 0 ;
                system("cls") ;
                break ;
            }
            fflush(stdin) ;

            if (strcmp(reponse_final,"oui") == 0  || strcmp(reponse_final,"OUI") == 0  )
            {
                continue ;
            }
            else
            {
                if  ( n  != 0 )
                system("cls") ;
                n = 0 ;
                break ;
            }
       }
    }
}

void buffer(char *c)
{
    while(*c != 10 )
        {
        *c = getchar();
        }
}

int correcteur(){
    char caractereMemoire = getchar() ;
    if (caractereMemoire != 0 && caractereMemoire != EOF){
        if (caractereMemoire == 10 || caractereMemoire == 32){
            buffer(&caractereMemoire);
            return 1 ;
        }
        else
            {
            buffer(&caractereMemoire);
        return 0 ;
        }
    }
}
