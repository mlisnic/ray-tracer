#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

char *stage_tos(stage stg)
{
  char buf[512];
  int i;
  for (i=0; i<512; i++)
    buf[i] = '\0';
  sprintf(buf,"%s%s",camera_tos(stg.c),scene_tos(stg.s));
  return strdup(buf);
}

void stage_show(FILE *f, stage stg)
{
  fprintf(f,"%s%s",camera_tos(stg.c),scene_tos(stg.s));
}

/* get_stage : returns a valid stage */
stage get_stage(unsigned int selection)
{
  xyz loc = xyz_expr(0,0,0);
  camera c = {loc, selection, selection};
  color col = color_expr(0,0,0);
  scene s = {col, NULL};
  stage st = {c,s};
  return st;
}

