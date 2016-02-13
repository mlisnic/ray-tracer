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
      tex_green, color_expr(0,0,0));
  object o1 = {POSTER, {.p = p}, NULL};
  obj_list *os = ol_singleton(o1);
  scene scn;
  scn.bg = bg;
  scn.objects = os;
  stage stg = {cam, scn};
  camera tcam = {xyz_expr(0,0,-1), 120, 120};
  xyz loc1 = logical_loc(tcam,60,51);
  xyz loc2 = logical_loc(tcam,1,0);
  xyz loc3 = logical_loc(tcam,60,80);
   ray orgray = {cam.loc, xyz_sub(loc1,cam.loc)};
  hit_test ht = intersect(orgray, o1);
  xyz htpt = ray_position(orgray,ht.t);
    double d1 =  dist(xyz_expr(-1.5,1.5,4.5),htpt);
  double d2 = sqrt(p.w*p.w+p.h*p.h);
  

  printf("\n\n *** testing intersect ***\n");
  xyz_show(stdout,htpt);
  hit_test_show(stdout,ht);
  
  
  printf("\n\n *** testing dist ***\n");
  printf("%.2lf %2.lf %.2lf\n",d1,d2,d1/d2);
  color c = color_expr(d1/d2,0,0);
  color_show(stdout,c);

  printf("\n\n *** testing logica_loc *** \n");
  xyz_show(stdout,loc1);
  xyz_show(stdout,loc2);
  xyz_show(stdout,loc3);

  printf("\n\n *** testing texture *** \n");
  color tx = tex_green(&o1, htpt);
  color_show(stdout,tx);
  xyz dirrr = xyz_sub(loc1,cam.loc);
  xyz_show(stdout,dirrr);
  ray tr = {cam.loc,dirrr};
  color trc = trace_ray(scn,tr);
  hit_test ht2 = intersect(tr,o1);
  xyz htpt22 = ht2.hit_point;
  xyz htpt2 = ray_position(tr,ht2.t);
  printf("\n\n");
  printf("===ray from cam (0,0,-5) to physical (60,51)\nray:");
  ray_show(stdout,tr);
  hit_test_show(stdout,ht2);
  printf("\n");
  xyz_show(stdout,htpt2);
  xyz_show(stdout,htpt22);
  printf("\n");
  color tx2 = tex_green(&o1, htpt2);
  color_show(stdout,tx2);
  printf("\n");
  color_show(stdout,trc);
  printf("\n\n");
  xyz_show(stdout,ray_position(tr,9.52));

  return 0;
}

 
