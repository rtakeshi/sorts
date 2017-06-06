#include <iostream>
#include <iomanip>
#include "sort.cpp"
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

int randomNumber(int menor, int maior){
    std::random_device random;
    std::mt19937 eng(random());
    std::uniform_int_distribution<> distr(menor, maior); // define o range

    return distr(eng);
}



//Recebe um vetor de doubles contendo os tempos e soma a cada execução
void exec (double *v){
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<double> elapsed_time;

    std::cout << std::setprecision(10) << std::fixed;


    //------------------------------------------------------

    int vSelection[10000];
    int vInsert[10000];
    int vMerge[10000];
    int vQuickSort[10000];
    int vShellSort[10000];
    int vHeapSort[10001];
    int vStlSort[10000];
    int vStlStableSort[10000];
    int vStlSortHeap[10000];

    vHeapSort[0] = -1;
    //Cenário 1
     for(int k = 0; k <= 9999; k++){
        int n = randomNumber(1, 1000000);

        vSelection[k] = n;
        vInsert[k] = n;
        vMerge[k] = n;
        vQuickSort[k] = n;
        vShellSort[k] = n;
        vHeapSort[k+1] = n;
        vStlSort[k] = n;
        vStlStableSort[k] = n;
        vStlSortHeap[k] = n;
    }

    start = std::chrono::steady_clock::now();
    selectionSort(vSelection, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[0] = v[0] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    insertSort(vInsert, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[1] = v[1] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    shellSort(vShellSort, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[2] = v[2] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    heapsort(vHeapSort, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[3] = v[3] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    mergeSort(vMerge, 0, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[4] = v[4] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    quickSort(vQuickSort, 0, 9999);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[5] = v[5] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::sort(vStlSort, vStlSort+10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[6] = v[6] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::stable_sort(vStlStableSort, vStlStableSort+10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[7] = v[7] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::make_heap(vStlSortHeap, vStlSortHeap + 10000);
    std::sort_heap(vStlSortHeap, vStlSortHeap+10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[8] = v[8] + elapsed_time.count();

    //Cenário 2

    int vSelection2[100000];
    int vInsert2[100000];
    int vMerge2[100000];
    int vQuickSort2[100000];
    int vShellSort2[100000];
    int vHeapSort2[100001];
    int vStlSort2[100000];
    int vStlStableSort2[100000];
    int vStlSortHeap2[100000];
    vHeapSort[0] = -1;

     for(int k = 0; k <= 99999; k++){
        int n = randomNumber(1, 1000000);
        vSelection2[k] = n;
        vInsert2[k] = n;
        vMerge2[k] = n;
        vQuickSort2[k] = n;
        vShellSort2[k] = n;
        vHeapSort2[k+1] = n;
        vStlSort2[k] = n;
        vStlStableSort2[k] = n;
        vStlSortHeap2[k] = n;
    }



    start = std::chrono::steady_clock::now();
    selectionSort(vSelection2, 100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[9] = v[9] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    insertSort(vInsert2, 100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[10] = v[10] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    shellSort(vShellSort2, 100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[11] = v[11] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    heapsort(vHeapSort2, 100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[12] = v[12] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    mergeSort(vMerge2, 0, 100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[13] = v[13] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    quickSort(vQuickSort2, 0, 99999);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[14] = v[14] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::sort(vStlSort2, vStlSort2+100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[15] = v[15] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::stable_sort(vStlStableSort2, vStlStableSort2+100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[16] = v[16] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::make_heap(vStlSortHeap2, vStlSortHeap2 + 100000);
    std::sort_heap(vStlSortHeap2, vStlSortHeap2 + 100000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[17] = v[17] + elapsed_time.count();

    //Cenário 3
    int vSelection3[10000];
    int vInsert3[10000];
    int vMerge3[10000];
    int vQuickSort3[10000];
    int vShellSort3[10000];
    int vHeapSort3[10001];
    int vStlSort3[10000];
    int vStlStableSort3[10000];
    int vStlSortHeap3[10000];

    vHeapSort[0] = -1;

     for(int k = 0; k <= 9999; k++){
        int n = k;

        vSelection3[k] = n;
        vInsert3[k] = n;
        vMerge3[k] = n;
        vQuickSort3[k] = n;
        vShellSort3[k] = n;
        vHeapSort3[k+1] = n;
        vStlSort3[k] = n;
        vStlStableSort3[k] = n;
        vStlSortHeap3[k] = n;
    }

    start = std::chrono::steady_clock::now();
    selectionSort(vSelection3, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[18] = v[18] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    insertSort(vInsert3, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[19] = v[19] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    shellSort(vShellSort3, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[20] = v[20] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    heapsort(vHeapSort3, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[21] = v[21] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    mergeSort(vMerge3, 0, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[22] = v[22] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    quickSort(vQuickSort3, 0, 9999);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[23] = v[23] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::sort(vStlSort3, vStlSort3+10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[24] = v[24] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    std::stable_sort(vStlStableSort3, vStlStableSort3+10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[25] = v[25] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::make_heap(vStlSortHeap3, vStlSortHeap3 + 10000);
    std::sort_heap(vStlSortHeap3, vStlSortHeap3 + 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[26] = v[26] + elapsed_time.count();


    //Cenário 4
    int vSelection4[10000];
    int vInsert4[10000];
    int vMerge4[10000];
    int vQuickSort4[10000];
    int vShellSort4[10000];
    int vHeapSort4[10001];
    int vStlSort4[10000];
    int vStlStableSort4[10000];
    int vStlSortHeap4[10000];
    vHeapSort[0] = -1;

    int count = 0;
     for(int k = 9999; k >= 0; k--){

        vSelection4[count] = k;
        vInsert4[count] = k;
        vMerge4[count] = k;
        vQuickSort4[count] = k;
        vShellSort4[count] = k;
        vHeapSort4[count+1] = k;
        vStlSort4[count] = k;
        vStlStableSort4[count] = k;
        vStlSortHeap4[count] = k;
        count = count + 1;
    }


    start = std::chrono::steady_clock::now();
    selectionSort(vSelection4, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[27] = v[27] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    insertSort(vInsert4, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[28] = v[28] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    shellSort(vShellSort4, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[29] = v[29] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    heapsort(vHeapSort4, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[30] = v[30] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    mergeSort(vMerge4, 0, 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[31] = v[31] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    quickSort(vQuickSort4, 0, 9999);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[32] = v[32] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::sort(vStlSort4, vStlSort4+10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[33] = v[33] + elapsed_time.count();


    start = std::chrono::steady_clock::now();
    std::stable_sort(vStlStableSort4, vStlStableSort4+10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[34] = v[34] + elapsed_time.count();

    start = std::chrono::steady_clock::now();
    std::make_heap(vStlSortHeap4, vStlSortHeap4 + 10000);
    std::sort_heap(vStlSortHeap4, vStlSortHeap4 + 10000);
    end = std::chrono::steady_clock::now();
    elapsed_time = end - start;
    v[35] = v[35] + elapsed_time.count();


}



