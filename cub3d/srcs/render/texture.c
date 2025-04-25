#include "../cub3d.h"

void setup_texture_paths(t_textures *textures)
{
    textures->north_path = textures->no_texture;
    textures->south_path = textures->so_texture;
    textures->west_path = textures->we_texture;
    textures->east_path = textures->ea_texture;
    print_texture_paths(textures);
}

void    load_textures(t_game *game)
{
    game->textures.tex_width = 64;
    game->textures.tex_height = 64;
    
    // printf("Loading north texture from path: '%s'\n", game->textures.north_path);
    game->textures.north_img.img = mlx_xpm_file_to_image(
        game->window.mlx_ptr, 
        game->textures.north_path, 
        &game->textures.tex_width, 
        &game->textures.tex_height);
    if (!game->textures.north_img.img)
        exit_error(game, "Failed to load north texture");
    game->textures.north_img.addr = mlx_get_data_addr(
        game->textures.north_img.img, 
        &game->textures.north_img.bits_per_pixel, 
        &game->textures.north_img.size_line, 
        &game->textures.north_img.endian);
    
    game->textures.south_img.img = mlx_xpm_file_to_image(
        game->window.mlx_ptr, 
        game->textures.south_path, 
        &game->textures.tex_width, 
        &game->textures.tex_height);
    if (!game->textures.south_img.img)
        exit_error(game, "Failed to load south texture");
    game->textures.south_img.addr = mlx_get_data_addr(
        game->textures.south_img.img, 
        &game->textures.south_img.bits_per_pixel, 
        &game->textures.south_img.size_line, 
        &game->textures.south_img.endian);

    game->textures.east_img.img = mlx_xpm_file_to_image(
        game->window.mlx_ptr, 
        game->textures.east_path, 
        &game->textures.tex_width, 
        &game->textures.tex_height);
    if (!game->textures.east_img.img)
        exit_error(game, "Failed to load east texture");
    game->textures.east_img.addr = mlx_get_data_addr(
        game->textures.east_img.img, 
        &game->textures.east_img.bits_per_pixel, 
        &game->textures.east_img.size_line, 
        &game->textures.east_img.endian);

    game->textures.west_img.img = mlx_xpm_file_to_image(
        game->window.mlx_ptr, 
        game->textures.west_path, 
        &game->textures.tex_width, 
        &game->textures.tex_height);
    if (!game->textures.west_img.img)
        exit_error(game, "Failed to load west texture");
    game->textures.west_img.addr = mlx_get_data_addr(
        game->textures.west_img.img, 
        &game->textures.west_img.bits_per_pixel, 
        &game->textures.west_img.size_line, 
        &game->textures.west_img.endian);
}


int    get_texture_color(t_image *img, int x, int y)
{
    char    *dst;
    
    if (x < 0 || y < 0)
        return (0);
    
    dst = img->addr + (y * img->size_line + x * (img->bits_per_pixel / 8));
    return (*(unsigned int*)dst);
}


void    cleanup_textures(t_game *game)
{
    if (game->textures.north_img.img)
        mlx_destroy_image(game->window.mlx_ptr, game->textures.north_img.img);
    if (game->textures.south_img.img)
        mlx_destroy_image(game->window.mlx_ptr, game->textures.south_img.img);
    if (game->textures.east_img.img)
        mlx_destroy_image(game->window.mlx_ptr, game->textures.east_img.img);
    if (game->textures.west_img.img)
        mlx_destroy_image(game->window.mlx_ptr, game->textures.west_img.img);
}

// DEBUG
void print_texture_paths(t_textures *textures)
{
    printf("North texture path: '%s'\n", textures->north_path);
    printf("South texture path: '%s'\n", textures->south_path);
    printf("East texture path: '%s'\n", textures->east_path);
    printf("West texture path: '%s'\n", textures->west_path);
}