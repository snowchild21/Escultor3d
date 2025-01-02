#include "sculptor.h"
#include "voxel.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

Sculptor :: Sculptor(int nx1, int ny1, int nz1){ // construtor
nx = nx1;
ny = ny1;
nz = nz1;
v = new Voxel**[nx];
  for(int i = 0; i < nx; i++){
    v[i] = new Voxel*[ny];
    for(int j = 0; j < ny; j++){
      v[i][j] = new Voxel[nz];
      for(int k = 0; k < nz; k++){
        v[i][j][k].show = false; 
        v[i][j][k].r = 0;
        v[i][j][k].g = 0;
        v[i][j][k].b = 0;
        v[i][j][k].a = 0;
        
      }
    }
  }
}

Sculptor::~Sculptor(){ // destrutor
  // liberar/deletar a memoria alocada!
  for(int i = 0; i < nx; i++){
    for(int j = 0; j < nz; j++){ 
      delete[]  v[i][j]; 
    }
  }
  for(int i = 0; i < nx; i++){
    delete[] v[i];
  }
  delete[] v;
  nx = ny = nz = 0;
}
// seletor de cores
void Sculptor :: setColor(float sr, float sg, float sb, float sa){ // s = set 
r = sr;
g = sg;
b = sb;
a = sa;  
} 
// ativa o voxel
void Sculptor :: putVoxel(int px, int py, int pz){ // p = put
v[px][py][pz].show = true;
v[px][py][pz].r = r;
v[px][py][pz].g = g;
v[px][py][pz].b = b;
v[px][py][pz].a = a;
}
//desativa o voxel
void Sculptor :: cutVoxel(int cx, int cy, int cz){ // c = cut
v[cx][cy][cz].show = false;
}
// faz uma caixa, ou seja, põe voxels em um determinado intervalo 
void Sculptor :: putBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int i = x0; i < x1; i++){
    for(int j = y0; j < y1; j++){ 
      for(int k = z0; k < z1; k++){
        v[i][j][k].show = true; //ativa
         v[i][j][k].r = r;
         v[i][j][k].g = g;
         v[i][j][k].b = b;
         v[i][j][k].a = a;
      }
    }
  }
}  

