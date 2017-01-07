var persons = [];
var personsContainer = document.getElementById("persons");

var Person = function(firstName, secondName, cnp, birthDay) {
  var obj = new Object();
  obj.firstName = firstName;
  obj.secondName = secondName;
  obj.cnp = cnp;
  obj.birthDay = new Date(birthDay);

  obj.toString = function() {
    return obj.firstName + " " + obj.secondName + " - CNP: " + obj.cnp + " - data nasterii : " + obj.birthDay.toString();
  }

  return obj;
};


var addButton = document.getElementById('add-btn');
addButton.addEventListener("click", function() {
  var firstName = prompt("Nume");
  var secondName = prompt("Prenume");
  var cnp = prompt("CNP");
  var birthDay = prompt("Data nasterii");
  var cnpPattern = /\d{12}/;

  if(!cnp.match(cnpPattern)) {
    alert("CNP nu e valid");
    return;
  }

  persons.push(Person(firstName, secondName, cnp, birthDay));
});

var listButton = document.getElementById('list-btn');
listButton.addEventListener("click", function() {
  alert(persons.length + "Persons" );
  var newInfo = "";
  for (var i = 0; i < persons.length; i++) {
    newInfo += persons[i].toString();
    newInfo += "\n";
  }

  personsContainer.innerHTML = newInfo;
});
