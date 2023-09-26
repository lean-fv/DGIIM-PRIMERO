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
            copy = "data"+SLASH+"kfc.pgm", output ="./data/output_hidden",
            textSource, imageSource;
    
    int zoom=0, k=0;
    
    Image im_input, im_output, im_copyfrom, im_bin, im_cut, im_histogram, im_collection[10], im_aux;
    int res, n, w, h;
    
    cout <<"Processing arguments:" << endl;
    
    for (int i=1; i<narg; i++) cout << i << " ---> " << args[i] << endl;
    cout << endl;
    
    bool e_input= false;
    bool e_copy= false;
    bool e_output= false;
    bool e_zoom= false;
    bool e_p= false;
    bool e_ht= false;
    bool e_st= false;
    bool e_hi= false;
    bool e_si= false;
    const string I= "-i";
    const string C="-c";
    const string O="-o";
    const string Z="-z";
    const string P="-p";
    const string HT="-ht";
    const string ST="-st";
    const string HI="-hi";
    const string SI="-si";
        
    if (narg>=3 && narg<=15){
        
        for (int i=1; i<narg; i++){
            
            if (args[i]== I && !e_input){
                e_input=true;
                i++;
                input=args[i];
                
            }
            
            /*else if (args[i]== C && !e_copy){
                e_copy=true;
                copy=args[i+1];
            }*/
            
            else if (args[i]== O && !e_output){
                e_output=true;
                i++;
                output=args[i];
            }
            
            else if (args[i]== Z && !e_zoom){
                e_zoom=true;
                i++;
                zoom=(stoi)(args[i]);
                if (zoom !=-1 && zoom!=1){
                    cout << "Invalid zoom value: expected integer values -1 or 1." << endl;
                    std::exit (9);
                }
            }
            
            else if (args[i]== P && !e_p){
                e_p=true;
                i++;
                k=(stoi)(args[i]);
                
                if (k<0 || k>7){
                    cout <<"Invalid plane: expected integer value between 0 and 7."<<endl;
                    std::exit(10);
                }
            }
            
            else if (args[i]== HT && !e_ht){
                e_ht=true;
                i++;
                textSource=args[i];
            }
            
            else if (args[i]== ST && !e_st){
                e_st=true;
            }
            
            else if (args[i]== HI && !e_hi){
                e_hi=true;
                i++;
                imageSource=args[i];
            }          
            
            else if (args[i]== SI && !e_si){
                e_si=true;
            }
              
            else{
                
                if (args[i]==I){
                    cout << "'-i' introduced more than once." << endl;
                    std::exit(5);
                }
                /*else if (args[i]==C){
                    cout << "'-c' introduced more than once." << endl;
                    std::exit(6);
                }*/
                else if (args[i]==O){
                    cout << "'-o' introduced more than once." << endl;
                    std::exit(7);
                }
                else if (args[i]==Z){
                    cout << "'-z' introduced more than once." << endl;
                    std::exit(8);
                }
                else if (args[i]==P){
                    cout << "'-p' introduced more than once." << endl;
                    std::exit(11);
                }
                else if (args[i]==HT){
                    cout << "'-ht' introduced more than once." << endl;
                    std::exit(12);
                }
                else if (args[i]==ST){
                    cout << "'-st' introduced more than once." << endl;
                    std::exit(13);
                }
                else if (args[i]==HI){
                    cout << "'-hi'introduced more than once." << endl;
                    std::exit(14);
                }
                else if (args[i]==SI){
                    cout << "'-si' introduced more than once." << endl;
                    std::exit(15);
                }
                

                cout << "Invalid extension."<< endl;
                cout << "Correct format:" << endl << "-i <imageCarrier> <-z <-1|1> -p <k> -ht <textSource> -st -hi <imageSource> -si -o <output>]" << endl<<endl;
                std::exit(4);
                
            }
                
        }
        
        if (!e_input){
            cout << "No input image carrier introduced." << endl<<"Invalid format." << endl << "Expected format:"<<endl
                 <<"-i <imageCarrier> [<-z <-1|1> -p <k> -ht <textSource> -st -hi <imageSource> -si -o <output>]" << endl;
            std::exit(3);
        }
        
    }
    
    else{
        cout << "Invalid argument number." << endl;
        std::exit(2);
    }
    
    
    res = im_input.readFromFile(input.c_str());
    if (res != Image::IMAGE_DISK_OK) {
        errorBreak(res, input);
    }
