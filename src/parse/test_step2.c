/* Test de l'etape 2 (hors Norme). */
#include <stdio.h>
#include "parsing.h"

static void	t_dbl(const char *s)
{
	double	d;
	int		r;

	d = 0;
	r = parse_double(s, &d);
	printf("double  %-8s -> %d (%g)\n", s, r, d);
}

static void	t_vec(const char *s)
{
	t_vec3	v;
	int		r;

	r = parse_vec3(s, &v);
	printf("vec3    %-10s -> %d (%g,%g,%g)\n", s, r, v.x, v.y, v.z);
}

static void	t_col(const char *s)
{
	t_vec3	v;
	int		r;

	r = parse_color(s, &v);
	printf("color   %-12s -> %d (%g,%g,%g)\n", s, r, v.x, v.y, v.z);
}

static void	t_dir(const char *s)
{
	t_vec3	v;
	int		r;

	r = parse_dir(s, &v);
	printf("dir     %-10s -> %d (%.3f,%.3f,%.3f)\n", s, r, v.x, v.y, v.z);
}

int	main(void)
{
	t_dbl("42"); t_dbl("-3.5"); t_dbl("+0.7"); t_dbl(".5"); t_dbl("5.");
	t_dbl("abc"); t_dbl("1.2.3"); t_dbl(""); t_dbl("-"); t_dbl("12a");
	t_vec("1,2,3"); t_vec("-1.5,0,2"); t_vec("1,2"); t_vec("1,,3");
	t_vec("1,2,3,"); t_vec("1,a,3");
	t_col("255,0,128"); t_col("256,0,0"); t_col("-1,0,0"); t_col("1.5,0,0");
	t_dir("0,0,1"); t_dir("0,0,2"); t_dir("0,0,0"); t_dir("1,1,0");
	return (0);
}
