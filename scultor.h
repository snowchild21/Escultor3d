#IFNDEF SCULTOR_H
#define SCULTOR_H
#include "voxel.h"
class Sculptor {
private:
  Voxel ***v; // Vetor da matriz 3D
  int nx,ny,nz; // Dimensões
  float r,g,b,a; // Propriedades do voxel
float fix;
public:
  Sculptor(int _nx, int _ny, int _nz); // construtor
  ~Sculptor(); // destrutor
  void setColor(float r, float g, float b, float alpha);
  void putVoxel(int x, int y, int z);
  void cutVoxel(int x, int y, int z);
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void writeOFF(const char* filename);
};
#endif
