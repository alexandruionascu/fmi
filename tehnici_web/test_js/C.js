var startButton = document.getElementById("start-btn");
startButton.addEventListener('click', function() {
  setTimeout(function() {
    alert("mesaj 1");
    setTimeout(function() {
      alert("mesaj 2");
      setTimeout(function() {
        alert("mesaj 3");
      }, 5000);
    }, 5000);
  }, 10000);
});
