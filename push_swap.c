#include "push_swap.h"

/*cett fonction sert a creer un tableau de structure
qui contient un tableau d'entier et un int*/
t_tab    **make_tab(t_list *a)
{
    int i;
    int len;
    t_tab **struc;

    i = 0;
    len = ft_lstsize(a);
    struc = (t_tab **)malloc(sizeof(t_tab *) * (len + 1));
    if (!struc || !a )
        return (NULL);
    while (i < len)
    {
        struc[i] = (t_tab *)malloc(sizeof(t_tab) * len);
        if (!struc[i])
            return (NULL);
		struc[i]->tabs = (int *)malloc(sizeof(int) * len);
		if (!struc[i]->tabs)
			return (NULL);
        struc[i]->lens = 0;
        i++;
    }
	struc[i] = NULL;
    return(struc);
}
/*cette fonction sert a remplir le tableau de structure*/
void    make_line(t_tab **struc, t_list *a)
{
    int     i;

    if (!struc || !a)
		return ;

	i = 0;
	while (a)
	{
        struc[i]->tabs[0] = a->content;
        struc[i]->lens++;
        chearch_line(struc, i);
		i++;
        a = a->next;
    }
}
/*cette fonction sert a chercher dans les tableaux
précédent si le plus grand nombre est inferieur au nombre actuel*/
void chearch_line(t_tab **struc, int i)
{
    int j;
    int len_max;
    int pos_struc;

    j = i;
    len_max = 1;
    pos_struc = 0;
    while (j >= 0)
    {
        if (struc[i]->tabs[0] > struc[j]->tabs[0])
        {
            if (struc[j]->lens >= len_max)
            {
                len_max = struc[j]->lens +1;
                pos_struc = j;
            }
        }
        j--;
    }
	if (len_max == 1)
		return ;
    fusion_tab(struc, len_max, pos_struc, i);
}
/*cette fonction sert a fusionner les tableaux*/
void fusion_tab(t_tab **struc, int len_max, int pos_struc, int i)
{
    int j;

    j = 1;
	while (j < len_max)
	{
        struc[i]->tabs[j] = struc[pos_struc]->tabs[j - 1];
		struc[i]->lens++;
        j++;
    }
}
/*cette fonction sert a retourner la position du tableau ou la plus grande 
suite est trouver*/
int	found_line(t_tab **struc)
{
	int i;
	int len_max;
	int pos_struc;

	i = 0;
	len_max = 0;
	pos_struc = 0;
	while (struc && struc[i])
	{
		if (struc[i]->lens > len_max)
		{
			len_max = struc[i]->lens;
			pos_struc = i;
		}
		i++;
	}
	return (pos_struc);
}
  