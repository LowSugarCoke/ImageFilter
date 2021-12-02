#include "stdafx.h"
#include "bmp_image_data.h"

BmpImageData::BmpImageData()
{
}

BmpImageData::~BmpImageData()
{
}

BmpImageData::BmpImageData(int height, int width)
{
	this->height = height;
	this->width = width;
	rowsize = (3 * width + 3) / 4 * 4;
	term = new BYTE[height*rowsize];
}

bool BmpImageData::Load(char * filename)
{
	BITMAPFILEHEADER h;
	BITMAPINFOHEADER hInfo;
	ifstream f;
	f.open(filename, ios::binary);
	f.seekg(0, f.end);
	cout << "¹ÏÀÉ¤j¤p:" << f.tellg() << " bytes\n";
	f.seekg(0, f.beg);
	f.read((char*)&h, sizeof(h));
	f.read((char*)&hInfo, sizeof(hInfo));
	print(hInfo);
	if (h.bfType != 0x4d42 ||
		hInfo.biClrUsed != 0 ||
		hInfo.biBitCount != 24 ||
		hInfo.biCompression != 0 ||
		hInfo.biPlanes != 1)
	{
		cout << "error!! \n";
		f.close();
		return 0;
	}

	width = hInfo.biWidth;
	height = hInfo.biHeight;
	cout << "reading from " << filename << "....\n";
	*this = BmpImageData(height, width);
	f.read((char*)term, height*rowsize);
	f.close();
	return 1;
}

bool BmpImageData::Save(char * filename)
{
	BITMAPFILEHEADER h = {
		0x4d42,
		54L + rowsize*height,
		0,
		0,
		54
	};
	BITMAPINFOHEADER hInfo = {
		sizeof(BITMAPINFOHEADER),
		width,
		height,
		1,
		24,
		0,
		rowsize*height,
		3780,
		3780,
		0,
		0
	};
	cout << "writing into " << filename << "....\n";
	ofstream f;
	f.open(filename, ios::binary);
	f.write((char*)&h, sizeof(h));
	f.write((char*)&hInfo, sizeof(hInfo));
	f.write((char*)term, rowsize*height);
	f.close();
	return 1;
}

void BmpImageData::print(BITMAPINFOHEADER h)
{
	cout << "biSize:" << dec << h.biSize << endl;
	cout << "biWidth:" << h.biWidth << endl;
	cout << "biHeight:" << h.biHeight << endl;
	cout << "biBitCount:" << h.biBitCount << endl;
	cout << "biCompression:" << h.biCompression << endl;
	cout << "biSizeImage:" << h.biSizeImage << endl;
	cout << "biXPelsPerMeter:" << h.biXPelsPerMeter << endl;
}