#include <iostream>
#include <algorithm>

using namespace std;

void shell_sort(int*A, int n) {
    for(int gap = n/2; gap >= 1; gap /= 2) {
        for(int i = gap; i < n; i++) {
            int k = A[i];
            int j = i - gap;
            while(j >= 0 && A[j] > k) {
                A[j + gap] = A[j];
                j = j - gap;
            }
            A[j + gap] = k;
        }
    }
}

int findMax(int*A, int n) {
    int max = -3213423;
    for(int i = 0; i < n; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void count_sort(int*A, int n) {
    int max = findMax(A, n);
    int *temp = new int[max+1];
    for(int i = 0; i < max  + 1; i++) {
        temp[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        temp[A[i]] = temp[A[i]] + 1;
    }
    int i = 0; int j = 0;
    while(j <= max  + 1) {
        if(temp[j] > 0) {
            A[i] = j;
            temp[j] = temp[j] - 1;
            i++;
        }
        else {
            j++;
        }
    }
}

int partition(int* A, int left, int right, int pivot){
    while(left<= right) {
        while (A[left] < pivot) {
            left++;
        }
        while (A[right] > pivot) {
            right--;
        }
        if(left <= right) {
            swap(A[left], A[right]);
            left++;
            right--;
        }
    }
    return left;
}

void quick_sort(int*A, int left, int right) {
    if(left >= right) {
        return;
    }
    int pivot = A[(left + right) / 2];
    int partitionIndex = partition(A, left, right, pivot);
    quick_sort(A, left, partitionIndex-1);
    quick_sort(A, partitionIndex, right);
}

void merge(int* A, int left, int right, int mid) {
    int *temp = new int[right + 1];
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right) {
        if(A[i] < A[j]) {
            temp[k++] = A[i++];
        }
        else {
            temp[k++] = A[j++];
        }
    }

    if (i > mid) {
        while(j <= right) {
            temp[k++] = A[j++];
        }
    }
    else {
        while(i <= mid) {
            temp[k++] = A[i++];
        }
    }

    for(k = left; k <= right; k++) {
        A[k] = temp[k];
    }
    
}

void merge_sort(int* A, int left, int right) {
    int mid = (left + right) / 2;
    if(left < right) {
        merge_sort(A, left, mid);
        merge_sort(A, mid+1, right);
        merge(A, left, right, mid);
    }
}

void selection_sort(int* A, int n) {
    for(int i = 0; i < n; i++) {
        int k = i;
        for(int j = i; j < n; j++) {
            if(A[j] < A[k]) {
                k = j;
            } 
        }
        swap(A[i], A[k]);
    }
}

void insertion_sort(int* A, int n) {
    for(int i = 0; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void bubble_sort(int* A, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            if(A[j+1] < A[j]) {
                swap(A[j], A[j+1]);
            }
        }
    }
}
void display(int* A, int n) {
    cout << "Sorted Array: { ";
    for(int i = 0; i < n; i++) {
        if(i != 0) {
            cout << ", ";
        }
        cout << A[i];
    }
    cout << " }" << endl;
}

int main() {
    int A[] = {4, 9, 1, 7, 10, 0, 6, 3, 8, 8, 2, 5};
    int n = sizeof(A)/ sizeof(A[0]);
    int left = 0;
    int right = n - 1;
    //insertion_sort(A, n);
    //selection_sort(A, n);
    //bubble_sort(A, n);
    //merge_sort(A, left, right);
    //quick_sort(A, left, right);
    //count_sort(A, n);
    shell_sort(A, n);
    display(A, n);

    return 0;
}