//    im_input.showInWindow("input");
//        im_input.depictsHistogram().showInWindow("histoinput");
//        im_aux = im_input.threshold(128);
//        im_aux.showInWindow("input128");
//        im_aux.depictsHistogram().showInWindow("histo128");
//        
//        im_aux=im_input.threshold();
//        im_aux.showInWindow("inputbalance");
//        im_aux.depictsHistogram().showInWindow("histobalance");

    
    //INSPECT(im_input);
    //if (zoom==-1) im_input=Image(im_input.zoomOut());
    //else if (zoom==1) im_input=Image(im_input.zoomIn());
    
    if (zoom!=0){
        //im_input.showInWindow("inputzoomed");
       // INSPECT(im_input);
    }
    
    /*
    if(e_copy){ 
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
    }
    
    //im_output.showInWindow("output");
    //INSPECT(im_output);
    */
    
    const int TOTAL_SIZE=im_input.width()*im_input.height();
    
    if (e_ht){
        string text;
        ifstream entrada;
        entrada.open(textSource.c_str());
        
        if (entrada){
            while (entrada){
                string aux;
                getline(entrada,aux);
                text= text+aux +"\n";
                
            } text.pop_back();
            
            int length=text.length();
            char* text_tohide=new char[length];
            for (int i=0; i<length; i++) text_tohide[i]=text.at(i);

            bool hidden_text=im_input.hideText(text_tohide,k);

            if (hidden_text) cout <<"Hiding text..."<<endl<<endl;
            else cout <<"Error hiding text."<<endl<<endl;

            entrada.close();
            delete[] text_tohide;
            text_tohide=nullptr;
            
        } else cout <<"Error opening input textSource file."<<endl<<endl;
        
        

    }
    
    if (e_st){
        
        char* text_toshow=new char [TOTAL_SIZE];
       
        bool text_shown=im_input.showText(text_toshow,TOTAL_SIZE,k);

        if (text_shown){
            
            ofstream salida;
            
            salida.open(output.c_str());
            
            if(salida){
                salida << text_toshow;
                cout<<"Showing text..."<<endl<< "Creating output file..."<<endl<<endl;
                salida.close();
                
            } else cout<<"Error saving to file."<<endl<<endl;
            
            
        } else cout<<"No text to show."<<endl<<endl;
        
        delete[] text_toshow;
        text_toshow=nullptr;

        
    }
    
    if (e_hi){
        
        Image im_tohide;
        int salida=im_tohide.readFromFile(imageSource.c_str());
        
        if (salida==Image::IMAGE_DISK_OK){
            bool hidden_image=im_input.hideImage(k,im_tohide);

            if(hidden_image) cout<<"Hiding image..."<<endl<<endl;
            else cout<<"Error hiding image."<<endl<<endl;
        }
        
        else if (salida==Image::IMAGE_ERROR_OPEN) cout<<"Error opening input imageSource file."<<endl<<endl;
        else if (salida==Image::IMAGE_ERROR_DATA) cout<<"Data error related to input imageSource file."<<endl<<endl;
        else if (salida==Image::IMAGE_ERROR_FORMAT) cout<<"Input imageSource error format."<<endl<<endl;
        else cout<<"Input imageSource too large."<<endl<<endl;
    }
    
    if (e_si){
        
        Image im_toshow;
        bool image_shown=im_input.showImage(k,im_toshow);
        
        if (image_shown){
            int salida=im_toshow.saveToFile(output.c_str());
            
            if (salida==Image::IMAGE_DISK_OK) cout<<"Showing image..."<<endl<< "Creating output file..."<<endl<<endl;
            else cout<<"Error saving to output file."<<endl<<endl; 
            
        } else cout<<"No image to show."<<endl<<endl;
        
    }
    
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