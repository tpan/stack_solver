/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:20:06 by tpan              #+#    #+#             */
/*   Updated: 2017/05/24 12:40:47 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

#define RED		"\x1b[31m"
#define GREEN	"\x1b[31m"
#define BOLD	"\x1b[1m"
#define UL		"\x1b[4m"
#define RESET	"\x1b[0m"

typedef enum	e_op
{	
	INVALID , SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}				t_op;

typedef struct	s_swap
{
	int			value;
	int			move_req_fw;
	int			move_req_bw;
	int			sb_req_fw;
	int			sb_req_bw;
	int			moves_req;
	int			optimal_path;
	struct s_swap		*next;
}				t_swap;

typedef struct	s_tracker
{
	t_op		current_operation;
	int				a_height;
	int				b_height;
	int				debug;
	int				color;
	int				input_cnt;
	size_t			counter;
	t_swap			*op_log;
}				t_tracker;

/*
**	Control Sections
*/

t_swap			*read_input(char **av, t_tracker *tracker);
void			sort_stack(t_swap **sa, t_swap **sb, t_tracker *tracker);

/*
** Validation and helper functions
*/

int				is_valid(char *arg);
void			print_op_code(int code);
void			print_output(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			stack_append(t_swap **stack, t_swap *to_add);
int				stack_len(t_swap *stack);
void			rot_largest(t_swap **sa, t_swap **sb, t_tracker *tracker);

/*
** Base operations
*/

void			flip_the_top(t_swap **stack);
void			push_on_top(t_swap **s2, t_swap **s1);
void			rotate_forward(t_swap **stack);
void			rotate_backward(t_swap **stack);

/*
** Mix operations and debug options.
*/

void			pa(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			pb(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			sa(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			sb(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			ss(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			ra(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rb(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rr(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rra(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rrb(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			rrr(t_swap **sa, t_swap **sb, t_tracker *tracker);

/*
** Debug / Verbose options
*/

void		print_stacks(t_swap *sa, t_swap *sb, t_tracker *tracker);
void		print_logs(t_tracker *tracker);
void		log_operation(int current_op, t_tracker *tracker);

#endif
