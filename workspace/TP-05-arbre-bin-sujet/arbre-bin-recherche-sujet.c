// COMPILATION:  gcc -W arbre-bin-recherche-sujet.c arbre-bin-recherche-main.c -o out

#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a)
{
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire *a)
{
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e)
{
	ArbreBinaire resultat = malloc(sizeof(ArbreBinaire));
	if (!estVide(resultat))
	{
		resultat->filsDroit = NULL;
		resultat->filsGauche = NULL;
		resultat->val = e;
	}
	return resultat;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) // dessiner les cases mémoires m'a  aidé ici.
{
	ArbreBinaire p = a;
	if (estVide(a))
	{
		return creer(e);
	}

	while (!estVide(a))
	{
		ArbreBinaire t = a; // pour parcourrir l'arbre
		if (a->val == e)
		{
			return p;
		}
		if (a->val > e)
		{
			a = a->filsGauche;
			if (estVide(a))
			{
				t->filsGauche = creer(e);
			}
		}
		if (a->val < e)
		{
			a = a->filsDroit;
			if (estVide(a))
			{
				t->filsDroit = creer(e);
			}
		}
	}
	return p;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive

ArbreBinaire insere_r(ArbreBinaire a, Element e)
{

	if (estVide(a))
	{
		return creer(e);
	}

	else
	{
		if (e == a->val)
		{
			return a;
		}
		if (e < a->val)
		{
			a->filsGauche = insere_r(a->filsGauche, e);
		}
		else
			a->filsDroit = insere_r(a->filsDroit, e);
	}

	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a)
{
	if (estVide(a))
	{
		return 0;
	}
	return (1 + nombreDeNoeud(a->filsDroit) + nombreDeNoeud(a->filsGauche));
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e)
{
	int p = 0;
	if (estVide(a))
	{
		return -1;
	}
	while (!estVide(a))
	{
		if (a->val > e)
		{
			a = a->filsGauche;
		}
		else if (a->val < e)
			a = a->filsDroit;
		else
		{
			return p + 1;
		}
		p++;
	}
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a)
{
	int hauteur_G, hauteur_D, maxN;
	if (estVide(a))
	{
		return 0;
	}
	else
	{
		hauteur_D = hauteur(a->filsDroit);
		hauteur_G = hauteur(a->filsGauche);
		(hauteur_D > hauteur_G) ? (maxN = hauteur_D) : (maxN = hauteur_G);
		return 1 + maxN;
	}
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem)
{
	ArbreBinaire res_pere = a;
	if (estVide(a) || a->val == elem)
	{
		return NULL;
	}
	while (!estVide(a))
	{
		if (a->val == elem)
		{
			return res_pere;
		}
		res_pere = a;
		if (a->val > elem)
		{
			a = a->filsGauche;
		}
		else
		{
			a = a->filsDroit;
		}
	}
}

void afficheRGD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		printf("{");

		printf("%d ", a->val);
		afficheRGD_r(a->filsGauche);
		afficheRGD_r(a->filsDroit);
		printf("}");
	}
}

void afficheGRD_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		printf("{");

		afficheGRD_r(a->filsGauche);
		printf("%d ", a->val);
		afficheGRD_r(a->filsDroit);
		printf("}");
	}
}

void afficheGDR_r(ArbreBinaire a)
{
	if (!estVide(a))
	{
		printf("{");
		afficheGDR_r(a->filsGauche);
		afficheGDR_r(a->filsDroit);
		printf("%d ", a->val);
		printf("}");
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a)
{
	if (estVide(a))
	{
		return NULL;
	}
	while (!estVide(a))
	{

		ArbreBinaire results = a;
		a = a->filsGauche;
		if (estVide(a))
			return results;
	}
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a)
{
	if (estVide(a))
	{
		return NULL;
	}
	while (!estVide(a))
	{

		ArbreBinaire results = a;
		a = a->filsDroit;
		if (estVide(a))
			return results;
	}
}

// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem)
{
	if (estVide(a) || (elem == a->val))
	{
		return a;
	}
	else
	{
		if (elem < a->val)
		{
			return recherche_r(a->filsGauche, elem);
		}
		else
		{
			return recherche_r(a->filsDroit, elem);
		}
	}
	return NULL;
}

// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a, Element x)
{
	ArbreBinaire temp;
	if (estVide(a))  
        return a;
 
    if (x < a->val)  // si element se trouve au sous arbre gauche
        a->filsGauche = supprimer_r(a->filsGauche, x);

    else if (x > a->val) // droit 
        a->filsDroit = supprimer_r(a->filsDroit, x);
 
    else { 
		// si l'arbre contient qu'un fils
        if (estVide(a->filsGauche)) {
            temp = a->filsDroit;
            return temp;
        }
        else if (estVide(a->filsDroit)) {
             temp = a->filsGauche;
            return temp;
        }
		// si l'arbre contient les deux fils 
        temp = min(a->filsDroit); // pour retrouver le noeud successeur (droite) , l'idée je l'ai consulté sur google.
        a->val = temp->val; 
        a->filsDroit = supprimer_r(a->filsDroit, temp->val);
    }
    return a;

}

void detruire_r(ArbreBinaire a)
{
	if (estVide(a))
	{
		return;
	}
	detruire_r(a->filsGauche);
	detruire_r(a->filsDroit);
	free(a);
}
