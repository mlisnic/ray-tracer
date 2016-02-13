#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

/* logical_loc : compute loc in logical plane given physical loc */
location logical_loc(camera c, unsigned int x, unsigned int y)
{
  double cmax = (c.w>c.h) ? c.w : c.h;
  double px = 2/cmax;
  double barv, barh;
  if (c.w == c.h) {
    barv = 0;
    barh = 0;
  } else {
    if (c.w>c.h) {
     barv = 0;
     barh = 1 - c.h*px/2;
    } else {
     barh = 0;
     barv = 1 - c.w*px/2;
    }
  }
  xyz result;
  
  result.x = -1 + barv + x*px + px/2;
  result.y = 1 - barh - y*px - px/2;
  result.z = 0;
  return result;
}

/* trace_ray : return color of object ray hits in the scene */ 
color trace_ray(scene s, ray r)
{
  object obj;
  hit_test temp;
  hit_test hit;
  int i = 0;
  
  while (i==0 && s.objects) {
    hit = intersect(r, s.objects->obj);
    if (hit.miss) { 
      i++;
      obj = s.objects->obj;
    } 
    s.objects = s.objects->next;
  }

  while (s.objects) {
    temp = intersect(r, s.objects->obj);
    if (temp.miss && temp.t<hit.t) {
      hit = temp;
      obj = s.objects->obj;
    }
    s.objects = s.objects->next;
  }

  if (i==0)
    return s.bg;
  
  switch (obj.tag) {
    case SPHERE :
      return (*obj.o.s.surface_color)(&obj, hit.hit_point);
    case POSTER :
      return (*obj.o.p.surface_color)(&obj, hit.hit_point);
    default :
      fprintf(stderr,"error(trace_ray):rogue tag\n");
      exit(1);
  }
}

/* render : runs trace_ray over each pixel, writes colors to file f */
void render(FILE *f, stage g)
{
  int x, y;
  xyz loc;
  ray r;
  r.origin = g.c.loc;

  fprintf(f, "P3 %d %d 255\n", g.c.w, g.c.h);

  for (y=0; y<g.c.h; y++) {
    for (x=0; x<g.c.w; x++) {
      loc = logical_loc(g.c, x, y);
      r.dir = xyz_sub(loc,r.origin);
      color_show_bytes(f, trace_ray(g.s, r));
    }
  }
}
