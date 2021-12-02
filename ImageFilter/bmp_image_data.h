//BmpImageData is a child class of ImageData.
//How to use:
//BmpImageData* image = new BmpImageData();
//image->Load(".\data\image.bmp");
//image->Save(".\output\output.bmp");

#ifndef BMP_IMAGE_DATA_H
#define BMP_IMAGE_DATA_H
#include "image_data.h"
#include<windows.h>
#include <fstream>
#include <iostream>

using namespace std;

class BmpImageData : public ImageData {
public:
	int rowsize;
	BYTE* term;

	BmpImageData();
	~BmpImageData();

	/// <summary> Constructor of BmpImageData </summary>
	/// <param name="height"> int type, image height </param>
	/// <param name="width"> int type, image width </param>
	BmpImageData(int height, int width);

	/// <summary> Load bmp image </summary>
	/// <param name="filename"> char* type, load path </param>
	/// <returns> bool type, false:fail, true:success </returns>
	virtual bool Load(char* filename) override;

	/// <summary> Save bmp image </summary>
	/// <param name="filename"> char* type, save path </param>
	/// <returns> bool type, false:fail, true:success </returns>
	virtual bool Save(char* filename) override;

private:
	void print(BITMAPINFOHEADER h);
};
#endif