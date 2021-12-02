//BmpImageData * bmp_image = new BmpImageData();
//bmp_image->Load("./data/lena_color.bmp");
//FilterAlgorithm* sobel_filter = new SobelFilterAlgorithm(bmp_image);
//sobel_filter->Filter();
//auto sobel_image = static_cast<BmpImageData*>(sobel_filter->GetFilterImage());
//sobel_image->Save("./output/sobel.bmp");

#ifndef SOBEL_FILTER_ALGORITHM_H
#define SOBEL_FILTER_ALGORITHM_H
#include "filter_algorithm.h"
#include "bmp_image_data.h"

class SobelFilterAlgorithm : public FilterAlgorithm {
public:

	/// <summary> Constructor of SobelFilterAlgorithm </summary>
	/// <param name="input_bmp"> BmpImageData* type, input is bmp image </param>
	SobelFilterAlgorithm(BmpImageData* input_bmp);
	~SobelFilterAlgorithm();

	/// <summary> Get BmpImageData </summary>
	/// <returns> void* type, return BmpImageData </returns>
	virtual void* GetFilterImage() override;

	/// <summary> Do filter </summary>
	/// <returns> void type </returns>
	virtual void Filter() override;
private:
	BmpImageData* input_bmp_;
	BmpImageData* output_bmp_;
};
#endif