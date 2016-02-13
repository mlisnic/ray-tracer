#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

char *scene_tos(scene sc)
{
  char buf[512];
  int i;
  for (i=0; i<512; i++)
    buf[i] = '\0';
  char *sm = color_tos(sc.bg);
  char *so = ol_tos(sc.objects);
  sprintf(buf,"scene: bg=%s, obj=\n%s", sm, so);
  free(sm);
  free(so);
  return strdup(buf);
}

void scene_show(FILE *f, scene sc)
{
  char *sm = color_tos(sc.bg);
  char *so = ol_tos(sc.objects);
  
  fprintf(f,"scene: bg=%s, obj=\n%s", sm, so);
  free(sm);
  free(so);
}
