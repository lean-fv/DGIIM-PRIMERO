/**
 * @file main.cpp
 * @author MP
 */
#include <iostream>
#include <cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"
#include "Histogram.h"

using namespace std;

/**
 * @brief It waits until the key [INTRO] [RETURN] is pressed
 */
void pressReturnToContinue();

/**
 * @brief It breaks the program due to some error and shows a message
 * @param errorcode The type of error as declared in Image.h
 * @param errordata A message trying to describe the error
 */
void errorBreak(int errorcode, const string & errordata);

int main(int narg, char **args) {
    
    string input = "data"+SLASH+"telediario.pgm", 
            copy = "data"+SLASH+"kfc.pgm", output = "data"+SLASH+"new.pgm";
    int zoom=0;
    Image im_input, im_output, im_copyfrom, im_bin, im_cut, im_histogram, im_collection[10], im_aux;
    int res, n, w, h;
    
    cout <<"Procesando argumentos:" << endl;
    
    for (int i=1; i<narg; i++) cout << i << " ---> " << args[i] << endl;
    cout << endl;
    
    bool e_input= false;
    bool e_copy= false;
    bool e_output= false;
    bool e_zoom= false;
    const string I= "-i";
    const string C="-c";
    const string O="-o";
    const string Z="-z";
        
    if (narg>=3 && narg<=9 && narg%2 != 0){
        
        for (int i=1; i<narg; i=i+2){
            
            if (args[i]== I && !e_input){
                e_input=true;
                input=args[i+1];
            }
            
            else if (args[i]== C && !e_copy){
                e_copy=true;
                copy=args[i+1];
            }
            
            else if (args[i]== O && !e_output){
                e_output=true;
                output=args[i+1];
            }
            
            else if (args[i]== Z && !e_zoom){
                e_zoom=true;
                zoom=(stoi)(args[i+1]);
                if (zoom !=-1 && zoom!=1){
                    cout << "Valor de Zoom incorrecto: debe introducir [-1|1]." << endl;
                    std::exit (9);
                }
            } 
            
            else{
                
                if (args[i]==I){
                    cout << "Ha introducido '-i' mas de una vez." << endl;
                    std::exit(5);
                }
                else if (args[i]==C){
                    cout << "Ha introducido '-c' mas de una vez." << endl;
                    std::exit(6);
                }
                else if (args[i]==O){
                    cout << "Ha introducido '-o' mas de una vez." << endl;
                    std::exit(7);
                }
                else if (args[i]==Z){
                    cout << "Ha introducido '-z' mas de una vez." << endl;
                    std::exit(8);
                }

                cout << "Extension no valida."<< endl;
                cout << "Correcto formato:" << endl << "-i <imagen de entrada> [-c <imagen de copia> -o <imagen de salida>]" << endl;
                std::exit(4);
                
            }
                
        }
        
        if (!e_input){
            cout << "No ha introducido imagen de entrada." << endl;
            cout << "Correcto formato:" << endl << "-i <imagen de entrada> [-c <imagen de copia> -o <imagen de salida>]" << endl;
            std::exit(3);
        }
        
    }
    
    else{
        cout << "Numero de argumentos incorrecto." << endl;
        std::exit(2);
    }
    
    
    res = im_input.readFromFile(input.c_str());
    if (res != Image::IMAGE_DISK_OK) {
        errorBreak(res, input);
    }
    im_input.showInWindow("input");
//        im_input.depictsHistogram().showInWindow("histoinput");
//        im_aux = im_input.threshold(128);
//        im_aux.showInWindow("input128");
//        im_aux.depictsHistogram().showInWindow("histo128");
//        
//        im_aux=im_input.threshold();
//        im_aux.showInWindow("inputbalance");
//        im_aux.depictsHistogram().showInWindow("histobalance");

    INSPECT(im_input);
    if (zoom==-1) im_input=Image(im_input.zoomOut());
    else if (zoom==1) im_input=Image(im_input.zoomIn());
    
    if (zoom!=0){
        im_input.showInWindow("inputzoomed");
        INSPECT(im_input);
    }
    
    
    if (copy.length() > 0) {
        res = im_copyfrom.readFromFile(copy.c_str());
        if (res != Image::IMAGE_DISK_OK) {
            errorBreak(res, input);
        }
        im_copyfrom.showInWindow("copyfrom");
        im_copyfrom.depictsHistogram().showInWindow("copyhisto");
        INSPECT(im_copyfrom);
        w = im_copyfrom.width() + 5;
        h = im_copyfrom.height() + 5;
        im_bin = im_copyfrom.threshold();
        im_bin.showInWindow("threshold");
        INSPECT(im_bin);
        int x = 0;
        im_input.pasteArea(x, 0, im_copyfrom);
        im_copyfrom.extractObjects(im_collection, n, 3);
        im_cut = im_collection[0];
        im_collection[0].showInWindow("segmented");
        INSPECT(im_collection[0]);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut);
        im_input.pasteArea(x, h, im_bin);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut, 64);
        im_input.pasteArea(x, h, im_bin, 64);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut, 64, 50);
        im_input.pasteArea(x, h, im_bin, 64, 50);
    }
    im_output = im_input;
    if (output.length() > 0) {
        im_output.saveToFile(output.c_str());
    }
    im_output.showInWindow("output");
    INSPECT(im_output);
    pressReturnToContinue();
    return 0;
}
        

void pressReturnToContinue() {
    char aux[10];
    cout << "Press [RETURN] to continue ...";
    cin.getline(aux, 1, '\n');
}

void errorBreak(int errorcode, const string & errordata) {
    switch (errorcode) {
        case Image::IMAGE_ERROR_OPEN:
            CVAL << endl << "Error opening file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_DATA:
            CVAL << endl << "Data error in file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_FORMAT:
            CVAL << endl << "Unrecognized format in file " << errordata << endl;
            break;
    }
    std::exit(1);
}