#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "raytracer.h"

/* ray_position: interpreting direction as velocity, calculate position
    * of ray r after time t. 
     */
xyz ray_position(ray r, double t)
{
    return xyz_add(r.origin, xyz_scale(t, r.dir));
}

/* ray_tos : return string with ray representation */
char *ray_tos(ray r)
{
  char buf[128];
  int i;
  for (i=0; i<128; i++)
    buf[i] = '\0';
  sprintf(buf, "%s -> %s", xyz_tos(r.origin), xyz_tos(r.dir));
  return strdup(buf);
}

/* ray_show : print ray representation to file */
void ray_show(FILE *f, ray r)
{
  fprintf(f, "%s -> %s", xyz_tos(r.origin), xyz_tos(r.dir));
}
