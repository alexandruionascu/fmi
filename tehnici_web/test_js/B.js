update();

var contactForm = document.getElementById("contactform");
contactForm.addEventListener("submit", function (e) {
    e.preventDefault();


    var name = document.getElementById("name-form").value;
    var email = document.getElementById("email-form").value;

    localStorage.setItem('name', name);
    localStorage.setItem('email', email);

    update();
});

function update() {
  var localName = document.getElementById("local-name");
  localName.value = localStorage.getItem('name');
  var localEmail = document.getElementById("local-email");
  localEmail.value = localStorage.getItem('email');
}
