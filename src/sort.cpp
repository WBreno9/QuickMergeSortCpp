#include "sort.h"

void merge(std::vector<int64_t>& data, size_t p, size_t q, size_t r)
{
    std::vector<int64_t> array0(data.begin() + p, data.begin() + (q + 1));
    std::vector<int64_t> array1(data.begin() + q, data.begin() + (r + 2));

    array0[q - p] = INT64_MAX;
    array1[r - q + 1] = INT64_MAX;

    size_t i = 0, j = 0, k = p;

    while(!(array0[i] == INT64_MAX && array1[j] == INT64_MAX)) {
        if (array0[i] < array1[j]) {
            data[k] = array0[i++];
        } else {
            data[k] = array1[j++];
        }
        ++k;
    }
}

void _mergeSort(std::vector<int64_t>& data, size_t p, size_t r)
{
    size_t q;

    if (p < r) {
        q = (p+r)/2.0f;
        _mergeSort(data, p  , q);
        _mergeSort(data, q+1, r);
        merge(data, p, q+1, r);
    }
}

void mergeSort(std::vector<int64_t>& data)
{
    _mergeSort(data, 0, data.size()-1);
}