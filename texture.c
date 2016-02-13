#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

/* dist : calculate unsigned distance between two vectors */
double dist(xyz v, xyz w)
{
  xyz x = xyz_expr(v.x,v.y,0);
  xyz y = xyz_expr(w.x,w.y,0);
  return fabs(xyz_mag(xyz_sub(x,y)));
}

/* tex_green - solid green texture */
color tex_green(object *o, location loc)
{
  return color_expr(0,1,0);
} 

/* poster_red_distance - calculate distance from upper-left-corner, use to 
 * scale from black at upper-left to red at lower-right
 */
color poster_red_distance(object *o, location loc)
{
  if (o->tag!=POSTER) {
    fprintf(stderr,"error(poster_red_distance): not a poster\n");
    exit(1);
  }

  xyz ul = o->o.p.upper_left;
  double d1 = dist(loc, ul);
  double d2 = sqrt(o->o.p.w*o->o.p.w+o->o.p.h*o->o.p.h);
  double red =  d1/d2;
  
  return color_expr(red, 0, 0);
}

/* poster_rgb_distance - calculate distance from upper-left-corner, use to 
 * scale from all red at upper-left to all blue at lower-left, with 
 * green in the middle, and gradations between them.
 */
color poster_rgb_distance(object *o, location loc)
{
  if (o->tag!=POSTER) {
    fprintf(stderr,"error(poster_rgb_distance): not a poster\n");
    exit(1);
  }

  xyz ul = o->o.p.upper_left;
  double d1 = dist(loc, ul);
  double d2 = sqrt(o->o.p.w*o->o.p.w+o->o.p.h*o->o.p.h);
  double red = (d1/d2)<0.5 ? 1 - 2*(d1/d2) : 0;
  double green = 1 - fabs(0.5-(d1/d2))*2;
  double blue = (d1/d2)>0.5 ? ((d1/d2)-0.5)*2 : 0;

  return color_expr(red, green, blue);
}

/* sphere_loc_to_rgb - scale the location so that it maps x, y, z onto r, g, b in 
 * a way that shows gradations in the sphere. You are being given flexibility to 
 * do this in a way that looks interesting to you.
 */
color sphere_loc_to_rgb(object *o, location loc)
{
  if (o->tag!=SPHERE) {
    fprintf(stderr,"error(sphere_loc_to_rgb): not a sphere\n");
    exit(1);
  }

  xyz cen = o->o.s.center;
  double rad = o->o.s.radius;
  xyz pole = xyz_expr(cen.x, cen.y+rad, cen.z);
  double dd = dist(pole,loc);
  double a = asin(dd/rad);
  double d = dd/2;
  double red = (d/rad)<0.5 ? 1 - 2*(d/rad) : 0;
  double green = 1 - fabs(0.5-(d/rad))*2;
  double blue = (d/rad)>0.5 ? ((d/rad)-0.5)*2 : 0;

  return color_expr(red, green, blue);
}

/* sphere_stripes - color the sphere with 4 blue stripes on a white background.
 * the pattern is: WBWBWBWBW. The stripes and background are roughly equal height.
 */
color sphere_horiz_stripes(object *o, location loc)
{
  if (o->tag!=SPHERE) {
    fprintf(stderr,"error(sphere_loc_to_rgb): not a sphere\n");
    exit(1);
  }
 
  xyz cen = o->o.s.center;
  double rad = o->o.s.radius;
  double h = 0.8*M_PI*rad/9;
  double d = fabs(loc.y-cen.y);
  double a = asin(d/rad);
  double dd = rad*a;
  double ddd = dd+(h/2);
  double str = ddd/h;

 /* if ((str>0 && str<1) || (str>2 && str<3))*/
  if ((dd>h/2 && dd<3*h/2) || (dd>5*h/2 && dd<7*h/2))
    return color_expr(0,0,1);
  else
    return color_expr(1,1,1);
}


