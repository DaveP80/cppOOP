// // In mathematics, a derivative represents the rate of change of a function 
// at a specific point. It measures how a function's output value changes with 
// respect to its input value. The derivative of a function f(x) at a point x is 
// denoted by f'(x) or dy/dx, where y = f(x).
// // Geometrically, the derivative of a function at a point corresponds to the 
// slope of the tangent line to the graph of the function at that point. It gives 
// us information about how the function is changing locally around that point.
// // Formally, the derivative of a function f(x) at a point x is defined as the 
// limit of the average rate of change of the function as the interval around x shrinks to zero.

// Function to compute the derivative of a given function f at a point x
function computeDerivative(f, x, h = 0.0001) {
    // Use central finite differences for better accuracy
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Example function: f(x) = x^2
function exampleFunction(x) {
    return x * x;
}

// Example usage
const x = 2; // Point at which to compute the derivative
const derivative = computeDerivative(exampleFunction, x);
console.log("Derivative at x =", x, "is", derivative);
