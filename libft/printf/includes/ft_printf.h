/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:02:27 by decordel          #+#    #+#             */
/*   Updated: 2021/11/01 20:21:46 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_x_type(unsigned int n, const char *base, int z, size_t *counter);
void	ft_u_type(unsigned int n, int fd, size_t *counter);
size_t	ft_p_type(long n);
size_t	ft_c_type(char c, int fd);
void	ft_d_type(int n, int fd, size_t *counter);
size_t	ft_s_type(char *s, int fd);

#endif
