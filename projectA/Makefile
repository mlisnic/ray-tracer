# Makefile (starter)
# CS152 Winter 2016
# Project A

.PHONY: clean

SRC = xyz.c color.c ray.c sphere.c poster.c object.c obj_list.c scene.c light.c camera.c hit_test.c stage.c intersect.c raytracer.c rt.c texture.c

EVSRC = xyz.c color.c ray.c sphere.c poster.c object.c obj_list.c scene.c light.c camera.c hit_test.c stage.c intersect.c raytracer.c ev_rt.c texture.c

OPSRC = xyz.c color.c ray.c sphere.c poster.c object.c obj_list.c scene.c camera.c hit_test.c stage.c ev_operations.c

op: raytracer.h $(OPSRC)
	clang -g -Wall -o op $(OPSRC) -lm

ev: raytracer.h $(EVSRC)
	clang -g -O3 -Wall -o ev $(EVSRC) -lm

trace: raytracer.h $(SRC)
	clang -g -O3 -Wall -o rt $(SRC) -lm

clean:
	rm -rf rt *.dSYM *.ppm
