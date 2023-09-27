type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
	const results: number[] = [];
    for (let i: number = 0; i < arr.length; ++i) {
        if (fn(arr[i], i)) {
            results.push(arr[i]);
        }
    }
    return results;
};