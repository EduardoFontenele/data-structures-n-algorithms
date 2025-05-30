function max(arr) {
    console.log('R')
    if (arr.length == 1) {
        return arr[0];
    }

    let maxOfRemainder = max(arr.slice(1));

    if(arr[0] > maxOfRemainder) {
        return arr[0];
    } else {
        return maxOfRemainder;
    }
}

const maximum = max([1, 2, 3, 4]);
console.log(maximum);

