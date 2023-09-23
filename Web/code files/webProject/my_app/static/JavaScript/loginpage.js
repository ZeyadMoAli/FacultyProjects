function checkUser() {
    var mail = document.getElementById("username").value;
    var pas = document.getElementById("pass").value;
    var form = document.getElementById("form");
    if (mail != "not.m7mdd@gmail.com") {

        alert("Error: flid Email!");
        mail.focus();
        return false
    }
    else if (pas != "12341234") {

        alert("Error: flid passowrd!");
        mail.focus();
        return false
    }
    else alert("Welcome");
}
