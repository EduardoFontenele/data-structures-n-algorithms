// sizeof("ab") + totalSizeOfStrings(["c", "def", "ghij"])

function totalSizeOfStrings(array) {
    if(array.length == 1) return array[0].length;
    return array[0].length + totalSizeOfStrings(array.slice(1));
}

// console.log(totalSizeOfStrings(['ab', 'cd', 'efg', 'hijkl']))

// X + func(array.slice(1));

function sumOfEvenNumbers(array) {
    if(array.length == 1) return array[0] % 2 == 0 ? array[0] : 0;
    return array[0] % 2 == 0 ? array[0] + sumOfEvenNumbers(array.slice(1)) :
    sumOfEvenNumbers(array.slice(1));
}

// console.log(sumOfEvenNumbers([2, 3, 5, 6, 7, 4, 2]))

// index 1 = prev + index = 0 + 1 = 1;
// index 2 = prev + index = 1 + 2 = 3;
// index 3 = prev + index = 3 + 3 = 6;
// index 4 = prev + index = 6 + 4 = 10;
// index 5 = prev + index = 10 + 5 = 15;
// index 6 = prev + index = 15 + 6 = 21;
// index N = prev + index = prev + N;

function triangularNumbers(numberPosition) {
    let index = 1;
    let previousValue = 0;
    while(index < numberPosition + 1) {
        previousValue = index + previousValue;
        index++;
    }
    return previousValue;
}


function triangularNumbers2(numberPosition) {
    if(numberPosition == 1) return 1;
    if(numberPosition > 1) return numberPosition + triangularNumbers(numberPosition - 1);
}

let result = triangularNumbers(6);
console.log('without recursion:',result);

result = triangularNumbers2(6);
console.log('with recursion', result);

function firstXOccurrence(array) {

}