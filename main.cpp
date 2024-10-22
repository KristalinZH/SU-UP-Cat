#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "./draw/sdlwrapper.h"

struct pixel{
    Uint8 r=0,g=0,b=0;
};

pixel readPixel(const std::string& line){
    std::istringstream ls(line);
    
    int r,g,b; 
    char sep;
    pixel pix;

    ls>>r>>sep>>g>>sep>>b;

    pix.r = Uint8(r);
    pix.g = Uint8(g);
    pix.b = Uint8(b);

    return pix;
}

std::vector<std::vector<pixel>>readPixels(){
    std::vector<std::vector<pixel>>arr(500,std::vector<pixel>(800));
    std::ifstream file("../garfield.txt");


    std::string line;
    std::getline(file, line);

    for(int i=0;i<500;i++){
        for(int j=0;j<800;j++){
            std::getline(file, line);

            pixel pix = readPixel(line);

            arr[i][j]=pix;
        }
    }

    return arr;
}

void drawGarfield(const std::vector<std::vector<pixel>>& arr){
    using namespace sdlw;

    for(int i=0;i<500;i++){
        for(int j=0;j<800;j++){
            setColor(arr[i][j].r, arr[i][j].g,arr[i][j].b);

            drawPixel(j,i);
        }
    }

    saveImage("../garfield.jpg");

}

int main()
{
   std::vector<std::vector<pixel>> arr = readPixels();

   drawGarfield(arr);
   
   std::cin.get();
   return 0;
}