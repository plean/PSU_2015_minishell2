/*
** my_execve.c for  in /home/planch_j/rendu/PSU/PSU_2015_minishell2/lib/my/
**
** Made by Jean PLANCHER
** Login   <planch_j@epitech.net>
**
** Started on  Wed Apr  6 22:27:54 2016 Jean PLANCHER
** Last update Wed Apr  6 22:31:39 2016 Jean PLANCHER
*/

int	my_execve(const char *filename, char *const argv[],
		  char *const envp[])
{
  int	ret;

  __asm__ __volatile__ ("syscall"
			: "=a" (ret)
			: "a" (59), "D" (filename), "S" (argv), "d" (envp)
			: "rcx", "r11", "cc");
  return (ret);
}
