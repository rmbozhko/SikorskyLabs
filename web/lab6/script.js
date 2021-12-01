let createUser = function() {
    surname = prompt('Призвіще');
    u_name = prompt('Ім\'я');
    return {
        "Призвіще": surname,
        "Ім\'я": u_name
    };
}

function task1() {
    let user = createUser();
    arrContent =    "<ul>" + 
                        "<li>" + "Користувач" + 
                            "<ol>" + 
                                "<li>" + user["Призвіще"] + "</li>" +
                                "<li>" + user["Ім\'я"] + "</li>" + 
                            "</ol>" +
                        "</li>" + 
                    "</ul>";

    document.getElementById('first-assignment-result').innerHTML = arrContent;
};

let createStudent = function() {
    specialization = prompt("Спеціальність");
    group = prompt("Група");
    return {
        "Спеціальність": specialization,
        "Група": group,
        add(property) { this[property] = property; },
        update(property, new_value) { this[property] = new_value; },
        delete(property) { delete this[property]; }
    };
}

let task2 = function() {
    let student = createStudent();
    
    arrContent = "<ul>";
    temp = "";
    for (property in student) {
        temp += "<li>"+ property + ":" + student[property] +"</li>";
    }
    arrContent += temp + "</ul>";
    document.getElementById('second-assignment-result').innerHTML = arrContent;
};

let task3 = function() {
    let user = createUser();
    let student = createStudent();
    let clone = Object.assign({}, user, student);

    dataContent = "<ul>";
    for (property in clone) {
        dataContent += "<li>" + property + ": " + clone[property] + "</li>";
    }
    dataContent += "</ul>";
    document.getElementById('third-assignment-result').innerHTML = dataContent;
};

let task4 = function() {
    let student = createStudent();
    Object.getPrototypeOf(student).showDate = function() { console.log(this); }

    dataContent = "<ul>";
    for (property in student) {
        dataContent += "<li>" + property + ": " + student[property] + "</li>";
    }
    dataContent += "</ul>";
    document.getElementById('fourth-assignment-result').innerHTML = dataContent;
};

let task5 = function() {
    class Student {
        constructor(specialization, group) {
            this.specialization = specialization;
            this.group = group;
        }
        add(property) { this[property] = property; }
        update(property, new_value) { this[property] = new_value; }
        delete(property) { delete this[property]; }
    }

    class Progress extends Student {
        constructor(specialization, group, subjects, marks) {
            super(specialization, group);
            this.subjects = subjects;
            this.marks = marks;
        }

        calculateAverageMark() { return (this.marks.reduce((a, b) => a + b, 0)) / this.marks.length; }
        showData() { console.log("Overridden method"); }
        
        get specialization() { console.log(this.specialization); return this.specialization; }
        set specialization(specialization) {
            if (specialization.length === 3) {
                this.specialization = specialization;
            }
        }

        get group() { console.log(`My group: ${this.group}`); return this.group; }
        set group(group) {
            if (group.search(/[а-я]{2}-\d{2}/ig) < 0) {
                alert("Ім\'я групи має містити дві кириличні літери і дві арабські цифри.");
                return;
            }
            this.group = group;
        }

        get subjects() { return this.subjects; }
        set subjects(subjects) { 
            if (subjects.length > 0) {
                this.subjects = subjects;
            }
        }

        get marks() { return this.marks; }
        set marks(marks) { 
            if (marks.length > 0) {
                this.marks = marks;
            }
        }
    }

    let progress = new Progress();
    Object.getPrototypeOf(student).showDate = function() { console.log(this); }

    dataContent = "<ul>";
    for (property in progress) {
        dataContent += "<li>" + property + ": " + student[property] + "</li>";
    }
    dataContent += "</ul>";
    document.getElementById('fourth-assignment-result').innerHTML = dataContent;
};