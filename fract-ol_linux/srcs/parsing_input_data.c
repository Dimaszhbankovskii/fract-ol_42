#include "../includes/fractol.h"

void	free_arr_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		arr[i] = NULL;
		i++;
	}
	free (arr);
	arr = NULL;
}

static char	**dup_arr(char **arr, int len)
{
	char	**out;
	int		i;

	out = (char **)malloc(sizeof(char *) * (len + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = ft_strdup(arr[i + 1]);
		if (!out[i])
		{
			free_arr_char(out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}

void	parsing_input_data(int argc, char **argv, t_fractol *fractol)
{
	fractol->argc = argc - 1;
	fractol->argv = dup_arr(argv, fractol->argc);
	if (!fractol->argv)
		exit (error_mess("Error: parsing data\n", fractol, 1));
}
