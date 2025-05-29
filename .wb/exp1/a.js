console.log("Hello world");

function sum(a, b){
    return a + b;
}

let a = parseInt(prompt("Enter the First Number: "));
let b = parseInt(prompt("Enter the Second Number: "));
alert(`${a} + ${b} = ${sum(a, b)}`);