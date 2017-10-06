//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include "file_ply_stl.h"
#include <stdlib.h>
#include <cmath>

using namespace std;

//*************************************************************************
// clase punto
//*************************************************************************
class _puntos3D {
public:
  vector<_vertex3f> vertices;
  vector<_vertex3f> colores;

  _puntos3D();
  void 	draw_puntos(float r, float g, float b, int grosor);
};

//*************************************************************************
// clase triángulo
//*************************************************************************
class _triangulos3D : public _puntos3D {
private:
  void draw_circulo(float radio, float x, float y, float z, int n);

public:
  vector<_vertex3i> caras;

	_triangulos3D();
  void draw_color_vertices();
  void draw_circulos_vertices(float radio, int resolucion);
  void draw_aristas(float r, float g, float b, int grosor);
  void draw_solido(float r, float g, float b);
  void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
};


//*************************************************************************
// clase cubo
//*************************************************************************
class _cubo : public _triangulos3D {
public:
	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************
class _piramide : public _triangulos3D {
public:
	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase Objeto PLY
//*************************************************************************
class _objetoPLY : public _triangulos3D {
public:
  _objetoPLY(const char archivo[]);
};
