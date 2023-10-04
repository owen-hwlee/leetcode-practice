declare global {
  interface Array<T> {
    snail(rowsCount: number, colsCount: number): number[][];
  }
}

Array.prototype.snail = function(rowsCount: number, colsCount: number): number[][] {
    if (rowsCount * colsCount !== this.length) {
      return [];
    }

    const result: number[][] = (new Array(rowsCount)).fill([]).map(_ => new Array(colsCount).fill(0));

    this.forEach((e, i) => {
      const col: number = Math.floor(i / rowsCount);
      const row: number = (col % 2 === 0) ? i % rowsCount : rowsCount - (i % rowsCount) - 1;
      result[row][col] = e;
    });

    return result;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */