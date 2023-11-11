#include "main.h"

/**
 * main - file entry point description
 * @ac: argument count
 * @av: argument vector
 * Return: 1 on errno, 0 on success
 */
int main(int ac, char **av)
{
	info_t data = { INFO_INIT };
	int mv = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (mv)
			: "=r" (mv));

	if (ac == 2)
	{
		mv = open(av[1], O_RDONLY);

		if (mv == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open  ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		data->readfd = mv;
	}
	populate_env_list(data);
	read_history(data);
	hsh(data, av);
	return (EXIT_SUCESS);
}
