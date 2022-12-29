function merge(A: Array<number>, start: number, mid: number, end: number, B: Array<number>) {
    let i = start
    let j = mid

    for (let k : number = start; k < end; k++) {
        if (i < mid && (j >= end || A[i] <= A[j])) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
    }
}

function mergeSort(B: Array<number>, start : number, end : number, A: Array<number>) {
    if (end - start <= 1) return;

    let mid = Math.floor((start + end) / 2);
    mergeSort(A, start, mid, B);
    mergeSort(A, mid, end, B);
    merge(B, start, mid, end, A);
}

// array of 5 ints 
let arr : Array<number> = [5, 4, 3, 2, 1];
let arr2 : Array<number> = arr.slice();

mergeSort(arr2, 0, arr.length, arr);
console.log(arr);