#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "raytracer.h"

char *object_tos(object o)
{
  switch (o.tag) {
    case SPHERE:
      return sphere_tos(o.o.s);
      break;
    case POSTER:
      return poster_tos(o.o.p);
      break;
    default :
      fprintf(stderr,"error(object_tos): rogue tag\n");
      exit(1);
  }
}

void object_show(FILE *f, object o)
{
  switch (o.tag) {
    case SPHERE:
      sphere_show(f,o.o.s);
      break;
    case POSTER:
      poster_show(f,o.o.p);
      break;
    default :
      fprintf(stderr,"error(object_tos): rogue tag\n");
      exit(1);
  }
}

