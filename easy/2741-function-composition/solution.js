/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    // Return a new function that takes the initial value 'x'
    return function(x) {
        let result = x;
        
        // Loop through the array of functions from right to left
        for (let i = functions.length - 1; i >= 0; i--) {
            // Pass the current result into the next function
            result = functions[i](result);
        }
        
        return result;
    }
};