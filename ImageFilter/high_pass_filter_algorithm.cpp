#include "stdafx.h"
#include"high_pass_filter_algorithm.h"

HighPassFilterAlgorithm::HighPassFilterAlgorithm(BmpImageData * input_bmp)
{
	input_bmp_ = input_bmp;
	output_bmp_ = new BmpImageData(input_bmp->GetHeight(), input_bmp->GetWidth());
}

HighPassFilterAlgorithm::~HighPassFilterAlgorithm()
{
}

void* HighPassFilterAlgorithm::GetFilterImage()
{
	return output_bmp_;
}

void HighPassFilterAlgorithm::Filter()
{
	auto height = input_bmp_->GetHeight();
	auto rowsize = input_bmp_->rowsize;

	for (int j = 1; j < height - 1; j++)
	{
		for (int i = 3; i < rowsize - 3; i += 3)
		{
			for (int k = 0; k < 3; ++k)
			{
				output_bmp_->term[j*rowsize + i + k] =
					-((input_bmp_->term[(j - 1)*rowsize + (i - 3) + k])
						- (input_bmp_->term[(j - 1)*rowsize + i + k])
						- (input_bmp_->term[(j - 1)*rowsize + (i + 3) + k])
						- (input_bmp_->term[j*rowsize + (i - 3) + k])
						+ (input_bmp_->term[j*rowsize + i + k]) * 8
						- (input_bmp_->term[j*rowsize + (i + 3) + k])
						- (input_bmp_->term[(j + 1)*rowsize + (i - 3) + k])
						- (input_bmp_->term[(j + 1)*rowsize + i + k])
						- (input_bmp_->term[(j + 1)*rowsize + (i + 3) + k])) / 9.0;
			}
		}
	}
}