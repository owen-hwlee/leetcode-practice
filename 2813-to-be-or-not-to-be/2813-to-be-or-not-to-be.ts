type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
	function toBe(expected: any): boolean {
        if (val !== expected) {
            throw new Error("Not Equal");
        }
        return val === expected;
    }

    function notToBe(expected: any): boolean {
        if (val === expected) {
            throw new Error("Equal");
        }
        return val !== expected;
    }

    return {
        toBe,
        notToBe,
    };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */