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


#include    "solong.h"

void    check_right(char **map, int x, int y, t_data *data)
{
    if (map[y][x + 1] != '1') //peut-etre un while
    {
        if (map[y][x + 1] == 'E')
            data->e = 0;
        if (map[y][x + 1] == 'P')
            data->p = 0;
        map[y][x + 1] = '1';
        x = x + 1;
        if (data->e == 0 && data->p == 0 && ft_cookiz(map) == 0)
        {
            data->r = 0;
            ft_printf("All items are reachable (bilingue ma gueuuuuuuuuuuuuuuuule)\n");
            return;
        }
        check_left(map, x - 1, y, data);
        check_right(map, x + 1, y, data);
        check_up(map, x, y - 1, data);
        check_down(map, x, y + 1, data);
    }
    else
        return;
}

void    check_left(char **map, int x, int y, t_data *data)
{
    if (map[y][x - 1] != '1') //peut-etre un while
    {
        if (map[y][x - 1] == 'E')
            data->e = 0;
        if (map[y][x - 1] == 'P')
            data->p = 0;
        map[y][x - 1] = '1';
        x = x - 1;
        if (data->e == 0 && data->p == 0 && ft_cookiz(map) == 0)
        {
            data->r = 0;
            ft_printf("All items are reachable (bilingue ma gueuuuuuuuuuuuuuuuule)\n");
            return;
        }
        check_left(map, x - 1, y, data);
        check_right(map, x + 1, y, data);
        check_up(map, x, y - 1, data);
        check_down(map, x, y + 1, data);
    }
    else
        return;
}

void    check_up(char **map, int x, int y, t_data *data)
{
    if (map[y - 1][x] != '1') //peut-etre un while
    {
        if (map[y - 1][x] == 'E')
            data->e = 0;
        if (map[y - 1][x] == 'P')
            data->p = 0;
        map[y - 1][x] = '1';
        y = y - 1;
        if (data->e == 0 && data->p == 0 && ft_cookiz(map) == 0)
        {
            data->r = 0;
            ft_printf("All items are reachable (bilingue ma gueuuuuuuuuuuuuuuuule)\n");
            return;
        }
        check_left(map, x - 1, y, data);
        check_right(map, x + 1, y, data);
        check_up(map, x, y - 1, data);
        check_down(map, x, y + 1, data);
    }
    else
        return;
}

void    check_down(char **map, int x, int y, t_data *data)
{
    if (map[y + 1][x] != '1') //peut-etre un while
    {
        if (map[y + 1][x] == 'E')
            data->e = 0;
        if (map[y + 1][x] == 'P')
            data->p = 0;
        map[y + 1][x] = '1';
        y = y + 1;
        if (data->e == 0 && data->p == 0 && ft_cookiz(map) == 0)
        {
            
            data->r = 0;
            ft_printf("All items are reachable (bilingue ma gueuuuuuuuuuuuuuuuule)\n");
            return;
        }
        check_left(map, x - 1, y, data);
        check_right(map, x + 1, y, data);
        check_up(map, x, y - 1, data);
        check_down(map, x, y + 1, data);
    }
    else
        return;
}

char **ft_tabtabstrdup(char **tab)
{
    int i;
    char **dest;

    i = 0;
    dest = malloc(sizeof(char *) * (ft_tabtabstrlen(tab) + 1));
    while (tab[i])
    {
        dest[i] = ft_strdup(tab[i]);
        i++;
    }
    return(dest);
}


int ft_pathfinder(t_data *data)
{
    int x;
    int y;
    char **map;
    int i;

    i = 0;
    x = data->player.posx;
    y = data->player.posy;
    data->e = 1;
    data->p = 1;
    data->r = 1;

    // map = data->map; tabtabstrlen et strdup par ligne, ne pas oublier de freetabtab
    map = ft_tabtabstrdup(data->map);
    while (map[i])
    {
        ft_printf("i = %d\n", i);
        ft_printf("map pathfinder[%d] : %s\n", i, map[i]);
        i++;
    }
    check_left(map, x - 1, y, data);
    check_right(map, x + 1, y, data);
    check_up(map, x, y - 1, data);
    check_down(map, x, y + 1, data);
    if (data->r == 0)
        return(0);
    else
        return(1);
}