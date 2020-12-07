/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:49:30 by ypark             #+#    #+#             */
/*   Updated: 2020/12/06 20:32:07 by hakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>

# define MAX_NUM 1000

typedef struct
{
	char	key[MAX_NUM];
	char	value[MAX_NUM];
}			t_list;

t_list		*g_list;
int			g_size;

int			read_line(int fd, char *buf);
int			line_size(int fd);
int			read_file(const char *str);
int			open_file(const char *str);

int			ft_split(char *str, int l_index);
int			is_space(char ch);
int			count_word(char *str);
char		*ft_copyword(char *str, int *start);

int			check_possible(int l_index);
int			join_value(char *str, int l_index, int *t_index);
int			key_copy(int l_index, char *str);
int			push_keyvalue(char **ptr, int size, int l_index);

int			ft_strlen(char *str);
void		ft_putstr(char *str);
void		ft_strcpy(int startindex, char *src, char *dest);
int			is_zero(char *str);

void		print2(char *str, char *ch, int sp, int *space);
void		print3(char *str, int sp, int *space);
void		init_str(char *c, char *str);
void		printall(char *str, int startpoint, int *space);
void		print_main(char *str);

void		find_str(char *str, int *space);
int			str_cmp(char *key, char *find);

#endif
