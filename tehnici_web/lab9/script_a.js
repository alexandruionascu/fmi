var KEYCODE_LEFT = 37;
var KEYCODE_RIGHT = 39;
var KEYCODE_UP = 38;
var KEYCODE_DOWN = 40;

var danutzu = document.getElementById("danutzu");
document.addEventListener('keypress', function(e) {
  console.log(danutzu);
  var keyCode = (e.keyCode || e.which);
  console.log(keyCode);
  if (keyCode == KEYCODE_LEFT) {
    console.log("BLAT");
    danutzu.style.left = parseInt(danutzu.style.left) + 10 + 'px';
  }

  if (keyCode == KEYCODE_RIGHT) {
  }

  if (keyCode == KEYCODE_UP) {
  }

  if (keyCode == KEYCODE_DOWN) {
  }
});
