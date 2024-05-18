//LeetCode No. 735 Asteroid Collision
var asteroidCollision = function(asteroids) {
    const stack = [];

    for (const ast of asteroids) {
        let collided = false;

        while (stack.length && ast < 0 && stack[stack.length - 1] > 0) {
            const abAst = Math.abs(ast);
            if (stack[stack.length - 1] < abAst) {
                stack.pop();
            } else if (stack[stack.length - 1] === abAst) {
                stack.pop();
                collided = true;
                break;
            } else {
                collided = true;
                break; 
            }
        }

        if (!collided) {
            stack.push(ast);
        }
    }

    return stack;
};