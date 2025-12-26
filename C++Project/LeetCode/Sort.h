#pragma once
#include <iterator>
#include <type_traits>
#include <vector>
#include <algorithm>


#pragma region _Forward Declaration_

template<typename _Ranlt, typename _Pr>
void _QuickSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

template<typename _Ranlt,typename _Pr>
void _InsertSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

template<typename _Ranlt, typename _Pr>
void _HillSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

template<typename _Ranlt, typename _Pr>
void _PopSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

template<typename _Ranlt, typename _Pr>
void _SelectSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

template<typename _Ranlt, typename _Pr>
void _MergerSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

template<typename _Ranlt, typename _Pr>
void _BucketSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

#pragma endregion

#pragma region _QuickSort_

template<typename _Ranlt, typename _Pr>
void quickSort(const _Ranlt _First, const _Ranlt _Last, _Pr _Pred) {
	static_assert(
		std::is_same_v<
		typename std::iterator_traits<_Ranlt>::iterator_category,
		std::random_access_iterator_tag
		>,
		"quickSort requires random access iterators"
		);

	if (_First >= _Last)return;

	_QuickSort_unchecked(_First, _Last, _Pred);
}

template<typename _Ranlt>
void quickSort(const _Ranlt _First, const _Ranlt _Last) {
	quickSort(_First, _Last, std::less<>());
}

template<typename _Ranlt, typename _Pr>
void _QuickSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	_Ranlt _Low = _First;
	_Ranlt _High = _Last;
	--_High;
	auto _Pivot = *_First;
	while (_Low < _High) {
		while (_Low < _High && !_Pred(*_High, _Pivot)) {
			--_High;
		}
		*_Low = *_High;

		while (_Low < _High && !_Pred(_Pivot, *_Low)) {
			++_Low;
		}
		*_High = *_Low;
	}
	*_Low = _Pivot;

	if (_Low > _First + 1) {
		_QuickSort_unchecked(_First, _Low, _Pred);
	}
	if (_Low + 1 < _Last - 1) {
		_QuickSort_unchecked(_Low + 1, _Last, _Pred);
	}
}

#pragma endregion

#pragma region _Insert Sort_

template<typename _Ranlt, typename _Pr>
void insertSort(const _Ranlt _First, const _Ranlt _Last, _Pr _Pred) {
	static_assert(
		std::is_same_v<
		typename std::iterator_traits<_Ranlt>::iterator_category,
		std::random_access_iterator_tag
		>,
		"insertSort requires random access iterators"
		);

	if (_First >= _Last)return;

	_InsertSort_unchecked(_First, _Last, _Pred);
}

template<typename _Ranlt>
void insertSort(const _Ranlt _First, const _Ranlt _Last) {
	insertSort(_First, _Last, std::less<>());
}

template<typename _Ranlt, typename _Pr>
void _InsertSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	for (_Ranlt it = _First + 1;it < _Last;++it) {
		auto key = *it;
		_Ranlt temp = it - 1;
		while (temp >= _First && _Pred(key, *temp)) {
			*(temp + 1) = *temp;
			if (temp == _First) {
				break;
			}
			--temp;
		}
		if (temp == _First) {
			*temp = key;
		}
		else {
			*(temp + 1) = key;
		}
	}
}

#pragma endregion

#pragma region _Hill Sort_

template<typename _Ranlt, typename _Pr>
void hillSort(const _Ranlt _First, const _Ranlt _Last, _Pr _Pred) {
	static_assert(
		std::is_same_v<
		typename std::iterator_traits<_Ranlt>::iterator_category,
		std::random_access_iterator_tag
		>,
		"hillSort requires random access iterators"
		);

	if (_First >= _Last)return;

	_HillSort_unchecked(_First, _Last, _Pred);
}

template<typename _Ranlt>
void hillSort(const _Ranlt _First, const _Ranlt _Last) {
	hillSort(_First, _Last, std::less<>());
}

template<typename _Ranlt, typename _Pr>
void _HillSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	int space = std::distance(_First, _Last) / 2;
	while (space >= 1) {
		//处理每一个分组
		for (int i = 0;i < space;i++) {
			for (_Ranlt it = _First + i + space;it < _Last;it = it + space) {
				auto key = *it;
				_Ranlt temp = it - space;
				while (temp >= _First && _Pred(key, *temp)) {
					*(temp + space) = *temp;
					if (temp == _First) {
						break;
					}
					temp = temp - space;
				}
				if (temp == _First) {
					*temp = key;
				}
				else {
					*(temp + space) = key;
				}
			}
		}
		space = space / 2;
	}
}

#pragma endregion

#pragma region _Pop Sort_

template<typename _Ranlt, typename _Pr>
void popSort(const _Ranlt _First, const _Ranlt _Last, _Pr _Pred) {
	static_assert(
		std::is_same_v<
		typename std::iterator_traits<_Ranlt>::iterator_category,
		std::random_access_iterator_tag
		>,
		"popSort requires random access iterators"
		);

	if (_First >= _Last)return;

	_PopSort_unchecked(_First, _Last, _Pred);
}

template<typename _Ranlt>
void popSort(const _Ranlt _First, const _Ranlt _Last) {
	popSort(_First, _Last, std::less<>());
}

template<typename _Ranlt, typename _Pr>
void _PopSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	for (_Ranlt rt = _Last - 1;rt >= _First;--rt) {
		bool hasSwap = false;
		for (_Ranlt it = _First;it < rt;++it) {
			if (_Pred(*(it + 1), *it)) {
				swap(*it, *(it + 1));
				hasSwap = true;
			}
		}
		if (!hasSwap) {
			break;
		}
	}
}

#pragma endregion

#pragma region _Select Sort_

template<typename _Ranlt, typename _Pr>
void selectSort(const _Ranlt _First, const _Ranlt _Last, _Pr _Pred) {
	static_assert(
		std::is_same_v<
		typename std::iterator_traits<_Ranlt>::iterator_category,
		std::random_access_iterator_tag
		>,
		"selectSort requires random access iterators"
		);

	if (_First >= _Last)return;

	_SelectSort_unchecked(_First, _Last, _Pred);
}

template<typename _Ranlt>
void selectSort(const _Ranlt _First, const _Ranlt _Last) {
	selectSort(_First, _Last, std::less<>());
}

template<typename _Ranlt, typename _Pr>
void _SelectSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	for (_Ranlt it = _First;it < _Last;++it) {
		_Ranlt minIt = it;
		for (_Ranlt nt = it + 1;nt < _Last;++nt) {
			if (_Pred(*nt, *minIt)) {
				minIt = nt;
			}
		}
		std::swap(*it, *minIt);
	}
}

#pragma endregion

#pragma region _Merger Sort_

template<typename _Ranlt, typename _Pr>
void mergerSort(const _Ranlt _First, const _Ranlt _Last, _Pr _Pred) {
	static_assert(
		std::is_same_v<
		typename std::iterator_traits<_Ranlt>::iterator_category,
		std::random_access_iterator_tag
		>,
		"combineSort requires random access iterators"
		);

	if (_First >= _Last)return;

	_MergerSort_unchecked(_First, _Last, _Pred);
}

template<typename _Ranlt>
void mergerSort(const _Ranlt _First, const _Ranlt _Last) {
	mergerSort(_First, _Last, std::less<>());
}

template<typename _Ranlt, typename _Pr>
void _MergerSort_unchecked_withTemp(_Ranlt _SourceFirst, _Ranlt _SourceLast, _Ranlt _TargetFirst, _Pr _Pred) {

	if (_SourceFirst + 1 < _SourceLast) {
		auto size = std::distance(_SourceFirst, _SourceLast);
		_Ranlt _TargetMid = _TargetFirst + size / 2;
		_Ranlt _SourceMid = _SourceFirst + size / 2;

		_CombineSort_unchecked_withTemp(_TargetFirst, _TargetMid, _SourceFirst, _Pred);
		_CombineSort_unchecked_withTemp(_TargetMid, _TargetFirst + size, _SourceMid, _Pred);

		_Ranlt _Left = _SourceFirst, _Right = _SourceMid;
		_Ranlt _Target = _TargetFirst;

		while (_Left < _SourceMid && _Right < _SourceLast) {
			if (_Pred(*_Left, *_Right)) {
				*_Target = *_Left;
				++_Left;
			}
			else {
				*_Target = *_Right;
				++_Right;
			}
			++_Target;
		}

		while (_Left < _SourceMid) {
			*_Target = *_Left;
			++_Left;
			++_Target;
		}

		while (_Right < _SourceLast) {
			*_Target = *_Right;
			++_Right;
			++_Target;
		}
	}
}

template<typename _Ranlt, typename _Pr>
void _MergerSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred)
{
	using _ValueType = typename std::iterator_traits<_Ranlt>::value_type;
	std::vector<_ValueType> temp(_First, _Last);
	_CombineSort_unchecked_withTemp(temp.begin(), temp.end(), _First, _Pred);
}

#pragma endregion

#pragma region _Bucket Sort_

template<typename _Ranlt, typename _Pr>
void bucketSort(const _Ranlt _First, const _Ranlt _Last, _Pr _Pred) {
	static_assert(
		std::is_same_v<
		typename std::iterator_traits<_Ranlt>::iterator_category,
		std::random_access_iterator_tag
		>,
		"bucketSort requires random access iterators"
		);

	if (_First >= _Last)return;

	_BucketSort_unchecked(_First, _Last, _Pred);
}

template<typename _Ranlt>
void bucketSort(const _Ranlt _First, const _Ranlt _Last) {
	bucketSort(_First, _Last, std::less<>());
}

template<typename _Ranlt,typename _Pr>
void _BucketSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	using ValueType = typename std::iterator_traits<_Ranlt>::value_type;
	size_t bucketCout = _Last - _First;
	std::vector<std::vector<ValueType>> buckets(bucketCout);

	auto minmax_it = std::minmax_element(_First, _Last);
	ValueType minValue = *minmax_it.first;
	ValueType maxValue = *minmax_it.second;
	if (minValue == maxValue) return;

	const ValueType range = maxValue - minValue;

	for (_Ranlt it = _First;it < _Last;++it) {
		double normalized = (static_cast<double>(*it - minValue) / range) * (bucketCout - 1);
		size_t idx = static_cast<size_t>(normalized);
		idx = std::max(static_cast<size_t>(0), std::min(idx, bucketCout - 1));
		buckets[idx].push_back(*it);
	}

	_Ranlt dest = _First;
	for (auto it : buckets) {
		if (!it.empty()) {
			_InsertSort_unchecked(it.begin(), it.end(), _Pred);
			dest = copy(it.begin(), it.end(), dest);
		}
	}
}

#pragma endregion


#pragma region _Heap Sort_


template<typename _Ranlt, typename _Pr>
void _HeapSort_builder(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	size_t offset = 2 * std::distance(_First, _Last) + 1;
	_Ranlt temp = _First;
	for (_Ranlt it = _First + offset;it < _Last;it = it + 2 * std::distance(it, _Last) + 1) {
		if (it + 1 < _Last) {
			if (*(it + 2 * std::distance(it, _Last) + 1) > *(it + 2 * std::distance(it, _Last) + 2)) {
				if (*temp < *(it + 2 * std::distance(it, _Last) + 1)) {
					std::swap(*temp, *(it + 2 * std::distance(it, _Last) + 1));
					temp = it + 2 * std::distance(it, _Last) + 1;
				}
			}
			else {
				if (*temp < *(it + 2 * std::distance(it, _Last) + 2)) {
					std::swap(*temp, *(it + 2 * std::distance(it, _Last) + 2));
					temp = it + 2 * std::distance(it, _Last) + 2;
					it++;
				}
			}
		}
	}
}


template<typename _Ranlt,typename _Pr>
void _HeapSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	size_t start = (std::distance(_First, _Last) - 2) / 2;	
	for (_Ranlt it = _First + start;it >= _First;--it) {
		_HeapSort_builder(_First, _Last, _Pred);
	}
	_Ranlt tempLast = _Last;
	while (tempLast != _First) {
		tempLast = tempLast - 1;
		std::swap(*_First, *tempLast);
		_HeapSort_builder(_First, tempLast, _Pred);
	}
}




#pragma endregion














