// Function to add event listener to table
var firstParagraph = document.getElementById("first_paragraph");
var secondParagraph = document.getElementById("second_paragraph");
firstParagraph.addEventListener("mouseover", function () {
    secondParagraph.setAttribute("style", "background-color: orange");
});
secondParagraph.addEventListener("mouseover", function () {
    firstParagraph.setAttribute("style", "background-color:yellow");
});

var searchButton = document.getElementById("search-btn");
searchButton.addEventListener("click", function () {
    var query = window.prompt("Please type the search query");
    var words = query.split(" ");
    var word = words[0];
    var paragraph = parseInt(words[1]);

    var text;
    if (paragraph == 1) {
        text = firstParagraph.innerHTML;
    } else {
        text = secondParagraph.innerHTML;
    }

    alert(text.split(word).length - 1);
});
