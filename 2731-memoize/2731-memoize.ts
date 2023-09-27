type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    const memory: Record<string, number> = {};
    
    return function(...args) {
        const key: string = JSON.stringify(args);
        if (key in memory) {
            // output already memoized, return from cache
            return memory[key];
        } else {
            const result: number = fn(...args);
            memory[key] = result;
            return result;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */