#include "sculptor.h"
#include "voxel.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

Sculptor::Sculptor(int nx1, int ny1, int nz1){
nx = nx1;
ny = ny1;
nz = nz1;
r = g = b = a = 0.5;
