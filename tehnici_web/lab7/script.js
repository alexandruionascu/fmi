var contentContainer = document.getElementById("content");
var generateButton = document.getElementById("generate");

generateButton.addEventListener("click", function () {
    var oldText = contentContainer.innerHTML;
    var mainTitles = contentContainer.querySelectorAll("h1, h2");

    var content = document.createElement("ul");

    var header = document.createElement("h3");
    header.innerHTML = "Cuprins";
    content.appendChild(header);
    for (var i = 0, title; title = mainTitles[i]; i++) {
        var main = title.textContent;
        console.log(main);
        console.log(title);

        if (title.nodeName == "H1") {
            if (mainTitles[i + 1].nodeName == "H2") {
                var newEntry = document.createElement("li");
                newEntry.innerHTML = title.textContent + " - " + mainTitles[i + 1].textContent;
                content.appendChild(newEntry);
            }
        }
    }
    if (confirm("Generez cuprins la inceput sau la final?")) {
        contentContainer.appendChild(content);
    } else {
        contentContainer.insertBefore(content, contentContainer.firstChild);
    }
});

var highlightButton = document.getElementById("highlight");
highlightButton.addEventListener("click", function () {
    var spans = document.getElementsByTagName("span");
    for (var i = 0, span; span = spans[i]; i++) {
        span.setAttribute("class", "highlight");
    }
});

var alertButton = document.getElementById("alert-btn");
alertButton.addEventListener("click", function () {
    myAlert("My custom alert");
});

function myAlert(message) {
    var modal = document.getElementById("modal");
    var modalMessage = document.getElementById("modal-message");
    var closeButton = document.getElementById("modal-close");
    modalMessage.innerHTML = message;
    modal.style.display = "block";

    closeButton.addEventListener("click", function () {
        modal.style.display = "none";
    });
}
