//GaussianFilterAlgorithm implement mean filter of bmp image data.
//How to use:
//BmpImageData * bmp_image = new BmpImageData();
//bmp_image->Load("./data/lena_color.bmp");
//FilterAlgorithm* mean_filter = new GaussianFilterAlgorithm(bmp_image);
//gaussian_filter->Filter();
//auto gaussian_image = static_cast<BmpImageData*>(gaussian_filter->GetFilterImage());
//gaussian_image->Save("./output/gaussian.bmp");

#ifndef GAUSSIAN_FILTER_ALGORITHM_H
#define GAUSSIAN_FILTER_ALGORITHM_H
#include "filter_algorithm.h"
#include "bmp_image_data.h"
#include <math.h>

class GaussianFilterAlgorithm : public FilterAlgorithm {
public:

	/// <summary> Constructor of MeanFilterAlgorithm </summary>
	/// <param name="input_bmp"> BmpImageData* type, input is bmp image </param>
	/// <param name="sigma"> double type, input is sigma </param>
	GaussianFilterAlgorithm(BmpImageData* input_bmp, double sigma);
	~GaussianFilterAlgorithm();

	/// <summary> Get BmpImageData </summary>
	/// <returns> void* type, return BmpImageData </returns>
	virtual void* GetFilterImage() override;

	/// <summary> Do filter </summary>
	/// <returns> void type </returns>
	virtual void Filter() override;

private:
	BmpImageData* input_bmp_;
	BmpImageData* output_bmp_;
	double sigma_;
	double guss_element_[9];

	void CalculateGussElement();
};
#endif