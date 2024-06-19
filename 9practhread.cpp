#include <iostream>
#include <vector>
#include <thread>
#include <functional>
using namespace std;

class MergeSort {
public:
    void Sort(vector<int>& numbers) {
        if (numbers.size() <= 1) return;
        vector<int> left(numbers.begin(), numbers.begin() + numbers.size() / 2);
        vector<int> right(numbers.begin() + numbers.size() / 2, numbers.end());

        Sort(left);
        Sort(right);

        Merge(numbers, left, right);
    }

private:
    void Merge(vector<int>& numbers,vector<int>& left,vector<int>& right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                numbers[k++] = left[i++];
            }
            else {
                numbers[k++] = right[j++];
            }
        }

        while (i < left.size()) numbers[k++] = left[i++];
        while (j < right.size()) numbers[k++] = right[j++];
    }
};

int main() {

    setlocale(LC_ALL, "ru");

    vector<int> numbers(10);

    cout << "Введите 10 чисел: ";
    for (int i = 0; i < 10; ++i) {
        cin >> numbers[i];
    }

    MergeSort mergeSort;
    thread mergeSortThread([&mergeSort, &numbers]() {
        mergeSort.Sort(numbers);
        });

    mergeSortThread.join();

    cout << "Отсортированный массив: ";
    for (const int& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
