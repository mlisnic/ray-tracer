#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "raytracer.h"

sphere sphere_expr(location v, double r, color(*sc)(object *,location), color sh)
{
  sphere s;
  s.center = v;
  s.radius = r;
  s.surface_color = sc;
  s.shine = sh;
  return s;
}

/* sphere_tos : return string with sphere representation */
char *sphere_tos(sphere s)
{
  char buf[256];
  int i;
  for (i=0; i<256; i++)
    buf[i] = '\0';
  char *str = xyz_tos(s.center);
  sprintf(buf, "sph @ %s, r=%.2lf", str, s.radius);
  free(str);
  return strdup(buf);
}

/* sphere_show : print sphere representation to f */
void sphere_show(FILE *f, sphere s)
{
  char *str = xyz_tos(s.center);
  fprintf(f, "sph @ %s, r=%.2lf", str, s.radius);
  free(str);
}

