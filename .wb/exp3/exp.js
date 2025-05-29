const student = {
  name: prompt("Enter the student's name:"),
  grade: parseFloat(prompt("Enter the student's grade:")),
  subjects: prompt("Enter the student's subjects separated by commas:").split(
    ","
  ),
    displayInfo: function(){
        for(let k in this){
            if(typeof this[k] != 'function'){
                console.log(`${k}: ${this[k]}`)
            }
        }
    }
};

student.passed = student.grade >= 6.5;
student.displayInfo();
