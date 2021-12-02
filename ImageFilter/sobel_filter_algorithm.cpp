#include "stdafx.h"
#include "sobel_filter_algorithm.h"

SobelFilterAlgorithm::SobelFilterAlgorithm(BmpImageData * input_bmp)
{
	input_bmp_ = input_bmp;
	output_bmp_ = new BmpImageData(input_bmp->GetHeight(), input_bmp->GetWidth());
}

SobelFilterAlgorithm::~SobelFilterAlgorithm()
{
}

void * SobelFilterAlgorithm::GetFilterImage()
{
	return output_bmp_;
}

void SobelFilterAlgorithm::Filter()
{
	int pixel_x;
	int pixel_y;

	float sobel_x[3][3] =
	{ { -1, 0, 1 },
	{ -2, 0, 2 },
	{ -1, 0, 1 } };

	float sobel_y[3][3] =
	{ { -1, -2, -1 },
	{ 0,  0,  0 },
	{ 1,  2,  1 } };

	for (int j = 1; j < input_bmp_->GetHeight() - 1; j++)
	{
		for (int i = 3; i < input_bmp_->rowsize - 3; i += 3)
		{
			for (int k = 0; k < 3; ++k)
			{
				pixel_x = (sobel_x[0][0] * input_bmp_->term[(j - 1)*input_bmp_->rowsize + (i - 3) + k])
					+ (sobel_x[0][1] * (input_bmp_->term[(j - 1)*input_bmp_->rowsize + i + k]))
					+ (sobel_x[0][2] * (input_bmp_->term[(j - 1)*input_bmp_->rowsize + (i + 3) + k]))
					+ (sobel_x[1][0] * (input_bmp_->term[j*input_bmp_->rowsize + (i - 3) + k]))
					+ (sobel_x[1][1] * (input_bmp_->term[j*input_bmp_->rowsize + i + k]))
					+ (sobel_x[1][2] * (input_bmp_->term[j*input_bmp_->rowsize + (i + 3) + k]))
					+ (sobel_x[2][0] * (input_bmp_->term[(j + 1)*input_bmp_->rowsize + (i - 3) + k]))
					+ (sobel_x[2][1] * (input_bmp_->term[(j + 1)*input_bmp_->rowsize + i + k]))
					+ (sobel_x[2][2] * (input_bmp_->term[(j + 1)*input_bmp_->rowsize + (i + 3) + k]));

				pixel_y = (sobel_y[0][0] * input_bmp_->term[(j - 1)*input_bmp_->rowsize + (i - 3) + k])
					+ (sobel_y[0][1] * (input_bmp_->term[(j - 1)*input_bmp_->rowsize + i + k]))
					+ (sobel_y[0][2] * (input_bmp_->term[(j - 1)*input_bmp_->rowsize + (i + 3) + k]))
					+ (sobel_y[1][0] * (input_bmp_->term[j*input_bmp_->rowsize + (i - 3) + k]))
					+ (sobel_y[1][1] * (input_bmp_->term[j*input_bmp_->rowsize + i + k]))
					+ (sobel_y[1][2] * (input_bmp_->term[j*input_bmp_->rowsize + (i + 3) + k]))
					+ (sobel_y[2][0] * (input_bmp_->term[(j + 1)*input_bmp_->rowsize + (i - 3) + k]))
					+ (sobel_y[2][1] * (input_bmp_->term[(j + 1)*input_bmp_->rowsize + i + k]))
					+ (sobel_y[2][2] * (input_bmp_->term[(j + 1)*input_bmp_->rowsize + (i + 3) + k]));

				int val = (int)sqrt((pixel_x * pixel_x) + (pixel_y * pixel_y));

				if (val < 0) val = 0;
				if (val > 255) val = 255;

				output_bmp_->term[j*input_bmp_->rowsize + i + k] = val;
			}
		}
	}
}