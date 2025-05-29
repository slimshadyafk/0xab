let image = document.getElementById("image");
let button = document.getElementById("button");
let heading = document.getElementById("heading");

image.addEventListener("mouseover", (ev)=>{
    image.style.borderColor = "blue";
})
image.addEventListener("mouseout", (ev)=>{
    image.style.borderColor = "black";
})

button.addEventListener("click", (ev)=>{
    console.log("you clicked the button.");
})

document.addEventListener("keypress", (ev)=>{
    heading.innerText = `you clicked '${ev.key}' !`
    setTimeout(()=>{
        heading.innerText = "Press any Key"
    }, 1000);
});