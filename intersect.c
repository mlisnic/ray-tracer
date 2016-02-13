#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

/* intersect_sphere : intersect func for spheres */
hit_test intersect_sphere(ray r, object obj)
{
  sphere s = obj.o.s;
  hit_test result;
  xyz A = xyz_sub(r.origin, s.center);
  double B = xyz_dot(A, xyz_norm(r.dir));
  double C = xyz_dot(A, A) - s.radius*s.radius;
  double D = B*B - C;
  double t = -B - sqrt(D);
  ray newr = {r.origin, xyz_norm(r.dir)};
  xyz loc = ray_position(newr,t);
  xyz v = xyz_sub(loc, s.center);
  xyz norm = xyz_norm(v);

  if(D<=0 || t<=0) 
    result.miss = MISS;
  else {
    result.miss = HIT;
    result.t = t;
    result.hit_point = loc;
    result.surf = s.surface_color(&obj, loc);
    result.shine = s.shine;
    result.surf_norm = norm;
  }
  return result;
}

/* intersect_poster : intersect func for posters */
hit_test intersect_poster(ray r, object obj)
{
  poster p = obj.o.p;
  hit_test result;
  xyz n = xyz_expr(0, 0, -1);
  double d = p.upper_left.z;
  xyz rd = xyz_norm(r.dir);
  double t = -(xyz_dot(r.origin, n) + d)/xyz_dot(rd, n);
  ray newr = {r.origin, rd};
  xyz loc = ray_position(newr,t);
  xyz ul = p.upper_left;

  if (t>0 && 
      loc.x>=ul.x && 
      loc.x<=(ul.x+p.w) &&
      loc.y<=ul.y &&
      loc.y>=(ul.y-p.h)) {
    result.miss = HIT;
    result.t = t;
    result.hit_point = loc;
    result.surf = p.surface_color(&obj, loc);
    result.shine = p.shine;
    result.surf_norm = n;
  } else {
    result.miss = MISS;
  }
  return result;
}



/* intersect: check if ray intersects with object, return hit_test */
hit_test intersect(ray r, object obj)
{
  switch (obj.tag) {
    case SPHERE :
      return intersect_sphere(r,obj);
    case POSTER :
      return intersect_poster(r,obj);
    default :
      fprintf(stderr,"error(intersect):rogue tag\n");
      exit(1);
  }
}

