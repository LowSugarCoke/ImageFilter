#include "stdafx.h"
#include "gaussian_filter_algorithm.h"

GaussianFilterAlgorithm::GaussianFilterAlgorithm(BmpImageData * input_bmp, double sigma)
{
	input_bmp_ = input_bmp;
	output_bmp_ = new BmpImageData(input_bmp->GetHeight(), input_bmp->GetWidth());
	sigma_ = sigma;
}

GaussianFilterAlgorithm::~GaussianFilterAlgorithm()
{
}

void* GaussianFilterAlgorithm::GetFilterImage()
{
	return output_bmp_;
}

void GaussianFilterAlgorithm::Filter()
{
	CalculateGussElement();
	auto height = input_bmp_->GetHeight();
	auto rowsize = input_bmp_->rowsize;

	for (int j = 1; j < height - 1; j++)
	{
		for (int i = 3; i < rowsize - 3; i += 3)
		{
			for (int k = 0; k < 3; ++k)
			{
				output_bmp_->term[j*rowsize + i + k] =
					((input_bmp_->term[(j - 1)*rowsize + (i - 3) + k])*guss_element_[0]
						+ (input_bmp_->term[(j - 1)*rowsize + i + k])*guss_element_[1]
						+ (input_bmp_->term[(j - 1)*rowsize + (i + 3) + k])*guss_element_[2]
						+ (input_bmp_->term[j*rowsize + (i - 3) + k])*guss_element_[3]
						+ (input_bmp_->term[j*rowsize + i + k])*guss_element_[4]
						+ (input_bmp_->term[j*rowsize + (i + 3) + k])*guss_element_[5]
						+ (input_bmp_->term[(j + 1)*rowsize + (i - 3) + k])*guss_element_[6]
						+ (input_bmp_->term[(j + 1)*rowsize + i + k])*guss_element_[7]
						+ (input_bmp_->term[(j + 1)*rowsize + (i + 3) + k]))*guss_element_[8];
			}
		}
	}
}

void GaussianFilterAlgorithm::CalculateGussElement()
{
	double sum = 0.0;

	guss_element_[0] = exp((-2) / (2 * sigma_*sigma_));
	guss_element_[1] = exp((-1) / (2 * sigma_*sigma_));
	guss_element_[2] = exp((-2) / (2 * sigma_*sigma_));
	guss_element_[3] = exp((-1) / (2 * sigma_*sigma_));
	guss_element_[4] = exp(0);
	guss_element_[5] = exp((-1) / (2 * sigma_*sigma_));
	guss_element_[6] = exp((-2) / (2 * sigma_*sigma_));
	guss_element_[7] = exp((-1) / (2 * sigma_*sigma_));
	guss_element_[8] = exp((-2) / (2 * sigma_*sigma_));

	for (int i = 0; i < 9; ++i)
	{
		sum += guss_element_[i];
	}

	for (int i = 0; i < 9; ++i)
	{
		guss_element_[i] = guss_element_[i] / sum;
	}
}