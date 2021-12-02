//ImageData is a superclass for all of image data
#ifndef IMAGE_DATA_H
#define IMAGE_DATA_H

class ImageData {
public:

	/// <summary> Load image </summary>
	/// <param name="filename"> char* type, load path </param>
	/// <returns> bool type, false:fail, true:success </returns>
	virtual bool Load(char* filename) = 0;

	/// <summary> Save image </summary>
	/// <param name="filename"> char* type, save path </param>
	/// <returns> bool type, false:fail, true:success </returns>
	virtual bool Save(char* filename) = 0;

	/// <summary> Get height of image </summary>
	/// <returns> int type, return height </returns>
	virtual int GetHeight() { return height; };

	/// <summary> Get width of image </summary>
	/// <returns> int type, return width </returns>
	virtual int GetWidth() { return width; };

protected:
	int height;
	int width;
};
#endif