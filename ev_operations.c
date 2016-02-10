#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

color get_sc(object *o, location intersection)
{
  return  color_expr(0,0,0);
}

int main()
{
  /* xyz */
  printf(" *** testing xyz *** \n");
  xyz v = xyz_expr(1,2,3);
  xyz add = xyz_add(v,v);
  xyz vv = xyz_expr(5,5,5);
  xyz sub = xyz_sub(v,vv);
  xyz n = xyz_neg(sub);
  xyz sc = xyz_scale(1.5,v);
  xyz sc2 = xyz_scale(-3.33,n);
  double dt = xyz_dot(v,sc);
  double mag = xyz_mag(v);
  xyz z = xyz_expr(0,0,0);
  xyz zn = xyz_norm(z);
  xyz vn = xyz_norm(v);
  
  printf("xyz_expr(1,2,3) =>\t%s\n",xyz_tos(v));
  printf("(1,2,3)+(1,2,3) =>\t%s\n",xyz_tos(add));
  printf("(1,2,3)-(5,5,5) =>\t%s\n",xyz_tos(sub));
  printf("-(-4,-3,-2) =>\t%s\n",xyz_tos(n));
  printf("scale (1,2,3) by 1.5 =>\t%s\n",xyz_tos(sc));
  printf("scale (4,3,2) by -3.33 =>\t%s\n",xyz_tos(sc2));
  printf("(1,2,3)*(1.5,3,4.5) =>\t%.2lf\n",dt);
  printf("magnitude of (1,2,3) =>\t%.2lf\n",mag);
  printf("norm (0,0,0) =>\t%s\n",xyz_tos(zn));
  printf("norm (1,2,3) =>\t%s\n",xyz_tos(vn));
  printf(" *****\n");

  /* color */
  printf(" *** testing color *** \n");
  color c = color_expr(1,0.5,0);
  color cc = color_expr(0.75,0,0.25);
  color mod = color_modulate(c,cc);
  color scc = color_scale(1.5, cc);
  color addc = color_add(c,cc);

  printf("color_expr(1,0.5,0) =>\t%s\n",color_tos(c));
  printf("(1,0.5,0)*(0.75,0,0.25) =>\t%s\n",color_tos(mod));
  printf("scale (0.75,0,0.25) by 1.5 =>\t%s\n",color_tos(scc));
  printf("(1,0.5,0)+(0.75,0,0.25) =>\t%s\n",color_tos(addc));
  printf("(0.75,0,0.25) on [0,255] =>");
  color_show_bytes(stdout,cc);
  printf(" *****\n");

  /* ray */
  printf(" *** testing ray *** \n");
  ray testray = {v,vv};
  printf("ray from (1,2,3) to (5,5,5) =>\t%s\n",ray_tos(testray));
  printf(" *****\n");

  /* sphere */
  printf(" *** testing sphere *** \n");
  sphere testsph = sphere_expr(v, 3.2, get_sc, c);
  printf("sphere at (1,2,3) with radius 3.2:\n");
  sphere_show(stdout,testsph);
  printf("\n *****\n");

  /* poster */
  printf(" *** testing poster *** \n");
  poster testpst = poster_expr(v, 4, 5.25, get_sc, c);
  printf("poster at (1,2,3) with width 4 and height 5.25:\n");
  poster_show(stdout,testpst);
  printf("\n *****\n");

  /* object */
  printf(" *** testing object *** \n");
  object objs = {SPHERE,{.s = testsph},NULL};
  object objp = {POSTER,{.p = testpst},NULL};
  printf("the above sphere:\n");
  object_show(stdout,objs);
  printf("\nthe above poster:\n%s\n",object_tos(objp));
  printf(" *****\n");

  /* obj_list */
  printf(" *** testing obj_list *** ");
  obj_list *ol1 = ol_singleton(objs);
  obj_list *ol2 = ol_cons(objs,ol_cons(objp,ol_singleton(objs)));
  printf("singleton object list with the above sphere:\n");
  ol_show(stdout, ol1);
  printf("\nobject list of sphere, poster, sphere:\n%s\n",ol_tos(ol2));
  printf(" *****\n");

  /* scene */
  printf(" *** testing scene *** \n");
  scene testsc = {c,ol2};
  printf("scene with bg (1,2,3) and sph,pst,sph:\n");
  scene_show(stdout,testsc);
  printf("\n *****\n");

  /* hit_test */
  printf(" *** testing hit_test *** \n");
  hit_test ht = {MISS,5.1,v,c,c,vv};
  hit_test htt = {HIT,2.5,v,c,c,vv};
  printf("missed at 5.1s at (1,2,3):\n");
  hit_test_show(stdout,ht);
  printf("\nhit at 2.5s at (1,2,3):\n%s\n",hit_test_tos(htt));
  printf(" *****\n");

  /* camera */
  printf(" *** testing camera *** \n");
  camera cam = {v,9,16};
  printf("camera 9 high and 16 wide at (1,2,3):\n");
  camera_show(stdout,cam);
  printf("\n *****\n");

  /* stage */
  stage stg = get_stage(10);
  printf("get_stage(10):\n");
  stage_show(stdout,stg);
  printf("\n *****\n");

  return 0;
}
