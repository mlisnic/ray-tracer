#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

int main()
{
  camera cam = {xyz_expr(0,0,-5), 120, 120};
  color bg = color_expr(0,0,0.25);
  poster p = poster_expr(xyz_expr(-1.5,1.5,4.5), 3, 3,
      poster_red_distance, color_expr(0,0,0));
  poster pp = poster_expr(xyz_expr(-1.5,1.5,4.5), 9, 9,
      tex_green, color_expr(0,0,0));
  sphere s = sphere_expr(xyz_expr(-0.5,0.7,3),0.5,
      sphere_horiz_stripes, color_expr(0,0,0));
  sphere ss = sphere_expr(xyz_expr(1,0,4),1,
      tex_green, color_expr(0,0,0));
  sphere sss = sphere_expr(xyz_expr(0,0,3),1,
      sphere_loc_to_rgb, color_expr(0,0,0));
  object o1 = {POSTER, {.p = p}, NULL};
  object o2 = {SPHERE, {.s = sss}, NULL};
  object o3 = {SPHERE, {.s = s}, NULL};
  obj_list *os = ol_singleton(o1);
  obj_list *os2 = ol_singleton(o2);
  obj_list *os3 = ol_cons(o2, ol_cons(o3,os));
  scene scn;
  scn.bg = bg;
  scn.objects = os3;
  stage stg = {cam, scn};
  
  double d1 =  dist(xyz_expr(-1.5,1.5,4.5),xyz_expr(0,0,0));
  double d2 = sqrt(p.w*p.w+p.h*p.h);



  render(stdout, stg);
  return 0;
}
