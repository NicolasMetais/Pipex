/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmetais <nmetais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:58:08 by nmetais           #+#    #+#             */
/*   Updated: 2025/01/11 16:17:26 by nmetais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h> //if size != 0 pas demande

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		tempo;

	i = 0;
	j = 0;
	if (size != 0)
	{
		while (tab[i] != '\0')
		{	
			j = 0;
			while (tab[j] != '\0')
			{	
				if (tab[i] < tab[j])
				{
					tempo = tab[i];
					tab[i] = tab[j];
					tab[j] = tempo;
				}
			j++;
			}
		i++;
		}
	}
}
/*
int main(void){
	int test[] ={ 4 , 2 ,1 ,12 , 5};
	int size = 5;
	ft_sort_int_tab(test, size);
	int i = 0;
	while(i < size)
	{
	printf("%d ,", test[i]);
	i++;
	}	
}*/
