#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "raytracer.h"

poster poster_expr(location ulc, double w, double h, color(*sc)(object*,location), color sh)
{
  poster r;
  r.upper_left = ulc;
  r.w = w;
  r.h = h;
  r.surface_color = sc;
  r.shine = sh;
  return r;
}

/* poster_tos : return string representation of poster */
char *poster_tos(poster s)
{
  char buf[256];
  int i;
  for (i=0; i<256; i++)
    buf[i] = '\0';
  sprintf(buf, "pst @ %s, w=%.2lf, h=%.2lf", xyz_tos(s.upper_left), s.w, s.h);
  return strdup(buf);
}

/* poster_show : print poster to f */
void poster_show(FILE *f, poster s)
{
  fprintf(f, "pst @ %s, w=%.2lf, h=%.2lf", xyz_tos(s.upper_left), s.w, s.h);
}

