/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaayoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:32:08 by klaayoun          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:10 by klaayoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef FD_BUFFER_SIZE
#  define FD_BUFFER_SIZE 1024
# endif

# if FD_BUFFER_SIZE < 1024
#  undef FD_BUFFER_SIZE
#  define FD_BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strndup(const char *src, size_t n);
ssize_t	ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *s);

#endif
