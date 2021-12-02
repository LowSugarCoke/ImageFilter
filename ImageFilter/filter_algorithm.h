//Filter Algorithm is a superclass for all algorithm
#ifndef FILTER_ALGORITHM_H
#define FILTER_ALGORITHM_H

class FilterAlgorithm {
public:
	FilterAlgorithm();
	~FilterAlgorithm();

	/// <summary> Do filter </summary>
	/// <returns> void type </returns>
	virtual void Filter() = 0;

	/// <summary> Get ImageData </summary>
	/// <returns> void* type, return ImageData </returns>
	virtual void* GetFilterImage() = 0;
};
#endif
