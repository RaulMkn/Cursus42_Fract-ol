# fract'ol

**fract'ol** es un proyecto desarrollado en el marco del currículo de 42 que tiene como objetivo crear un programa en C capaz de representar fractales de manera gráfica utilizando la librería **miniLibX**.

## Descripción

El proyecto se centra en la generación y visualización de fractales, figuras geométricas que se repiten a diferentes escalas y que son conocidas por su complejidad y belleza. En este programa, se implementan los conjuntos de **Mandelbrot** y **Julia**, permitiendo al usuario explorar estas fascinantes estructuras matemáticas.

## Características

- **Visualización de fractales**: Permite mostrar los conjuntos de Mandelbrot y Julia.
- **Interactividad**:
  - **Zoom**: Acercar y alejar utilizando la rueda del ratón.
  - **Movimiento**: Desplazarse por la imagen usando las flechas del teclado.
  - **Modificación en tiempo real**: En el conjunto de Julia, es posible alterar los parámetros en tiempo real para observar cómo cambian las formas del fractal.
- **Colores personalizables**: Diferentes paletas de colores para resaltar la profundidad y los detalles de los fractales.

## Requisitos

- **Sistema operativo**: macOS o Linux.
- **Librerías**:
  - [miniLibX](https://github.com/42Paris/minilibx-linux)
  - Librería matemática estándar (`-lm`).
- **Compilador**: gcc

## Instalación

1. **Clonar el repositorio**:

   ```bash
   git clone https://github.com/RaulMkn/Cursus42_Fract-ol.git
   cd Cursus42_Fract-ol
   ```

2. **Compilar el proyecto**:

   ```bash
   make
   ```

   Esto generará el ejecutable `fractol`.

## Uso

```bash
./fractol <nombre_del_fractal> [parámetros_opcionales]
```

**Fractales disponibles**:

- `mandelbrot`: Muestra el conjunto de Mandelbrot.
- `julia <Re> <Im>`: Muestra el conjunto de Julia con los parámetros reales (`Re`) e imaginarios (`Im`).

**Ejemplos**:

- Para visualizar el conjunto de Mandelbrot:

  ```bash
  ./fractol mandelbrot
  ```

- Para visualizar el conjunto de Julia con parámetros específicos:

  ```bash
  ./fractol julia -0.4 0.6
  ```

## Controles

- **Rueda del ratón**: Zoom in/out.
- **Flechas del teclado**: Desplazamiento en las direcciones correspondientes.
- **Tecla ESC**: Cerrar la aplicación.
- **Click en la ventana**: Cerrar la aplicación.
