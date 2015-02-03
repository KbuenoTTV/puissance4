

Algorithme recusion

//	On peut utiliser une structure de retour specifique

t_ret		rec (tab, last_drop, deepth)

	// Variable
	int		i = 0;
	t_ret	retour;

	// Condition de victoire
	si (tab + last_drop == victoire)
		return Victoire(deepth);

	// Test des autre coup
	sinon
		tant que (i < largeur du tableau)
		{
			retour = rec (tab, i, deepth + 1)
			sinon
			{
				// Calcul de ponderation
			}
			i++;
		}
}
