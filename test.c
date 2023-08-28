#include <stdio.h>

int	ft_tabtabstrlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

int main()
{
	char *tab[11];
	int i;

	tab[0] = "test";
	tab[1] = "test";
	tab[2] = "test";
	tab[3] = "test";
	tab[4] = "test";
	tab[5] = "test";
	tab[6] = "test";
	tab[7] = "test";
	tab[8] = "test";
	tab[9] = "test";
	tab[10] = "test";
	

	i = ft_tabtabstrlen(tab);
	printf("%d\n", i);
	return (0);
}