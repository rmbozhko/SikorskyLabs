function task1() {
    let n = +prompt("Вкажіть кінцеве значення послідовності.");
    if (n <= 1) {
        alert("Кінцеве значення послідовності має бути більше нуля.");
        return;
    }
    let step = +prompt("Вкажіть крок послідовності.");
    if (step <= 0) {
        alert("Крок послідовності має бути більше нуля.");
        return;
    }
    
    const range = (start, end, step = 1) => {
        let output = [];
        if (typeof end === 'undefined') {
          end = start;
          start = 0;
        }
        for (let i = start; i <= end; i += step) {
          output.push(Math.pow(-1, i + 1) * i);
        }
        return output;
      };
    let arr = range(1, n, step);
    arrContent = "<p>" + arr.toString() + "</p>";
    document.getElementById('first-assignment-first-part-result').innerHTML = arrContent;
    
    let reversed_length = +prompt("Вкажіть кількість перевернутих елементів початкового масиву.");
    if (reversed_length <= 0) {
        alert("Кількість перевернутих елементів початкового масиву не може дорівнювати нулеві чи бути менше нуля.");
        return;
    }
    let reversed_arr = arr.slice(-reversed_length).reverse();
    arrContent = "<p>" + arr.toString() + ",<span style=\"color: red;\">" + reversed_arr.toString() + "</span>";
    document.getElementById('first-assignment-second-part-result').innerHTML = arrContent;
};

let task2 = function() {
    let n = +prompt("Вкажіть розмірність квадратної матриці.");
    if (n < 2) {
        alert("Розмірність квадратної матриці не може бути менше 2.");
        return;
    }
    console.log(typeof n);
    const arr = new Array(n);
    
    function getRandomInt(max) {
        return Math.floor((Math.random() + 1) * max);
    }

    for (let i = 0; i < arr.length; i++) {
        arr[i] = new Array(n).fill(getRandomInt(3));
    }
    console.log(arr);
    let end_index = n - 1;
    for (let i = arr.length - 1; i > 0; i--) {
        arr[i].fill(1, 0, end_index--);
    }
    matrixContent = "<table>";
    for (let i = 0; i < arr.length; i++) {
        matrixContent += "<tr>";
        for (let j = 0; j < arr.length; j++) {
            matrixContent += "<td>" + arr[i][j] + "</td>";
        }
        matrixContent += "</tr>";
    }
    matrixContent += "</table>";
    console.log(matrixContent);
    let elem = document.getElementById('second-assignment-result')
    elem.innerHTML = matrixContent;
};

let task3 = function() {
    data = {};
    data['Призвіще'] = prompt('Призвіще');
    data['Ім\'я'] = prompt('Ім\'я');
    data['По-батькові'] = prompt('По-батькові');
    data['Група'] = prompt('Група');
    if (data['Група'].search(/[а-я]{2}-\d{2}/ig) < 0) {
        alert("Ім\'я групи має містити дві кириличні літери і дві арабські цифри.");
        return;
    }
    data['isInGroupTM-91'] = (data['group'] === "TM-91");

    dataContent = "<ul>";
    for (key in data) {
        dataContent += "<li>" + key + ": " + data[key] + "</li>";
    }
    dataContent += "</ul>";
    console.log(dataContent);
    document.getElementById('third-assignment-result').innerHTML = dataContent;
};