/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:24:23 by amine             #+#    #+#             */
/*   Updated: 2026/10/27 14:30:49 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parsing.h"

static int  is_double_str(const char *s)
{
    int i;
    int digits;

    i = 0;
    digits = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (ft_isdigit(s[i]) && ++digits)
        i++;
    if (s[i] == '.')
        i++;
    while (ft_isdigit(s[i]) && ++digits)
        i++;
    return (digits > 0 && s[i] == '\0');
}

int parse_double(const char *s, double *out)
{
    double  res;
    double  div;
    int     sign;

    if (!is_double_str(s))
        return (0);
    sign = 1;
    if (*s == '-')
        sign = -1;
    if (*s == '-' || *s == '+')
        s++;
    res = 0;
    while (ft_isdigit(*s))
    {
        div /= 10;
        res += (*s++ - '0') * div;
    }
    *out = res * sign;
    return (1);
}

int parse_ranged(const char *s, double min, double max, double *out)
{
    double  v;
    
    if (!parse_double(s, &v) || v < min || v > max)
        return (0);
    *out = v;
    return (1);
}

int parse_positive(const char *s, double *out)
{
    double  v;
    
    if (!parse_double(s, &v) || v <= 0)
        return (0);
    *out = v;
    return (1);
}
