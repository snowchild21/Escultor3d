#include <iostream>
#include <fstream>
#include "voxel.h"
#include "sculptor.h"
#include "Sculptor.cpp"

int main(){

Sculptor caixa(100, 100, 100);
caixa.setColor(0.28, 0.81, 0.79, 0.7);
caixa.putBox(0, 10, 0, 10, 0, 10);
caixa.writeOFF("caixa ciano.off");
return 0;  
}
