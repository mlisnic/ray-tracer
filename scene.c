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
  sprintf(buf,"scene: bg=%s, obj=\n%s",color_tos(sc.bg),ol_tos(sc.objects));
  return strdup(buf);
}

void scene_show(FILE *f, scene sc)
{
  fprintf(f,"scene: bg=%s, obj=\n%s",color_tos(sc.bg),ol_tos(sc.objects));
}
