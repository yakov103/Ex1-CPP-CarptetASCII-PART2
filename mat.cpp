#include <iostream>
#include "mat.hpp"

using namespace std;
namespace ariel
{
    string printMat (int width, int height, char first, char second) ;
    void checkErrors (int width, int height, char first, char second);

    string mat(int width, int height, char first, char second)
    {
        checkErrors(width,height,first,second); 
        return printMat(width,height, first , second); 
    }




    void checkErrors (int width, int height, char first, char second)
    {
    
          if (width * height % 2 == 0 )
        {
            throw runtime_error("carpet shoud be odd ! ");
        }
        if (width < 0 || height < 0 ){ 
            throw runtime_error("you cannot use negative numbers !"); 
        }
        const int MINCHAR = 33 ;
        const int MAXCHAR = 126; 
        if (first< MINCHAR || first >MAXCHAR || second < MINCHAR || second > MAXCHAR){
        throw runtime_error("you cannot use negative numbers !"); 
        }
    }

    string printMat (int width, int height, char first, char second) { 

        string res;
        res="";
        if (width == 1 ){ 
            for (int i = 0 ; i < height ; i++){ 
                res += first ;
            }
            return res;
        }
        if (height == 1 ){ 
            for (int i = 0 ; i < width ; i++){ 
                res += first ;
            }
            return res;
        }
        
        for ( int i = 0 ; i < height ; i ++){
            for (int j = 0 ; j < width ; j ++){
                res +=second;
            }
           res += '\n';
        }

        int p = 0 ;  
        int q = 0 ;

        while ( p < height /2 || q < width /2) {
            for ( int i = p ; i < height-p && p < height; i ++ ){
                res[i*(width+1)+q]=first;
                res[i*(width+1)+(width -q -1)]=first;
            }
            for (int i = q ; i < width - q  && q < width; i++) {
                res[(p*(width+1)) + i ] = first;
                res[((height-1-p)*(width+1)) + i]= first;
            }

            p+=2;
            q+=2;
        }
        if(width == height && width % 4 == 1){
            res[width/2*(width+1)+width/2]=first;
        }
        return res;

    }

    
}
