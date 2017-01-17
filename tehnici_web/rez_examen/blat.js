var firstList = document.getElementById('lista1');
var secondList = document.getElementById('lista2');

function addSwitchEvent(node) {
  node.addEventListener('click', function() {
      var clone = this.cloneNode(true);

      if(this.parentNode === firstList)
        secondList.appendChild(clone);
      else
        firstList.appendChild(clone);
      this.parentNode.removeChild(this);
      addSwitchEvent(clone);
  });
}


for (var i = 0, item; item = firstList.childNodes[i]; ++i) {
  addSwitchEvent(item);
}

for (var i = 0, item; item = secondList.childNodes[i]; ++i) {
  addSwitchEvent(item);
}
