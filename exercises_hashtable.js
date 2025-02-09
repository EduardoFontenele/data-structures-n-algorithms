function intersectionOfTwoArrays(array1, array2) {
    const firstArrayLength = array1.length;
    const secondArrayLength = array2.length;
    const result = [];

    if (firstArrayLength < secondArrayLength) {
        let map = array1.reduce((acc, value) => {
            acc[value] = true;
            return acc;
        }, {});

        for (let val of array2) {
            let foundVal = map[val];
            if (foundVal) result.push(val);
        }

        return result;
    } else {
        let map = array2.reduce((acc, value) => {
            acc[value] = true;
            return acc;
        }, {});

        for (let val of array1) {
            let foundVal = map[val];
            if (foundVal) result.push(val);
        }

        return result;
    }
}
let bleh = intersectionOfTwoArrays([1, 3, 4, 5, 8, 10, 14], [3, 2, 5, 8, 14]);
console.log(bleh);

const findFirstDuplicateString = (array) => {
    let firstDuplicateString = '';
    array.reduce((acc, value) => {
        if(acc[value] == true) {
            firstDuplicateString = value;
            return;
        }
        acc[value] = true;
        return acc;
    }, {})

    return firstDuplicateString;
}

bleh = findFirstDuplicateString(['a', 'b', 'c', 'd', 'c']);
console.log(`First duplicate value found was '${bleh}'`);

const findFirstNonDuplicateLetterInString = function(str) {
    const splitedString = str.split('');
    let firstNonDuplicateLetter = '';
    const map = splitedString.reduce((acc, val) => {
        if(acc[val]) {
            acc[val] = acc[val] + 1;
            return acc;
        }
        acc[val] =+ 1;
        return acc;
    }, {});

    let mapLength = Object.values(map).length;
    let i = 0;
    
    while(i < mapLength) {
        if(Object.values(map).at(i) == 1) {
            firstNonDuplicateLetter = Object.keys(map).at(i);
            break;
        }
        i++
    }

    return firstNonDuplicateLetter;
};

bleh = findFirstNonDuplicateLetterInString('Eduardo')
console.log(`First non duplicate letter found was '${bleh}'`);