type P = Promise<number>

async function addTwoPromises(promise1: P, promise2: P): P {
	const num1 = await promise1;
    const num2 = await promise2;
    return new Promise(resolve => resolve(num1 + num2));
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */