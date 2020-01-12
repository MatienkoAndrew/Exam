/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeruss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 09:24:14 by fgeruss           #+#    #+#             */
/*   Updated: 2019/07/18 11:38:50 by fgeruss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


typedef struct		s_board
{
	int 			size_y;
	int 			size_x;
	int 			sm_x;
	int 			sm_y;
	int 			me_x;
	int 			me_y;
	char 			*me;
	char 			*sm;
	char			**board;
}					t_board;

typedef struct  s_point
{
    int         x;
    int         y;
}               t_point;

void	get_heat(int **bd, int i, int x, int y, int size_x, int size_y)
{
	static int 	k = 1;
	
	if (x + 1 < size_x && bd[y][x + 1] == i)
		bd[y][x] = i + 1;
	if (y + 1 < size_y && bd[y + 1][x] == i)
		bd[y][x] = i + 1;
	if (x + 1 < size_x && y + 1 < size_y && bd[y + 1][x + 1] == i)
		bd[y][x] = i + 1;
	if (x + 1 < size_x && y - 1 >= 0 && bd[y - 1][x + 1] == i)
		bd[y][x] = i + 1;
	if (x - 1 >= 0 && bd[y][x - 1] == i)
		bd[y][x] = i + 1;
	if (y - 1 >= 0 && bd[y - 1][x] == i)
		bd[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && bd[y - 1][x - 1] == i)
		bd[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < size_y && bd[y + 1][x - 1] == i)
		bd[y][x] = i + 1;
}

void	get_map_with_weight(int **bd, int y, int x, int size_x, int size_y)
{
	static char		target = 9;
	static int 		i = 1;
//	char 			prev_tar;

	if (y < 0 || x < 0 || y >= size_y || x >= size_x)
		return ;
	if (bd[y][x] != 0)//(bd[y][x] == 'X' || bd[y][x] == 'x' || bd[y][x] == 'O' \
	//	|| bd[y][x] == 'o'|| bd[y][x] == target)
		return ;
	get_heat(bd, i, x, y, size_x, size_y);
	//i++;
//	if (y < size_y - 1 && x < size_x - 1 && y != 0 && x != 0 \
//		&&(bd[y][x - 1] == 'X' || bd[y][x + 1] == 'X' || bd[y - 1][x] == 'X' \
//		|| bd[y + 1][x] == 'X'|| bd[y - 1][x - 1] == 'X' || bd[y - 1][x + 1] == 'X' \
//		|| bd[y + 1][x - 1] == 'X' || bd[y + 1][x + 1] == 'X'))
//		bd[y][x] = '9';
//	else
//	{
//		//prev_tar = target;
//		if (y < size_y - 1 && x < size_x - 1 && y != 0 && x != 0 \
//		&&(bd[y][x - 1] == target || bd[y][x + 1] == target || bd[y - 1][x] == target \
//		|| bd[y + 1][x] == target || bd[y - 1][x - 1] == target || bd[y - 1][x + 1] == target \
//		|| bd[y + 1][x - 1] == target || bd[y + 1][x + 1] == target))
//			target = (target == '0') ? '0' : --target;
//		bd[y][x] = target;
//	}
	for (int y1 = 0; y1 < size_y; y1++)
	{
		for (int x1 = 0; x1 < size_x; x1++)
		{
			if (x1 != 0)
				printf(" ");
			printf("%i", bd[y1][x1]);
		}
		printf("\n");
	}
	printf("\n\n");
	get_map_with_weight(bd, y + 1, x, size_x, size_y);
	get_map_with_weight(bd, y - 1, x, size_x, size_y);
	i++;
	get_map_with_weight(bd, y, x + 1, size_x, size_y);
	get_map_with_weight(bd, y, x - 1, size_x, size_y);
//	get_map_with_weight(bd, y + 1, x + 1, size_x, size_y);
//	get_map_with_weight(bd, y + 1, x - 1, size_x, size_y);
//	get_map_with_weight(bd, y - 1, x + 1, size_x, size_y);
//	get_map_with_weight(bd, y - 1, x - 1, size_x, size_y);
	
	
//    if (row < 0 || col < 0 || row >= size.y || col >= size.x)
//        return ;
//    if (tab[row][col] == 'F' || tab[row][col] != target)
//        return ;
//    tab[row][col] = 'F';
//    f_fill(tab, size, target, row, col - 1);
//    f_fill(tab, size, target, row, col + 1);
//    f_fill(tab, size, target, row - 1, col);
//    f_fill(tab, size, target, row + 1, col);
}

//void    flood_fill(char **tab, t_point size, t_point begin)
//{
//    char    target;
//
//    target = tab[begin.y][begin.x];
//    f_fill(tab, size, target, begin.y, begin.x);
//}

int 	**get_heat_map(char **bd, int x, int y)
{
	int 	i;
	int 	j;
	int 	**map;
	
	i = -1;
	if (!(map = (int **)malloc(sizeof(int *) * y)))
		return (NULL);
	while (++i < y)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * x)))
			return (NULL);
		j = -1;
		while (++j < x)
		{
			if (bd[i][j] == '.')
				map[i][j] = 0;
			else if (bd[i][j] == 'X')
				map[i][j] = 1;
			else if (bd[i][j] == 'O')
				map[i][j] = -1;
		}
	}
	return (map);
}

char **make_area(char **zone, int _x, int _y)
{
	char **area;
	area = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		area[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j) {
			area[i][j] = zone[i][2 * j];
			printf("%c", area[i][j]);
		}
		printf("\n");
	}
	return (area);
}
int main(void)
{
	char *zone[] = {
		". . . . . . . .",
		". . . . . . . .",
		". X . . . . . .",
		". . . . . . . O",
		". . . . . . . .",
	};
	t_point size  = {8, 5};
//	t_point begin = {6, 1};
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", zone[y][x]);
		}
		printf("\n");
	}
	char **area = make_area(zone, size.x, size.y);
	int	 **map = get_heat_map(area, 8, 5);
	
	
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%i", map[y][x]);
		}
		printf("\n");
	}
	
	
	
	
	get_map_with_weight(map, 2, 2, 8, 5);
//	flood_fill(area, size, begin);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%i", map[y][x]);
		}
		printf("\n");
	}
	free(area);
	return (0);
}

