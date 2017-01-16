var button1 = document.getElementById('btn-1');
var button2 = document.getElementById('btn-2');
var title1 = document.getElementById('title-1');
var title2 = document.getElementById('title-2');

button1.addEventListener('click', function() {
  var newDiv = document.createElement("DIV");
  newDiv.innerHTML = " MY TEXT 1";
  title1.insertAdjacentHTML('afterEnd', newDiv.outerHTML)
});


button2.addEventListener('click', function() {
  var newDiv = document.createElement("DIV");
  newDiv.innerHTML = " MY TEXT 2";
  title2.insertAdjacentHTML('afterEnd', newDiv.outerHTML)
});
