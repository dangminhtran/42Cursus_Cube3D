int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_uppercase_char(char c)
{
    if (is_uppercase(c))
        return (c);
    else if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (0);
}
