#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

int close_window()
{
    exit(0);
	return(0);
}

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "MiniLibX");
    
    // Dibujar un píxel
    mlx_pixel_put(mlx, win, 400, 300, 0xFF0000); // Rojo en el centro
    
    // Capturar la tecla ESC para cerrar
    mlx_hook(win, 2, 1L << 0, close_window, NULL);
    
    // Mantener la ventana abierta
    mlx_loop(mlx);
    return (0);
}

