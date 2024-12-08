// 20112024 | Author: @josephineesposito
// Project13.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.

#include <iostream>
#include "Image.h"
#include "Png.h"
#include "Jpeg.h"

#include <vector>

/// 
/// [X] Implementar una función para la clase "png" que simule la eliminación del canal "alpha"
/// [X] Implementar una función que dada una tabla de imágenes de cualquier tipo elimina al canal alpha de todas las que sean "png"
/// 

void RemoveAlphas(std::vector<Image> _vTablaImg)
{
  int iIdx = _vTablaImg.size();

  for (int i = 0; i < iIdx; i++)
  {
    _vTablaImg.at(i).RemoveAlpha();
    _vTablaImg.at(i).Print();
  }
}

int main()
{
    Image cImage = Image(0xFFAAAAAA);
    Png cPng = Png(0xDDAAAAAA);
    Jpeg cJpeg = Jpeg(0xEEAAAAAA);

    cImage.Print();
    //cImage.RemoveAlpha();
    //cImage.Print();

    cPng.PrintChannels();
    //cPng.RemoveAlpha();
    //cPng.PrintChannels();

    cJpeg.PrintChannels();
    //cJpeg.RemoveAlpha();
    //cJpeg.PrintChannels();

    std::cout << std::endl;

    std::vector<Image> vTablaImg;
    vTablaImg.push_back(cImage);
    vTablaImg.push_back(cJpeg);
    vTablaImg.push_back(cPng);

    RemoveAlphas(vTablaImg);
}
// EOF
