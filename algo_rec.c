

Algorithme recusion

//	On peut utiliser une structure de retour specifique

t_ret{
	
}

t_ret		rec (tab, drop, deepth, color)

	// Variable
	int		i = 0;
	t_ret	retour;

	play(tab, drop, color)
	// Condition de victoire
	si (tab + last_drop*color == victoire)
		return 1;

	// Test des autre coup
	sinon
	{
		tant que (i < largeur du tableau)
		{
			retour = rec (tab, i, deepth + 1)
			i++;
		}
		// Aanlyse des cas suivant
		Si (victoire 100%)
			return 1;
		sinon si (defait > 0%)
			return -1;
		sinon
			return 0;
	}
	unplay(tab, drop, color);
}
