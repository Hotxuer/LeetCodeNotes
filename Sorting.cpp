//
// Created by mac on 2020/7/8.
//

#include "problem.h"

// 插入排序
void insertion_sort(int arr[], int length) {
    int i,j;
    for (i=1; i<length; i++) {
        int temp = arr[i];
        for (j=i; j>0 && arr[j-1]>temp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
}

// 希尔排序：插入排序升级版，步长由长到短
void shell_sort(int arr[], int length) {
    int i, j;
    for (int gap = length/2; gap>0; gap/=2) {
        for (i=gap; i<length; i++) {
            int temp = arr[i];
            for (j=i; j>=gap && arr[j-1]>temp; j-=gap) {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}

// 基数排序
int getMax(int arr[], int length) {
    if (!length) return 0;
    int maxNumber = arr[0];
    for (int i=1; i<length; i++) {
        maxNumber = max(arr[i], maxNumber);
    }
    return maxNumber;
}

void count_sort(int arr[], int length, int exp) {
    int* output;
    output = new int [length];
    int i=0;
    int count[10] = {10};

    for (i=0; i<length; i++) {
        count[(arr[i]/exp)%10]++;
    }

    for (i=1; i<10; i++) {
        count[i] += count[i-1];
    }

    for (i=length-1; i>=0; i--) {
        output[count[(arr[i]/10)%10]-1] = arr[i];
        count[(arr[i]/10)%10]--;
    }

    for (i=0; i<length; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(int arr[], int length) {
    int m = getMax(arr, length);
    for (int exp=1; m/exp>0; exp*=10) {
        count_sort(arr, length, exp);
    }
}

// 冒泡排序
void bubble_sort(int arr[], int length) {
    bool swap = false;
    for (int i=0; i<length-1; i++) {
        for (int j=0; j<length-1-i; j++) {
            if (arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swap = true;
            }
        }
        if (!swap) break;
    }
}

// 归并排序
void merge(int arr[], int left, int mid, int right) {
    int *result;
    result = new int[right-left+1];
    int i=left, j=mid+1, index=0;
    while (i<=mid && j<=right) {
        if (arr[i]<=arr[j]) {
            result[index++] = arr[i++];
        } else {
            result[index++] = arr[j++];
        }
    }
    while (i<=mid)
        result[index++] = arr[i++];
    while (j<=right)
        result[index++] = arr[j++];


    for (int i=0; i<right-left+1; i++) {
        arr[left+i] = result[i];
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left == right)
        return;
    int mid = (left+right)/2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

void mSort(int arr[], int length) {
    merge_sort(arr, 0, length-1);
}

// 快速排序
int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int temp;
    while (left < right) {
        while (arr[right]>=pivot && left<right)
            right--;
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        while (arr[left]<=pivot && left<right)
            left++;
        temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp;
    }
    return left;
}

void quick_sort(int arr[], int left, int right) {
    if (left<right) {
        int partitionIndex = partition(arr, left, right);
        quick_sort(arr, left, partitionIndex);
        quick_sort(arr, partitionIndex+1, right);
    }
}

void qSort(int arr[], int length) {
    quick_sort(arr, 0, length-1);
}

// 堆排序
void heapify(int arr[], int currentIndex, int length) {
    if (currentIndex<length) {
        int left = currentIndex*2 + 1;
        int right = currentIndex*2 + 2;

        // 把当前父节点位置看成最大的
        int max = currentIndex;

        if (left < length) {
            if (arr[left]>arr[max]) {
                max = left;
            }
        }

        if (right < length) {
            if (arr[right]>arr[max]) {
                max = right;
            }
        }

        if (max != currentIndex) {
            int temp = arr[max];
            arr[max] = arr[currentIndex];
            arr[currentIndex] = temp;

            heapify(arr, max, length);
        }
    }
}

void maxHeapify(int arr[], int length) {
    for (int i=length-1; i>=0; i--) {
        heapify(arr, i, length);
    }
}

void heap_sort(int arr[], int length) {
    for (int i=0; i<length; i++) {
        // 每次建堆就可以排出一个元素了
        maxHeapify(arr, length-i);

        // 交换（最大值堆，最大值在堆顶arr[0]，交换到末尾，下次就考虑前n-1个
        int temp = arr[0];
        arr[0] = arr[length-1-i];
        arr[length-1-i] = temp;
    }
}