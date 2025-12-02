/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:27:14 by boksuz            #+#    #+#             */
/*   Updated: 2025/12/02 21:57:07 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef	struct s_myGame
{
	void 	*mix;
	void 	*win;
	char 	**map;			// haritayı tutacak olan 2D array
	// diğer görseller - (zemin coin çıkış)
	void 	*img_wall;		// duvar görseli
	void 	*img_player;	// oyuncu görseli
	int 	map_width;
	int 	map_height;
	int 	player_x;
	int 	player_y;
	int 	collectibles;	// toplanacak coin sayısı
	int 	moves;			// haraket sayısı
}t_game;


#endif
