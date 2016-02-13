#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

char *camera_tos(camera cm)
{
  char buf[256];
  int i;
  for (i=0; i<256; i++)
    buf[i] = '\0';
  sprintf(buf,"cam: h=%d, w=%d @ %s\n",cm.h,cm.w,xyz_tos(cm.loc));
  return strdup(buf);
}

void camera_show(FILE *f, camera cm)
{
  char *s = xyz_tos(cm.loc);
  fprintf(f,"cam: h=%d, w=%d @ %s\n",cm.h,cm.w,s);
  free(s);
}

