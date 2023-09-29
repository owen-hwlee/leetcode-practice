declare global {
    interface Array<T> {
        groupBy(fn: (item: T) => string): Record<string, T[]>
    }
}

Array.prototype.groupBy = function(fn) {
    const group = {};
    for (let i = 0; i < this.length; ++i) {
        const e = this[i];
        const key: string = fn(e);
        if (key in group) {
            group[key].push(e);
        } else {
            group[key] = [e];
        }
    }
    return group;
}

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */