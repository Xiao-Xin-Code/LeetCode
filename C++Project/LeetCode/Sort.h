#pragma once
#include <iterator>
#include <type_traits>

#pragma region Ç°ÏòÉùÃ÷

template<typename _Ranlt, typename _Pr>
void _QuickSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

template<typename _Ranlt,typename _Pr>
void _InsertSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred);

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
		while (_Low < _High && _Pred(_Pivot, *_High)) {
			--_High;
		}
		*_Low = *_High;

		while (_Low < _High && !_Pred(_Pivot, *_Low)) {
			++_Low;
		}
		*_High = *_Low;
	}
	*_Low = _Pivot;

	if (_Low - 1 > _First) {
		_QuickSort_unchecked(_First, _Low, _Pred);
	}
	if (_Low + 1 < _Last - 1) {
		_QuickSort_unchecked(_Low + 1, _Last, _Pred);
	}
}

#pragma endregion


template<typename _Ranlt, typename _Pr>
void _InsertSort_unchecked(_Ranlt _First, _Ranlt _Last, _Pr _Pred) {
	for (_Ranlt it = _First + 1;it < _Last;++it) {
		auto key = *it;
		_Ranlt temp = it - 1;
		while (temp >= _First && _Pred(key, *temp)) {
			*(temp + 1) = *temp;
			if (temp != _First) {
				--temp;
			}
		}
		if (temp == _First) {
			*temp = key;
		}
		else {
			*(temp + 1) = key;
		}
	}
}




