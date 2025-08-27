/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life-.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:22:38 by mel-hime          #+#    #+#             */
/*   Updated: 2025/08/27 17:22:38 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int main(int ac, char **av)
{
	if (ac != 4)
		return write(1, "error!\n", 7), 1;
	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iterations = atoi(av[3]);

	int arr[2][height + 2][width + 2];
	for (int i = 0; i < 2; i++)
	{
		for (int y = 0; y < height + 2; y++)
		{
			for (int x = 0; x < width + 2; x++)
				arr[i][y][x] = 0;
		}
	}

	int x =1;
	int y = 1;
	int prnt = 0;
	char cmd;
	while (read(0, &cmd, 1) > 0)
	{
		if (cmd == 'w' && y > 1)
			y--;
		else if (cmd == 'a' && x > 1)
			x--;
		else if (cmd == 's' && y < height)
			y++;
		else if (cmd == 'd' && x < width)
			x++;
		else if (cmd == 'x')
			prnt = !prnt;
		if (prnt)
			arr[0][y][x] = 1;
	}

	for(int iter = 0; iter < iterations; iter++)
	{
		for(int h = 1; h <= height; h++)
		{
			for(int w = 1; w <= width; w++)
			{
				int n = 0;
				for (int y = -1; y <= 1; y++)
				{
					for (int x = -1; x <= 1; x++)
					{
						if (!(x == 0 && y == 0))
							n += arr[iter %2][y+h][x+w];
					}
				}
				if (arr[iter%2][h][w] == 1)
				{
					if (n == 2 || n == 3)
						arr[(iter + 1) % 2][h][w] = 1;
					else
					 	arr[(iter + 1) % 2][h][w] = 0;
				}
				else {
					if (n == 3)
						arr[(iter + 1) % 2][h][w] = 1;
					else
					 	arr[(iter + 1) % 2][h][w] = 0;
				}
			}

		}
	}

	for(int i = 1 ; i <= height; i++)
	{
		for(int j = 1; j <= width; j++)
		{
			putchar(arr[iterations % 2][i][j]? '0': ' ');
		}
		putchar('\n');
	}
	return 0;
}