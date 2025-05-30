
function fibonacci(term, memo = {}) {
    if(term in memo) {
        return memo[term];
    }

    if(term <= 1) {
        return term;
    }

    memo[term] = fibonacci(term - 1, memo) + fibonacci(term - 2, memo);
    return memo[term];
}

function fib(n) {
    let current = 0;
    let previous = 0;

    for(let i = 1; i < n + 1; i++) {
        if(i == 1) {
            current = 1;
            continue;
        }
        
        let temporaryCurrent = current;
        current = temporaryCurrent + previous;
        previous = temporaryCurrent;

    }

    return current;
}

// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

console.log(fib(10));