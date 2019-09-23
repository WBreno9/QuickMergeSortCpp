#include "sort.h"

void merge(std::vector<int64_t>& v, size_t p, size_t q, size_t r)
{
    std::vector<int64_t> v0(v.begin() + p, v.begin() + (q + 1));
    std::vector<int64_t> v1(v.begin() + q, v.begin() + (r + 2));

    v0[q - p] = INT64_MAX;
    v1[r - q + 1] = INT64_MAX;

    uint64_t i = 0, j = 0, k = p;

    while(!(v0[i] == INT64_MAX && v1[j] == INT64_MAX)) {
        if (v0[i] < v1[j]) {
            v[k] = v0[i++];
        } else {
            v[k] = v1[j++];
        }
        ++k;
    }
}

void _mergeSort(std::vector<int64_t>& v, size_t p, size_t r)
{
    size_t q;

    if (p < r) {
        q = (p+r)/2.0f;
        _mergeSort(v, p  , q);
        _mergeSort(v, q+1, r);
        merge(v, p, q+1, r);
    }
}

void mergeSort(std::vector<int64_t>& v) { 
  _mergeSort(v, 0, v.size() - 1); 
}

void _quickSort(int64_t* v, int sz) {
  if (sz < 2) return;

  uint64_t pivot = sz - 1, wall = 0, n = 0;

  while (true) {
    while (v[n] > v[pivot]) n++;
    if (n >= pivot) {
      std::swap(v[n], v[wall]);
      break;
    }
    std::swap(v[n++], v[wall++]);
  }
  _quickSort(v, wall);
  _quickSort(&v[wall + 1], sz - (wall + 1));
}

void quickSort(std::vector<int64_t>& v) { _quickSort(v.data(), v.size()); }