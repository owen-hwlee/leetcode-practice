function merge(intervals: number[][]): number[][] {
    // sort the array by starting position
    intervals.sort((a:number[], b:number[]) => a[0]-b[0]);
    const result: number[][] = [intervals[0]];
    for (let i:number = 0; i < intervals.length - 1; i++) {
        // if overlap
        if (intervals[i+1][0] <= result[result.length-1][1]) {
            // merge
            result[result.length-1][1] = Math.max(result[result.length-1][1], intervals[i+1][1]);
        }
        // if no overlap
        else {
            // append new interval
            result.push(intervals[i+1]);
        }
    }
    return result;
}; 
