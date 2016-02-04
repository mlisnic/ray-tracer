# Makefile (starter)

# CS152 Winter 2015
# Project B

.PHONY: clean

SRC = xyz.c color.c ray.c sphere.c poster.c object.c obj_list.c scene.c camera.c hit_test.c stage.c intersect.c raytracer.c rt.c 

trace: raytracer.h $(SRC)
	gcc -g -O3 -Wall -o rt $(SRC) -lm

clean:
	rm -rf rt *.dSYM *.ppm

