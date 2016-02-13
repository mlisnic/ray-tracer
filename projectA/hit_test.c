#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

char *hit_test_tos(hit_test t)
{
  char buf[256];
  int i;
  for (i=0; i<256; i++)
    buf[i] = '\0';
  char *s = xyz_tos(t.hit_point);
  sprintf(buf,"hit_test: hit=%d, t=%.2lf @%s\n",t.miss,t.t,s);
  free(s);
  return strdup(buf);
}

void hit_test_show(FILE *f, hit_test t)
{
  char *s = xyz_tos(t.hit_point);
  fprintf(f,"hit_test: hit=%d, t=%.2lf @%s\n",t.miss,t.t,s);
  free(s);
}




