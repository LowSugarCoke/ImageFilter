//MeanFilterAlgorithm implement mean filter of bmp image data.
//How to use:
//BmpImageData * bmp_image = new BmpImageData();
//bmp_image->Load("./data/lena_color.bmp");
//FilterAlgorithm* mean_filter = new MeanFilterAlgorithm(bmp_image);
//mean_filter->Filter();
//auto mean_image = static_cast<BmpImageData*>(mean_filter->GetFilterImage());
//mean_image->Save("./output/mean.bmp");

#ifndef MEAN_FILTER_ALGORITHM_H
#define MEAN_FILTER_ALGORITHM_H
#include "filter_algorithm.h"
#include "bmp_image_data.h"

class MeanFilterAlgorithm : public FilterAlgorithm {
public:

	/// <summary> Constructor of MeanFilterAlgorithm </summary>
	/// <param name="input_bmp"> BmpImageData* type, input is bmp image </param>
	MeanFilterAlgorithm(BmpImageData* input_bmp);
	~MeanFilterAlgorithm();

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