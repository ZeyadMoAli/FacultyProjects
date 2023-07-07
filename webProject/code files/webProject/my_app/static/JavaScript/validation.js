
function validat() {
    var name = document.getElementById("usernams").value;
    var mobNum = document.getElementById("mobile").value;
    var reg = /[0-9]/;
    if (name == "") {
        alert("Error: Name can't be blank!");
        document.getElementById("usernams").focus();
        return false
    }
    if (reg.test(name)) {
        alert("Error: Name can't be with number!");
        name.focus();
        return false;
    }
    if (mobile.value.length > 12 || mobile.value.length < 10) {
        alert("Error: Wrong Mobile Number!");
        name.focus();
        return false;
    }
    var n = document.getElementById("id").value;
    var regr = /[a-zA-Z]/;
    if (n == "") {
        alert("ID can't be blank!");
        n.focus();
        return false;
    }
    if (regr.test(n)) {
        alert("Error: ID can't have charcter!!");
        n.focus();
        return false;
    }
    else {
        alert("Done successfully");
    }


}
function searchCheak() {
    var search = document.getElementById("search").value;
    if (search == "")
        alert("Enter Name or ID");
    return false;
}
var form = document.getElementById("form");
function handleForm(event) { event.preventDefault(); }
form.addEventListener('submit', handleForm);

