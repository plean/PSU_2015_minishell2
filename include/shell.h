/*
** shell.h for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Tue Mar 29 15:57:05 2016 Jean PLANCHER
** Last update Tue Apr 12 00:33:18 2016 Jean PLANCHER
*/

#ifndef SHELL_H_
# define SHELL_H_

# include "list.h"

# define TMP_FILE ("/tmp/planch_j")
# define MYSH_HISTORY (".mysh_history")
# define MYSH_RC (".myshrc")
# define PATH_ENV ("/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin/")
# define ATC_TAB __attribute__ ((cleanup(free_tab)))
# define ATC_STR __attribute__ ((cleanup(free_str)))

/*
** Shell
*/

char	*cut_space(char *buffer);
int	execute_shell(t_list *list,
		      char *buffer);
void	test_exit(char *buffer, t_list *list);
int	test_builtins(t_list *list, char **tab);
void	commands(char **tab, t_list *list);
void	free_str(char **to_free);
void	free_tab(char ***to_free);
void	do_fork(t_list *list, char **tab, int i);
void	my_commands(t_list *list, char **tab);
int	aff_promt(t_list *list);
void	swap_str(char **str1, const char *str2);
void	move_dir(t_list *list, char **tab);
int	get_fd(char *str);
void	replace_next_word(char *str);
void	check_nb_pipes(const char *str);
void	load_rc(t_list *list);

/*
** Env
*/

void	new_env(t_list *list, char **tab);
void	set_env(t_list *list, char **tab);
void	unset_env(t_list *list, char **tab);

/*
** Alias
*/

void	add_alias(const char **tab);
void	aff_alias(const char *str);

/*
** Error
*/

int	my_ambiguous(const char *buffer);
int	null_command(const char *buffer);
int	relat_path(const char *str);
int	is_a_dir(const char *str);

/*
** Get
*/

int	get_history(int fd);
int	get_stdout(int fd);
int	get_stdin(int fd);
int	get_stderr(int fd);
int	get_pipes(int pipe);
void	reset_fd(void);
int	get_pv(char *str);

/*
** Misc
*/

void	print_list(t_list *list, char c);
t_env	*get_element(const char *env);

/*
** Help
*/

int	test_flags(char *const *argv);
void	aff_help(const char *str);
void	aff_version(const char *str);

#endif /* !SHELL_H_ */
