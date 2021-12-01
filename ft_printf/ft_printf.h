#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define TRUE	1
# define FALSE	0

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct Element Element;
struct Element
{
	char *contenu;
	int precision;
	int width;
	int length;
	int begin_end;
	int zero;
	int hint_wp;
	int pos_k;
	int lock;
	int neg;
	int flag;
	int	bsz;
	int hflag;
	int hexa;
	int fhexa;
};

void	init_element(Element *objet);
void	detect_param_elem(const char *set, int *i, va_list ap, Element *objet);
void    rempli_width(const char *set,int *i, Element *objet, va_list ap);
void    rempli_contenu(Element *objet, va_list ap, char c);
int		rempli_preci(const char *set,int *i, Element *objet, va_list ap);
void	insert_char(Element *objet, va_list ap, char c, int i);
void	insert_string(Element *objet, va_list ap);
void	insert_pointer(Element *objet, va_list ap);
void	insert_nbr(Element *objet, va_list ap, int i);
void	insert_hexa(Element *objet, va_list ap, int i);
void	appli_pre_width(Element *objet, int i);
void	modif_number(Element *objet, int i);
void	modif_string(Element *objet);
char	*ft_itoa(long n);
char	*ft_pointoa(unsigned long n, char *set);
size_t	ft_intlen(long sv);
size_t	ft_hexlen(unsigned int sv);
char	*ft_hextoa(unsigned int n, char *set);
int		ft_atoi(const char *str);
char	*ft_ox(char *save, int length);
int		ft_strcmp(const char s2);
int		ft_strlen(const char *set);
int		ft_abs(int x);
int		ft_abs_width(int x, Element *objet);
int		ft_isnum(int c);
int		ft_sup(int a, int b, int c);
int		ft_printf(const char *set, ...);
void	ft_cut(Element *objet);
void	ft_add_zero(Element *objet);
void	ft_add_zero_n(Element *objet);
void	ft_rempli_fi(Element *objet, int range, char sep);
void	ft_rempli_ifi(Element *objet, int range, char sep);
char	*ft_strdup(const char *s);
int		ft_len(Element *objet);
void	ft_add_zero_ox(Element *objet);
void	modif_pointer(Element *objet);
void    ft_cut_ox(Element *objet);
void	ft_rempli_fi_num(Element *objet);
#endif