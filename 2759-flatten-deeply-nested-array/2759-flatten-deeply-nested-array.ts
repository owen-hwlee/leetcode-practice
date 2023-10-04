type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    if (n === 0) {
        return arr;
    }

    const result: MultiDimensionalArray = [];

    arr.forEach((e) => {
        if (typeof e === "number") {
            result.push(e);
        } else {
            result.push(...flat(e, n - 1));
        }
    });

    return result;
};