/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:20:06 by tpan              #+#    #+#             */
/*   Updated: 2017/05/26 22:25:53 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

#define RED		"\x1b[31m"
#define GREEN	"\x1b[32m"
#define BOLD	"\x1b[1m"
#define UL		"\x1b[4m"
#define RESET	"\x1b[0m"

typedef enum	e_op
{	
	NOTVALID, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
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
	int				silence;
	int				input_cnt;
	size_t			counter;
	t_swap			*op_log;
}				t_tracker;

t_swap			*read_input_init_stack(char **av, t_tracker *tracker);
int				is_valid(char *arg);
void			print_op_code(int code);
void			print_output(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			append_node(t_swap **stack, t_swap *to_add);
int				stack_len(t_swap *stack);
void			rot_largest(t_swap **sa, t_swap **sb, t_tracker *tracker);
void			flip_the_top(t_swap **stack);
void			push_on_top(t_swap **s2, t_swap **s1);
void			rotate_forward(t_swap **stack);
void			rotate_backward(t_swap **stack);
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
void			print_stacks(t_swap *sa, t_swap *sb, t_tracker *tracker);
void			print_logs(t_swap *sa, t_tracker *tracker);
void			log_operations(int current_op, t_tracker *tracker);
void			execute_instructions(t_swap **stack_a, t_swap **stack_b,
												t_tracker *tracker, t_op op);
void			rot_smallest_to_top(t_swap **sa, t_swap **sb,
												t_tracker *tracker);
void			rot_largest_to_top(t_swap **sa, t_swap **sb,
												t_tracker *tracker);
void			free_stack(t_swap *stack);
char			**parse_args(char **argv);
int				check_duplicates(t_swap *stack);
t_swap			*invalid_input_error(t_swap *sa);
void			calculate_moves(t_swap *sa, t_swap *sb, t_tracker *tracker);
t_swap			*find_optimal_path(t_swap *sa);
t_op			*init_ops(t_swap *element, t_op *ops);

/*
** All SORTS of functions.
*/

void			bubblesque_sort(t_swap **sa, t_swap **sb, t_tracker *tracker);
int				is_sorted(t_swap *stack);
void			sort_stacks(t_swap **sa, t_swap **sb, t_tracker *tracker);
#endif
