/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decordel <decordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:33:51 by decordel          #+#    #+#             */
/*   Updated: 2022/06/06 21:48:49 by decordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_put_err(char *str);
int		ft_ret_err(char *str, int code);
void	*check_calloc(size_t count, size_t size);

#endif
