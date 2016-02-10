#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "raytracer.h"

/* Maxim Lisnic, Lisnic
 * CS 152, Winter 16
 * Project A
 */

xyz xyz_expr(double x, double y, double z)
{
  xyz r = {x, y, z};
  return r;
}

/* xyz_add : add two vectors */
/* (x,y,z) + (X,Y,Z) = (x+X,y+Y,z+Z) */
xyz xyz_add(xyz v1, xyz v2)
{
  xyz r;
  r.x = v1.x + v2.x;
  r.y = v1.y + v2.y;
  r.z = v1.z + v2.z;
  return r;
}

/* xyz_sub : subtract the second vector from the first */
/* (x,y,z) - (X,Y,Z) = (x-X,y-Y,z-Z) */
xyz xyz_sub(xyz v1, xyz v2)
{
  xyz r;
  r.x = v1.x - v2.x;
  r.y = v1.y - v2.y;
  r.z = v1.z - v2.z;
  return r;
}

/* xyz_neg : negate a vector */
/* -(x,y,z) = (-x,-y,-z) */
xyz xyz_neg(xyz v)
{
  xyz r;
  r.x = -v.x;
  r.y = -v.y;
  r.z = -v.z;
  return r;
}

/* xyz_scale : scale the components of a vector by scalar s */
/* s(x,y,z) = (sx,sy,sz) */
xyz xyz_scale(double s, xyz v)
{
  xyz r;
  r.x = s*v.x;
  r.y = s*v.y;
  r.z = s*v.z;
  return r;
}

/* xyz_dot : compute the dot product of two vectors */
/* (x,y,z) dot (X,Y,Z) = xX+yY+zZ */
double xyz_dot(xyz v1, xyz v2)
{
  double r;
  r = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
  return r;
}

/* xyz_mag : compute the magnitude of a vector */
/* the square root of the sum of the squares of the components */
double xyz_mag(xyz v)
{
  double r;
  r = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
  return r;
}

/* xyz_norm : normalize the vector */
/* i.e., a vector pointing in the same direction whose magnitude is 1 */
/* - normalize a vector by scaling by 1 over its magnitude */
/* - if a vector's magnitude is zero, it can't be normalized; return it */
xyz xyz_norm(xyz v)
{
  double m = xyz_mag(v);
  if (m==0)
    return v;
  else 
    return xyz_scale(1/m, v);
}

/* xyz_tos : returns string with xyz */
char *xyz_tos(xyz v)
{
  char buf[128];
  int i;
  for (i=0; i<128; i++) 
    buf[i] = '\0';
  sprintf(buf, "(%.2lf, %.2lf, %.2lf)", v.x, v.y, v.z);
  return strdup(buf);
}

/* xyz_show : prints xyz to screen */
void xyz_show(FILE *f, xyz v)
{
  fprintf(f,"(%.2lf, %.2lf, %.2lf)", v.x, v.y, v.z);
}


