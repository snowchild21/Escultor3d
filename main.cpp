#include <iostream>
#include <fstream>
#include "sculptor.h"


// eixos para me ajudar a construir.

/* Zepellin.setColor(1, 1, 1, 0.1); // cinza
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
*/


int main(){

Sculptor Zepellin(100, 100, 100);


// corpo do zepellin
Zepellin.setColor(0.6601, 0.6601, 0.6601, 1); // cinza
Zepellin.putEllipsoid(50, 50, 50, 12, 34, 6); 
Zepellin.cutVoxel(50, 50, 56);
Zepellin.cutVoxel(50, 50, 44);
Zepellin.cutVoxel(50, 50, 56);
Zepellin.cutVoxel(62, 50, 50);
Zepellin.cutVoxel(38, 50, 50);




// Zepellin.setColor(0.996, 0.0, 0.996, 1); // magenta

// cabine do zepellin
Zepellin.setColor(0.6601, 0.6601, 0.6601, 1); // DarkGray
Zepellin.putEllipsoid(58, 61, 50, 7, 7, 2);
Zepellin.cutEllipsoid(58, 61, 50, 6, 6, 1);
Zepellin.putVoxel(64, 61, 50);
Zepellin.cutVoxel(65, 61, 50);


Zepellin.setColor(0.75, 0.75, 0.75, 0.1); // silver

// asas do Zepellin

// asas laterais
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

// outras asas laterais

for(int j = 0; j < 4; j++){
    for(int i = 0; i < 4 - j; i++){
        Zepellin.putVoxel(50, 54 + j, 56 + i);
    }
}

for(int j = 0; j < 4; j++){
    for(int i = 0; i < 4 - j; i++){
        Zepellin.putVoxel(50, 54 + j, 44  - i);
    }
}
for(int j = 0; j < 4; j++){
    for(int i = 0; i < 4 - j; i++){
        Zepellin.putVoxel(50, 54 + j, 56 + i);
    }
}

for(int j = 0; j < 4; j++){
    for(int i = 0; i < 4 - j; i++){
        Zepellin.putVoxel(50, 54 + j, 44  - i);
    }
}


// asas verticais

for(int j = 0; j < 9; j++){
    for(int i = 0; i < 10 - j; i++){
        Zepellin.putVoxel(43 + i, 22 + j, 50);
    }
}

for(int j = 0; j < 9; j++){
    for(int i = 0; i < 10 - j; i++){
        Zepellin.putVoxel(43 - i, 22 + j, 50);
    }
}


// essa asa tem que ser menor

for(int j = 0; j < 9; j++){
    for(int i = 0; i < 7 - j; i++){
        Zepellin.putVoxel(57 + i, 22 + j, 50);
    }
}

for(int j = 0; j < 9; j++){
    for(int i = 0; i < 7 - j; i++){
        Zepellin.putVoxel(57 - i, 22 + j, 50);
    }
}
    
// janela da cabine

Zepellin.setColor(1 , 1, 1, 0.09);

for(int i = 0; i < 8; i++){
    Zepellin.putVoxel(62, 58 + i, 51);
}
for(int i = 0; i < 8; i++){
    Zepellin.putVoxel(62, 58 + i, 49);
}
Zepellin.putVoxel(62, 58 + 8, 50);


// detalhes 
Zepellin.setColor(0.6601, 0.6601, 0.6601, 1);
Zepellin.putSphere(55, 30, 53, 3);
Zepellin.putSphere(55, 30, 47, 3);
 
Zepellin.putBox(55, 61, 37, 41, 53, 55);

Zepellin.setColor(0.41, 0.41, 0.41, 1);
Zepellin.putVoxel(65, 61, 51);
Zepellin.putVoxel(65, 61, 49);
Zepellin.putVoxel(65, 64, 50);
Zepellin.putVoxel(65, 58, 50);


Zepellin.writeOFF("zeppelin.off");

return 0;  
}
