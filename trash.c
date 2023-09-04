char    *get_str(int total, int fd)
{
    char    *str;

    str = malloc(sizeof(char) * (total + 1));
    read(fd, str, total);
    ft_printf("get_str (gstr)= %s\n", str);
    return(str);
}

int ft_maping(int fd, t_data *data)
{
	get_number(fd, data);
	data->map = ft_split(data->str, '\n');
	return (0);
}

//int	handle_no_event(void *data)
//{
    /* This function needs to exist, but it is useless for the moment */
//	return(0);
//}


