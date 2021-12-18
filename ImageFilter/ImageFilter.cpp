//It's a example for image filter. It's only for *bmp and color(RGB).

#include "stdafx.h"
#include <iostream>
#include "mean_filter_algorithm.h"
#include "sobel_filter_algorithm.h"
#include "high_pass_filter_algorithm.h"
#include "gaussian_filter_algorithm.h"
#include "bmp_image_data.h"

int main()
{
	BmpImageData * bmp_image = new BmpImageData();
	bmp_image->Load("./data/lena_color.bmp");

	FilterAlgorithm* mean_filter = new MeanFilterAlgorithm(bmp_image);
	mean_filter->Filter();
	auto mean_image = static_cast<BmpImageData*>(mean_filter->GetFilterImage());
	mean_image->Save("./output/mean.bmp");

	FilterAlgorithm* sobel_filter = new SobelFilterAlgorithm(bmp_image);
	sobel_filter->Filter();
	auto sobel_image = static_cast<BmpImageData*>(sobel_filter->GetFilterImage());
	sobel_image->Save("./output/sobel.bmp");

	FilterAlgorithm* high_pass_filter = new HighPassFilterAlgorithm(bmp_image);
	high_pass_filter->Filter();
	auto high_pass_image = static_cast<BmpImageData*>(high_pass_filter->GetFilterImage());
	high_pass_image->Save("./output/high_pass.bmp");

	FilterAlgorithm* gaussian_filter = new GaussianFilterAlgorithm(bmp_image, 1.0);
	gaussian_filter->Filter();
	auto gaussian_image = static_cast<BmpImageData*>(gaussian_filter->GetFilterImage());
	gaussian_image->Save("./output/gaussian.bmp");

	system("pause");
	return 0;
}