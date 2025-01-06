#include <iostream>
#include <fstream>
#include "sculptor.h"
//terminal
// g++ main.cpp Sculptor.cpp -o escultor
// ./escultor
int main(){

Sculptor Zepellin(100, 100, 100);

Zepellin.setColor(1, 1, 1, 0.1); // cinza
for(int i = 0; i < 100; i++){
    Zepellin.putVoxel(i, 50, 50);
}
Zepellin.setColor(0, 0, 0, 0.1); // cinza
for(int i = 0; i < 100; i++){
    Zepellin.putVoxel(50, i, 50);
}
Zepellin.setColor(0.89, 0.17, 0.32, 0.1); // cinza
for(int i = 0; i < 100; i++){
    Zepellin.putVoxel(50, 50, i);
}

Zepellin.setColor(0.5, 0.5, 0.5, 1); // cinza
Zepellin.putEllipsoid(50, 50, 50, 12, 34, 6); 

// Zepellin.setColor(0.996, 0.0, 0.996, 1); // magenta
Zepellin.setColor(0.5, 0.5, 0.5, 1); // cinza
Zepellin.putEllipsoid(58, 61, 50, 7, 7, 2);

Zepellin.setColor(0.5, 0.5, 0.5, 0.1);

// asas do Zepellin
for(int j = 0; j < 8; j++){
    for(int i = 0; i < 10 - j; i++){
        Zepellin.putVoxel(50, 22 + j, 53 + i);
    }
}

for(int j = 0; j < 8; j++){
    for(int i = 0; i < 10 - j; i++){
        Zepellin.putVoxel(50, 22 + j, 47  - i);
    }
}
for(int j = 0; j < 8; j++){
    for(int i = 0; i < 10 - j; i++){
        Zepellin.putVoxel(50, 22 + j, 53 + i);
    }
}

for(int j = 0; j < 8; j++){
    for(int i = 0; i < 10 - j; i++){
        Zepellin.putVoxel(50, 22 + j, 47  - i);
    }
}
    
 




Zepellin.writeOFF("zeppelin.off");

return 0;  
}
