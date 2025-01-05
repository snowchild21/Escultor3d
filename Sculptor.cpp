#include "sculptor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

Sculptor :: Sculptor(int _nx, int _ny, int _nz){ // construtor
  std::cout << "Construtor chamado" << std::endl;
nx = _nx;
ny = _ny;
nz = _nz;
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
  std::cout<<"destrutor chamado"<<std::endl;
}
// seletor de cores
void Sculptor :: setColor(float r, float g, float b, float alpha){  
this -> r = r;
this -> g = g;
this -> b = b;
this -> a = alpha;  
} 
// ativa o voxel
void Sculptor :: putVoxel(int x, int y, int z){ 
v[x][y][z].show = true;
v[x][y][z].r = r;
v[x][y][z].g = g;
v[x][y][z].b = b;
v[x][y][z].a = a;
}
//desativa o voxel
void Sculptor :: cutVoxel(int x, int y, int z){ 
v[x][y][z].show = false;
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
void Sculptor :: cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
  for(int i = x0; i < x1; i++){
    for(int j = y0; j < y1; j++){ 
      for(int k = z0; k < z1; k++){
        v[i][j][k].show = false; //desativa
      }
    }
  }
}


  // faz uma bola, ou como o nome diz, uma esfera em um determinado intervalo
 void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int x = xcenter - radius; x <= xcenter + radius; x++){ // x + raio = x0, ou seja, x= x0 - raio
        for(int y = ycenter - radius; y <= ycenter + radius; y++){ // y + raio = y0, ou seja, y= y0 - raio
            for(int z = zcenter - radius; z <= zcenter + radius; z++){ // z + raio = z0, ou seja, z= z0 - raio
                if((x - xcenter) * (x - xcenter) + (y - ycenter) * (y - ycenter) + (z - zcenter) * (z - zcenter) <= radius * radius){   // se a equação da esfera for verdadeira, então faz o voxel
                    v[x][y][z].show = true;
                    v[x][y][z].r = r;
                    v[x][y][z].g = g;
                    v[x][y][z].b = b;
                }
            }
        }
    } 
}
  // tira essa bola
  void Sculptor :: cutSphere(int xcenter, int ycenter, int zcenter, int radius){ // c = center
       for(int x = xcenter - radius; x <= xcenter + radius; x++){ // x + raio = x0, ou seja, x= x0 - raio
        for(int y = ycenter - radius; y <= ycenter + radius; y++){ // y + raio = y0, ou seja, y= y0 - raio
            for(int z = zcenter - radius; z <= zcenter + radius; z++){ // z + raio = z0, ou seja, z= z0 - raio
                if((x - xcenter) * (x - xcenter) + (y - ycenter) * (y - ycenter) + (z - zcenter) * (z - zcenter) <= radius * radius){   // se a equação da esfera for verdadeira, então faz o voxel

              v[x][y][z].show = false;
            }
          }
        }
      }
    }
  // esse metodo preenche o espaço de uma elipse
 void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    float xnovo;
    float ynovo;
    float znovo;

    for(int x = 0; x < nx; x++){ 

        for(int y = 0; y < ny; y++){ 

            for(int z = 0; z < nz; z++){

                xnovo = ((float)(x-xcenter) * (float)(x-xcenter))/(rx * rx);
                ynovo = ((float)(y-ycenter) * (float)(y-ycenter))/(ry * ry);
                znovo = ((float)(z-zcenter) * (float)(z-zcenter))/(rz * rz);
                if((xnovo + ynovo + znovo) <= 1){ // se a equação da elipse for verdade, então faz o voxel
                putVoxel(x, y, z);
                v[x][y][z].show = true;
                v[x][y][z].r = r;
                v[x][y][z].g = g;
                v[x][y][z].b = b;

                }
            }
        }
    } 
}
  //tira o elipsoide
  void Sculptor :: cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){ 
   float xnovo;
    float ynovo;
    float znovo;

    for(int x = 0; x < nx; x++){ 

        for(int y = 0; y < ny; y++){ 

            for(int z = 0; z < nz; z++){

                xnovo = ((float)(x-xcenter) * (float)(x-xcenter))/(rx * rx);
                ynovo = ((float)(y-ycenter) * (float)(y-ycenter))/(ry * ry);
                znovo = ((float)(z-zcenter) * (float)(z-zcenter))/(rz * rz);
                if((xnovo + ynovo + znovo) <= 1){ // se a equação da elipse for verdade, então faz o voxel
                cutVoxel(x, y, z);
                }
            }
        }
    } 
}
  // metodo para salvar arquivos ;) 
  void Sculptor :: writeOFF(const char* filename){
      int Nvox = 0;
      int aux = 0;
    
      std::ofstream arqoff;
      arqoff.open(filename);

      arqoff<<"OFF\n";

      
      for (int i = 0; i < nx; i++){
          for (int j = 0; j <ny; j++){
               for (int k = 0; k <nz; k++){
                    if(v[i][j][k].show == true){
                    Nvox++;
                    }
               }
           }
      }
      arqoff<<Nvox * 8<<" "<<Nvox * 6 << " " << "0" << "\n"; 

      for (int i = 0; i < nx; i++){
          for (int j = 0; j < ny; j++){
               for (int k = 0; k < nz; k++){
                    if(v[i][j][k].show == true){
                    arqoff << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                    arqoff << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                    arqoff << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n"; 
                    arqoff << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n"; 
                    arqoff << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n"; 
                    arqoff << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n"; 
                    arqoff << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n"; 
                    arqoff << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n"; 
                    }
               }
          }
      }

      Nvox = 0;

      // descrever cada voxel
      for (int i= 0; i<nx; i++){
          for (int j = 0; j<ny; j++){
               for (int k= 0; k<nz; k++){
                    if(v[i][j][k].show == true){
                    aux = Nvox * 8;
                    arqoff << std::fixed;

                    // montar linha que realiza a construção das faces a partir do vertices e mostrar as propriedades rgba do voxel
                    arqoff << "4" << " " << 0+aux << " " << 3+aux << " " << 2+aux << " " << 1+aux << " ";
                    arqoff << std::setprecision(2)<<v[i][j][k].r << " " << std::setprecision(2)<<v[i][j][k].g <<" " << std::setprecision(2)<<v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";

                    arqoff << "4" << " " << 4+aux << " " << 5+aux << " " << 6+aux << " " << 7+aux << " ";
                    arqoff << std::setprecision(2)<<v[i][j][k].r << " " << std::setprecision(2)<<v[i][j][k].g <<" " << std::setprecision(2)<<v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";

                    arqoff << "4" << " " << 0+aux << " " << 1+aux << " " << 5+aux << " " << 4+aux << " ";
                    arqoff << std::setprecision(2)<<v[i][j][k].r << " " << std::setprecision(2)<<v[i][j][k].g <<" " << std::setprecision(2)<<v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";

                    arqoff << "4" << " " << 0+aux << " " << 4+aux << " " << 7+aux << " " << 3+aux << " ";
                    arqoff << std::setprecision(2)<<v[i][j][k].r << " " << std::setprecision(2)<<v[i][j][k].g <<" " << std::setprecision(2)<<v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";

                    arqoff << "4" << " " << 3+aux << " " << 7+aux << " " << 6+aux << " " << 2+aux << " ";
                    arqoff << std::setprecision(2)<<v[i][j][k].r << " " << std::setprecision(2)<<v[i][j][k].g <<" " << std::setprecision(2)<<v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";

                    arqoff << "4" << " " << 1+aux << " " << 2+aux << " " << 6+aux << " " << 5+aux << " ";
                    arqoff << std::setprecision(2)<<v[i][j][k].r << " " << std::setprecision(2)<<v[i][j][k].g <<" " << std::setprecision(2)<<v[i][j][k].b << " " << std::setprecision(2) << v[i][j][k].a << "\n";

                    Nvox = Nvox + 1;
                    }
               }
           }
      }
      arqoff.close();
}
