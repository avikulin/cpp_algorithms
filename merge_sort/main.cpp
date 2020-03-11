#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

void print_vector(const std::string& msg, const std::vector<std::reference_wrapper<int>>& sequence){
    cout << msg << ": ";
    std::for_each(sequence.cbegin(), sequence.cend(), [](int& v){cout << v << " ";});
    cout << endl;
}

std::vector<std::reference_wrapper<int>> slice(const std::vector<std::reference_wrapper<int>>& source, size_t begin_idx, size_t end_idx){
    return vector<std::reference_wrapper<int>>(source.cbegin()+begin_idx, source.cbegin()+end_idx);
}

std::vector<std::reference_wrapper<int>> merge(const std::vector<std::reference_wrapper<int>>& source1, const std::vector<std::reference_wrapper<int>>& source2){
    std::vector<std::reference_wrapper<int>> res;
    size_t source1_offset = 0;
    size_t source2_offset = 0;
    size_t res_size = source1.size()+source2.size();
    for (size_t idx=0; idx< res_size;++idx){
        if (source1[source1_offset]<source2[source2_offset]){
            // берем значение из коллекции №1
            res.push_back(source1[source1_offset]);
            source1_offset++;
        } else {
            // берем значение из коллекции №2
            res.push_back(source2[source2_offset]);
            source2_offset++;
        }

        // если один из оффсетов вышел за пределы коллекции - значит все значения уже перенесены в итоговую выборку
        // значит остаток второй выборки можно смело перенести в итоговую.
        // проверять выход оффсетов можно по очереди - одновременно они не случатся.
        if (source1_offset >= source1.size()){
            res.insert(res.end(), source2.begin()+source2_offset, source2.end());
            return res;
        }

        if (source2_offset >= source2.size()){
            res.insert(res.end(), source1.begin()+source1_offset, source1.end());
            return res;
        }
    }
    return res;
}

void mergeSort(vector<std::reference_wrapper<int>>& values, int level = 0){
    print_vector("Splitting("+std::to_string(level)+ ")",values);

    if (values.size()>1) {
        size_t mid = values.size()/2;
        vector<std::reference_wrapper<int>> lefthalf = slice(values, 0, mid);
        vector<std::reference_wrapper<int>> righthalf = slice(values, mid, values.size());
        level++;
        mergeSort(lefthalf, level);
        mergeSort(righthalf, level);

        vector<std::reference_wrapper<int>> res = merge(lefthalf, righthalf);
        std::copy(res.begin(), res.end(), values.begin());
        print_vector("Merged ("+std::to_string(level)+ ")",values);
    } else {
        print_vector("Omitting ("+std::to_string(level)+ ")",values);
    }
}

int main() {
    cout << "Starting mergesort example...\n\n" << endl;
    vector<int> data {44,26,93,17,77,31,44,55,20};
    vector<std::reference_wrapper<int>> view_data(data.begin(), data.end());

    mergeSort(view_data);
    print_vector("The whole data", view_data);

    return 0;
}
