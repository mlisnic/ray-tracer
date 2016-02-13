#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "raytracer.h"

/* ol_cons : cons object onto objectlist */
obj_list *ol_cons(object o, obj_list *os)
{
  obj_list *r = malloc(sizeof(obj_list));
  r->obj = o;
  r->next = os;
  return r;
}

/* ol_singleton: return singleton list with object */
obj_list *ol_singleton(object s)
{
  obj_list *r = malloc(sizeof(obj_list));
  r->obj = s;
  r->next = NULL;
  return r;
}

/* ol_tos : return string representation of objectlist */
char *ol_tos(obj_list *os)
{
  char buf[1024];
  int i;
  for (i=0; i<1024; i++)
    buf[i] = '\0';
  strcpy(buf,"'(");
  while (os) {
    strcat(buf, object_tos(os->obj));
    strcat(buf,"\n");
    os = os->next;
  }
  strcat(buf,")");
  return strdup(buf);
}

/* ol_show : print objectlist representation to f */
void ol_show(FILE *f, obj_list *os)
{
  char *s;
  fprintf(f,"'(");
  while (os) {
    s = object_tos(os->obj);
    fprintf(f, ":%s\n", s);
    os = os->next;
  }
  fprintf(f,")");
  free(s);
}

/* ol_free : free an objectlist */
void ol_free(obj_list *ss)
{
  obj_list *temp;
  while(ss->next) {
    temp = ss;
    ss = ss->next;
    free(temp);
  }
  free(ss);
}

