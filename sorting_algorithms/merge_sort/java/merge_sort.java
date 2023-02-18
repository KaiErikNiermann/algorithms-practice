package sorting_algorithms.merge_sort.java;

public class merge_sort {
    public static void merge(int[] A, int start, int mid, int end, int[] B) {
        int i = start, j = mid;
        for (int k = start; k < end; k++) {
            if (i < mid && (j >= end || A[i] <= A[j])) {
                B[k] = A[i];
                i = i + 1;
            } else {
                B[k] = A[j];
                j = j + 1;
            }
        }
    }

    public static void mergeSort(int[] B, int start, int end, int[] A) {
        if (end - start < 2) {
            return;
        }
        int mid = (start + end) / 2;
        mergeSort(A, start, mid, B);
        mergeSort(A, mid, end, B);
        merge(B, start, mid, end, A);
    }

    public static void main(String[] args) {
        int[] A = { 5, 4, 3, 2, 1 };
        int[] B = A.clone();
        mergeSort(B, 0, A.length, A);
        for (int i = 0; i < A.length; i++) {
            System.out.print(A[i] + " ");
        }
    }
}