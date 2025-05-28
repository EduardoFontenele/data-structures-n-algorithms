function quicksort(array : number[], leftPointer: number, rightPointer: number) : void {
    if (leftPointer >= rightPointer) {
        return;
    }

    let pivotIndex: number = rightPointer;
    let pivot: number = array[pivotIndex];
    rightPointer--;

    while(true) {
        while(array[leftPointer] < pivot) {
            leftPointer++;
        }

        while(array[rightPointer] > pivot) {
            rightPointer--
        }

        if(leftPointer >= rightPointer) {
            break;
        } else {
            let leftVal: number = array[leftPointer];
            let rightVal: number = array[rightPointer];
            array[leftPointer] = rightVal;
            array[rightPointer] = leftVal;
            leftPointer++;
        }
    }

    array[pivotIndex] = array[leftPointer];
    array[leftPointer] = pivot;

    quicksort(array, 0, leftPointer - 1);
    quicksort(array, leftPointer + 1, pivotIndex);
}

function quicksortHelper(array: number[]): void {
    quicksort(array, 0, array.length - 1);
}

const array = [0, 5, 2, 1, 6, 3];
quicksortHelper(array);
console.log(array)