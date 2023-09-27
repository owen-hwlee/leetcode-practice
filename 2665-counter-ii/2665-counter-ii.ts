type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let current: number = init;

    const increment: () => number = () => {
        current++;
        return current;
    };

    const decrement: () => number = () => {
        current--;
        return current;
    };

    const reset: () => number = () => {
        current = init;
        return current;
    };

    return {
        increment,
        decrement,
        reset,
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */