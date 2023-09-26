/**
 * @file Image.cpp
 * @note To be implemented by students 
 * @author MP-DGIM, MP-IADE, MP-II (grupo B)
 */
#include<iostream>
#include <fstream>
#include<cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"
using namespace std;

Image::Image() : _height (0), _width (0){

}

Image::Image(int width, int height) {
    
    if (height >=0 && width>=0 && width*height< Image::IMAGE_MAX_SIZE ){
        
        _height= height;
        _width = width;
        
        for (int x=0; x<width; x++)
            for (int y=0; y<height; y++)
                setPixel(x,y,Byte(0));
    }

}

int Image:: height () const{
    
    return _height;
}

int Image:: width () const{
    
    return _width;
}

void Image:: setPixel (int x, int y, Byte v){
    
    int i = y * _width + x;
    if (x>=0 && x<=_width && y>=0 && y<=_height && 0<=v.getValue() && v.getValue()<Byte::MAX_BYTE)
        setPos (i,v);
}

int Image:: getPixel (int x, int y) const{
    
    if (x>=0 && x<=_width && y>=0 && y<=_height)
        return getPos(y *_width + x);
    else return -1;
}

void Image:: setPos (int i, Byte v){
    
    if (0<=i && i< _height*_width && 0<=v.getValue() && v.getValue()<Byte::MAX_BYTE)
        _data[i] = v;
}

int Image:: getPos (int i) const{
    
    int pos = -1;
    if (0<=i && i< _height* _width)
        pos = _data[i].getValue();
    
    return pos;
}

void Image:: flatten (Byte b){
        
    if (0<=b.getValue() && b.getValue()<Byte::MAX_BYTE)
        for (int y=0; y<_height; y++)
            for (int x=0; x< _width; x++)
                setPixel(x,y,b);
}


void Image::showInWindow(string title) const {
    string tempname = "data"+SLASH+".hidden_" + title + ".pgm";

    mpSavePGMImage(tempname, (unsigned char *)_data, _width, _height);
    mpDisplayImage(tempname, title);
    
}

string Image::inspect() const {
    string result = "";
    result = std::to_string(_width) + "x" + std::to_string(_height) + " " + std::to_string(mphash((const unsigned char*) _data, _height * _width));
    return result;
}

int Image::readFromFile (const char filename[]){
    
    const string FORMATO="P2";
    int salida=IMAGE_DISK_OK;
    int num;

    ifstream fentrada;
    
    fentrada.open(filename);
    
    if (fentrada){
        string magic_n;
        fentrada >> magic_n;
                        
        if (magic_n == "P2"||magic_n == "P5"){
            int width, height, pixel_value;
            fentrada >> width;
            fentrada >> height;
            fentrada >> pixel_value;


            if (width >= 0 && height >= 0 && width*height <= IMAGE_MAX_SIZE && pixel_value==255){
                
                _width = width;
                _height = height;

                for (int j=0; j<height; j++)
                    for (int i=0; i<width; i++){
                        fentrada >> num;
                        setPixel(i,j,Byte(num));
                    }    

                if (!fentrada) salida=IMAGE_ERROR_DATA; 
            }
            else salida = IMAGE_TOO_LARGE; 
        }
        else salida = IMAGE_ERROR_FORMAT;
        
        fentrada.close();
    }
    
    else salida = IMAGE_ERROR_OPEN;
    
    
    return salida;
}

int Image::saveToFile (const char filename[]) const {
    
    const string magic_n = "P2";
    int salida=IMAGE_DISK_OK, pixel_value = 255, height=_height, width=_width; 
    int num=0;

    ofstream fsalida;
    
    fsalida.open(filename);
    
    if (fsalida){
        
        fsalida << magic_n <<endl;        
        fsalida << width <<" ";
        fsalida << height <<endl;
        fsalida << pixel_value <<endl;
        for (int j=0; j<height; j++)
            for (int i=0; i<width; i++) 
                fsalida << getPixel(i,j)<<" ";
        if (!fsalida) salida = IMAGE_ERROR_DATA;
        
        fsalida.close();
    }
            
    
    else salida = IMAGE_ERROR_OPEN;
    
    
    return salida;
}

Histogram Image::getHistogram() const{
        
    Histogram histogram;
    int counter = 0;
    
    for (int i=0; i<Histogram::HISTOGRAM_LEVELS; i++){
        for (int x=0; x<_width; x++)
            for (int y=0;y<_height; y++)
            if (getPixel(x,y)==i){
                counter++;
                histogram.setLevel(Byte(i),counter);
            }
        counter=0;
    }

    return histogram;
     
}

Image Image::depictsHistogram() const {
    
    int width = 256, height = 160, border = 1, foot_tone = 9, a = height -(border+foot_tone)-2;
    int normal, max=-1;
    Image result(width, height);

    Histogram histogram = getHistogram();
    max = histogram.getMaxLevel();
    result.flatten(Byte(255));

    for (int x = 0; x <256; x++) {

        for (int y = 0; y < foot_tone; y++) { // the foot tone in the image
            result.setPixel(x, height-1-y, x);
        }
        
        normal = (histogram.getLevel(x)*a)/max;
        for (int y=0; y<=normal; y++) result.setPixel(x,height-foot_tone-border-y-1,0);
    }
    
    
    return result;
}


void Image::extractObjects(Image set[], int &nimages, int maximages, double tolerance) const{    
    Histogram histogram=getHistogram();
    int max=histogram.getMaxLevel();
    
    bool buscandoSupTolerancia=true;
    nimages=0;
    vector <int> posIniciales; //posición más a la izquierda de cada bloque
    vector <int> posFinales;//posición más a la derecha de cada bloque
    
    for(int level=Histogram::HISTOGRAM_LEVELS-1; level>=0 && nimages<=maximages; level--){
        if(buscandoSupTolerancia){
            if(histogram.getLevel(Byte(level))>=(max*tolerance)){
                posFinales.push_back(level);
                buscandoSupTolerancia=!buscandoSupTolerancia;
                
                if(level==0){
                    posIniciales.push_back(level);
                    nimages++;
                }
            }  
        }else{
            if(histogram.getLevel(Byte(level))<(max*tolerance) || level==0){
                /*if(level==0) posIniciales.push_back(level);
                else posIniciales.push_back(level-1);*/
                posIniciales.push_back(level);
                nimages++;
                buscandoSupTolerancia=!buscandoSupTolerancia;
            }
        } 
    }
    //Creo las imagenes
    for(int i=0; i<nimages; i++){
        Image image(width(), height());
        for(int x=0; x<width(); x++){
            for(int y=0; y<height(); y++){
                if(getPixel(x,y)>=posIniciales.at(i) && getPixel(x,y)<=posFinales.at(i)){
                    image.setPixel(x,y, Byte(getPixel(x,y)));
                }
            }
        }
        set[i]=image;
    }  
    
    for(int i=0; i<nimages; i++){
        cout << "Found object " << to_string(i) << " in " << "[" << to_string(posIniciales.at(i))
             << "," << to_string(posFinales.at(i)) << "]" << endl;
    }
    cout << "Found " << to_string(nimages) << " objects" << endl << endl;
}
