//HihgPassFilterAlgorithm implement high pass filter of bmp image data.
//How to use:
//BmpImageData * bmp_image = new BmpImageData();
//bmp_image->Load("./data/lena_color.bmp");
//FilterAlgorithm* high_pass_filter = new HighPassFilterAlgorithm(bmp_image);
//high_pass_filter->Filter();
//auto high_pass_image = static_cast<BmpImageData*>(high_pass_filter->GetFilterImage());
//high_pass_image->Save("./output/high_pass.bmp");

#ifndef HIGH_PASS_FILTER_ALGORITHM_H
#define HIGH_PASS_FILTER_ALGORITHM_H
#include "filter_algorithm.h"
#include "bmp_image_data.h"

class HighPassFilterAlgorithm : public FilterAlgorithm {
public:

	/// <summary> Constructor of MeanFilterAlgorithm </summary>
	/// <param name="input_bmp"> BmpImageData* type, input is bmp image </param>
	HighPassFilterAlgorithm(BmpImageData* input_bmp);
	~HighPassFilterAlgorithm();

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