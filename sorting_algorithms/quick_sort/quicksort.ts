function partition(A : Array<number>, start : number, end : number) {
    let pivot : number = A[end]
    let i : number = start - 1
    for (let j = start; j < end; j++) {
        if (A[j] >= pivot) { // <= for ascending order, >= for descending order 
            i++
            [A[i], A[j]] = [A[j], A[i]]
        }
    }
    [A[i + 1], A[end]] = [A[end], A[i + 1]]
    return i + 1
}

function quicksort(A : Array<number>, start : number, end : number) {
    if (start < end) {
        let q : number = partition(A, start, end)
        quicksort(A, start, q - 1)
        console.log(end)
        quicksort(A, q + 1, end)
    }
}

let A : Array<number> = [5, 4, 3, 2, 1]
quicksort(A, 0, A.length - 1)
console.log(A)