// tira essa caixa
void Sculptor :: cutBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_){
  for(int i = x0_; i < x1_; i++){
    for(int j = y0_; j < y1_; j++){ 
      for(int k = z0_; k < z1_; k++){
        v[i][j][k].show = false; //desativa
      }
    }
  }
}


  // faz uma bola, ou como o nome diz, uma esfera em um determinado intervalo
  void Sculptor :: putSphere(int xc, int yc, int zc, int r){ // c = center
  double x2, y2, z2; // uso o tipo double para aumentarmos a precisão do intervalo
    for(int i = 0; i < xc; i++){
      for(int j = 0; j < yc; j++){ 
        for(int k = 0; k < zc; k++){
          x2 = (double)(i - xc)*(double)(i - xc); // aqui uso a conversão de variável pois os parametros sao tipo int
          y2 = (double)(j - yc)*(double)(j - yc);
          z2 = (double)(k - zc)*(double)(k - zc);
          if((x2 + y2 + z2) < (r*r)){
            v[i][j][k].show = true;
             v[i][j][k].r = r;
             v[i][j][k].g = g;
             v[i][j][k].b = b;
             v[i][j][k].a = a;
          }
        }
      }
    }
  }
  // tira essa bola
  void Sculptor :: cutSphere(int xc_, int yc_, int zc_, int r_){ // c = center
    double x2_, y2_, z2_;
      for(int i = 0; i < xc_; i++){
        for(int j = 0; j < yc_; j++){ 
          for(int k = 0; k < zc_; k++){
            x2_ = (double)(i - xc_)*(double)(i - xc_);
            y2_ = (double)(j - yc_)*(double)(j - yc_);
            z2_ = (double)(k - zc_)*(double)(k - zc_);
            if((x2_ + y2_ + z2_) < (r_*r_)){
              v[i][j][k].show = false;
            }
          }
        }
      }
    }
  // esse metodo preenche o espaço de uma elipse
  void Sculptor :: putEllipsoid(int xc, int yc, int zc, int rx, int ry, int rz){ // c = center
    double xe, ye, ze; // e = elipse (x2/a2 + y2/b2 + z2/c2)
      for(int i = 0; i < xc; i++){
        for(int j = 0; j < yc; j++){ 
          for(int k = 0; k < zc; k++){
            xe = (double)(i - xc)*(double)(i - xc)/(rx*rx);
            ye = (double)(i - yc)*(double)(i - yc)/(ry*ry);
            ze = (double)(i - zc)*(double)(i - zc)/(rz*rz);
            if((xe + ye + ze) < 1){
              v[i][j][k].show = true;
               v[i][j][k].r = r;
               v[i][j][k].g = g;
               v[i][j][k].b = b;
               v[i][j][k].a = a;
            }
          }
        }
      }
    }
  //tira o elipsoide
  void Sculptor :: cutEllipsoid(int xc_, int yc_, int zc_, int rx_, int ry_, int rz_){ 
    double xe, ye, ze; 
      for(int i = 0; i < xc_; i++){
        for(int j = 0; j < yc_; j++){ 
          for(int k = 0; k < zc_; k++){
            xe = (double)(i - xc_)*(double)(i - xc_)/(rx_*rx_);
            ye = (double)(i - yc_)*(double)(i - yc_)/(ry_*ry_);
            ze = (double)(i - zc_)*(double)(i - zc_)/(rz_*rz_);
            if((xe + ye + ze) < 1){
              v[i][j][k].show = false;
            }
          }
        }
      }
  }
  // metodo para salvar arquivos ;) 
  void Sculptor :: writeOFF(const char* filename){
    std::ofstream ArqOFF;
    fixed(ArqOFF); // correção da precisão do .off nas casas decimais
    int Nvox = 0, aux;
    ArqOFF.open(filename);
    
    
    //criação do nosso arquivo:
    
      ArqOFF<<"OFF\n";
    
    for(int i = 0; i < ny; i++){
      for(int j = 0; j < nx; j++){ 
        for(int k = 0; k < nz; k++){
          if(v[i][j][k].show == true){
            Nvox++;
          }
        }
      }
    }

    ArqOFF<<Nvox*8<<" "<<Nvox*6<<" "<<0<<"\n"; // quantidade de vertices e de faces, 0 arestas pois não precisa indicar.

    // hora de colocar os valores de acordo com as orientações para o voxel ser um cubo
    for(int a = 0; a < ny; a++){
      for(int b = 0; b < nx; b++){ 
        for(int c = 0; c < nz; c++){
          if(v[a][b][c].show == true){
            ArqOFF << a - 0.5 << " " << b - 0.5 << " " << c - 0.5 << std::endl<< std::flush;
            ArqOFF << a - 0.5 << " " << b + 0.5 << " " << c - 0.5 << std::endl<< std::flush;
            ArqOFF << a + 0.5 << " " << b + 0.5 << " " << c - 0.5 << std::endl<< std::flush;
            ArqOFF << a + 0.5 << " " << b - 0.5 << " " << c - 0.5 << std::endl<< std::flush;
            ArqOFF << a - 0.5 << " " << b - 0.5 << " " << c + 0.5 << std::endl<< std::flush;
            ArqOFF << a - 0.5 << " " << b + 0.5 << " " << c + 0.5 << std::endl<< std::flush;
            ArqOFF << a + 0.5 << " " << b + 0.5 << " " << c + 0.5 << std::endl<< std::flush;
            ArqOFF << a + 0.5 << " " << b - 0.5 << " " << c + 0.5 << std::endl<< std::flush;
      }
     }
   }
 }
    
Nvox = 0;
    for(int i = 0; i < ny; i++){
      for(int j = 0; j < nx; j++){ 
        for(int k = 0; k < nz; k++){
          if(v[i][j][k].show == true){
            aux = Nvox*8;
              ArqOFF<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].r<<" "
              <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
              ArqOFF<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" "
              <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
              ArqOFF<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "
              <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
              ArqOFF<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "
              <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
              ArqOFF<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "
              <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
              ArqOFF<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "
              <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<std::endl;
    
                          Nvox = Nvox+8;
                        }
                    }
                }
            }
    if(ArqOFF.is_open()){
            std::cout << "Arquivo.OFF salvo!"<<std::endl;
        }
  ArqOFF.close();
}
