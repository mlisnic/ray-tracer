#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "raytracer.h"

/* reject if any component is outside [0.0,1.0] */
color color_expr(double r, double g, double b)
{
  if (r>1 || r<0 || g>1 || g<0 || b>1 || b<0) {
    fprintf(stderr, "error(color_expr): color not on [0,1]");
    exit (1);
  }
  color c = {r, g, b};
  return c;
}

/* color_modulate : multiply the components or two colors */
/* (r,g,b) * (R,G,B) = (rR,gG,bB) */
color color_modulate(color c1, color c2)
{
  color c = {c1.r*c2.r, c1.g*c2.g, c1.b*c2.b};
  return c;
}

/* edge_case : if less than 0 -> 0, if greater that 1 -> 1, else return */
double edge_case(double x)
{
  if (x<0)
    return 0;
  else
    return (x>1) ? 1 : x;
}

/* color_scale : scale each component by given scalar, but */
/* don't allow any component in the result to fall outside [0,1] */
color color_scale(double s, color c)
{
  color x;
  x.r = edge_case(s*c.r);
  x.g = edge_case(s*c.g);
  x.b = edge_case(s*c.b);
  return x;
}

/* add components of colors, but */
/* don't allow any component in the result to exceed 1 */
color color_add(color c1, color c2)
{
  color x;
  x.r = edge_case(c1.r + c2.r);
  x.g = edge_case(c1.g + c2.g);
  x.b = edge_case(c1.b + c2.b);
  return x;
}

/* color_tos : return string with color */
char *color_tos(color c)
{
  char buf[128];
  int i;
  for (i=0; i<128; i++)
    buf[i] = '\0';
  sprintf(buf, "(%.2lf, %.2lf, %.2lf)", c.r, c.g, c.b);
  return strdup(buf);
}

/* color_show : prints color out */
void color_show(FILE *f, color c)
{
  printf("(%.2lf, %.2lf, %.2lf)", c.r, c.g, c.b);
}

/* color_show_bytes */
/* print three integers on [0,255] with spaces in between and a newline */
/* suitable for use in a PPM */
void color_show_bytes(FILE *f, color c)
{
  int r = (int) 255*c.r;
  int g = (int) 255*c.g;
  int b = (int) 255*c.b;
  fprintf(f,"%d %d %d\n", r, g, b);
}

