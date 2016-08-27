function getFocus(event) {
    var tar = event.target;
    tar.parentNode.style.border = "2px solid dimgray";
}

function lostFocus(event) {
    var tar = event.target;
    tar.parentNode.style.border = "2px solid darkgray";
}
var tar1 = document.getElementById("InputUsername");
var tar2 = document.getElementById("InputPassword");
tar1.onfocus = getFocus;
tar1.onblur = lostFocus;
tar2.onfocus = getFocus;
tar2.onblur = lostFocus;