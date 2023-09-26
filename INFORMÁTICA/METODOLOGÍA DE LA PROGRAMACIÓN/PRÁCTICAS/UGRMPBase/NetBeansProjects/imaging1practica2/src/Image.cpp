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
        
        _height =height;
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
    if (0<=i && i<_height*_width)
        setPos (i,v);
}

int Image:: getPixel (int x, int y) const{
    
    return getPos(y *_width + x);
}

void Image:: setPos (int i, Byte v){
    
    if (0<=i && i< _height*_width)
        _data[i] = v;
}

int Image:: getPos (int i) const{
    
    int pos = -1;
    if (0<=i && i< _height* _width)
        pos = _data[i].getValue();
    
    return pos;
}

void Image:: flatten (Byte b){
    
    int length = _height*_width;
    
    for (int i=0; i<length; i++)
        _data[i] = b;
}
// ...

void Image::showInWindow(string title) const {
    string tempname = "data"+SLASH+".hidden_" + title + ".pgm";

    mpSavePGMImage(tempname, (const unsigned char *)_data, _width, _height);
    mpDisplayImage(tempname, title);
    
}

string Image::inspect() const {
    string result = "";
    result = std::to_string(_width) + "x" + std::to_string(_height) + " " + std::to_string(mphash((const unsigned char*) _data, _height * _width));
    return result;
}

void Image:: getHistogram (int values[]) const{
        
    for (int i=0; i<Byte::MAX_BYTE; i++){
        values[i]=0;
        for (int x=0; x<_width; x++)
            for (int y=0;y<_height; y++)
                if (getPixel(x,y)==i) values[i]++;
    }
}


